// SPDX-License-Identifier: GPL-2.0
/*
 * Motorcomm YT9215 Dual-Conduit Untagged Switch Initializer for Xiaomi AX3000 v2 (RA80 v2)
 *
 * Configures the YT9215 switch on MDIO bus (address 0x1d) in Option B (Untagged
 * Dual-Conduit Raw Ethernet) mode so Qualcomm NSS (qca-nss-dp / qca-nss-drv /
 * qca-nss-ecm) can offload 100% of wired WAN <-> LAN and Wi-Fi traffic without
 * proprietary 0x9988 DSA tags:
 *
 *   - Rear WAN (Port 3)       <---> Internal PHY Port 4 (dp1 / eth1)
 *   - Rear LAN 1..3 (Port 0..2)<---> SGMII Port 8 (dp2 / eth0, Rev-SGMII 1000M)
 */

#include <linux/delay.h>
#include <linux/gpio/consumer.h>
#include <linux/kernel.h>
#include <linux/mdio.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/phy.h>

#define YT9215_SWITCH_ID		0x0
#define YT9215_REG_ADDR_HI_LO		((YT9215_SWITCH_ID << 2) | 0x0)
#define YT9215_REG_DATA_WRITE		((YT9215_SWITCH_ID << 2) | 0x2)
#define YT9215_REG_ADDR_READ		((YT9215_SWITCH_ID << 2) | 0x1)
#define YT9215_REG_DATA_READ		((YT9215_SWITCH_ID << 2) | 0x3)

/* YT9215 Global & Switch Registers */
#define YT921X_GLOBAL_RESET		0x80000
#define YT921X_GLOBAL_CTRL1		0x80004
#define YT921X_CHIP_ID_REG		0x80008
#define YT921X_EXT_CPU_PORT_REG		0x8000c
#define YT921X_CPU_TAG_TPID_REG		0x80010
#define YT921X_INTERFACE_CTRL		0x80028
#define YT921X_SGMII_MODE(p)		(0x8006c + (p) * 4)
#define YT921X_MAC_EN(p)		(0x80078 + (p) * 8)
#define YT921X_PORT_CTRL(p)		(0x80100 + (p) * 4)
#define YT921X_LOOP_DETECT		0x80230
#define YT921X_SGMII_LINK(p)		(0x802d4 + (p) * 4)
#define YT921X_XMII_CTRL(p)		(0x8036c + (p) * 4)
#define YT921X_SERDES_CTRL		0x80394

/* Internal PHY MBUS indirect controller */
#define YT921X_INT_MBUS_OP		0xf0000
#define YT921X_INT_MBUS_ADDR		0xf0004
#define YT921X_INT_MBUS_DOUT		0xf0008
#define YT921X_INT_MBUS_DIN		0xf000c

/* L2, STP, VLAN & Port Isolation Registers */
#define YT921X_PORT_LEARN_CTRL(p)	(0x180200 + (p) * 4)
#define YT921X_CTRLPKT_EEE_ACT		0x18028c
#define YT921X_CTRLPKT_LLDP_ACT		0x180290
#define YT921X_PORT_ISOLATION(p)	(0x180294 + (p) * 4)
#define YT921X_STP_STATE_REG		0x18038c
#define YT921X_PORT_LEARN_DIS(p)	(0x1803d0 + (p) * 4)
#define YT921X_PORT_EGR_MASK1		0x180468
#define YT921X_PORT_EGR_MASK2		0x18046c
#define YT921X_FLOOD_CTRL_BASE		0x180480
#define YT921X_FLOOD_CTRL_END		0x1804ac
#define YT921X_L2_ENABLE_REG		0x180690
#define YT921X_VLAN1_LOW		0x188008
#define YT921X_VLAN1_HIGH		0x18800c
#define YT921X_VLAN2_LOW		0x188010
#define YT921X_VLAN2_HIGH		0x188014
#define YT921X_PORT_VLAN_CTRL(p)	(0x230010 + (p) * 4)

static int yt9215_smi_read(struct mdio_device *mdiodev, u32 reg, u32 *val)
{
	struct mii_bus *bus = mdiodev->bus;
	int addr = mdiodev->addr;
	int ret, hi, lo;

	mutex_lock_nested(&bus->mdio_lock, MDIO_MUTEX_NESTED);

	ret = __mdiobus_write(bus, addr, YT9215_REG_ADDR_READ, (u16)(reg >> 16));
	if (ret < 0)
		goto out;
	ret = __mdiobus_write(bus, addr, YT9215_REG_ADDR_READ, (u16)(reg & 0xffff));
	if (ret < 0)
		goto out;

	hi = __mdiobus_read(bus, addr, YT9215_REG_DATA_READ);
	if (hi < 0) {
		ret = hi;
		goto out;
	}
	lo = __mdiobus_read(bus, addr, YT9215_REG_DATA_READ);
	if (lo < 0) {
		ret = lo;
		goto out;
	}

	*val = ((u32)(hi & 0xffff) << 16) | (u32)(lo & 0xffff);
	ret = 0;

out:
	mutex_unlock(&bus->mdio_lock);
	return ret;
}

static int yt9215_smi_write(struct mdio_device *mdiodev, u32 reg, u32 val)
{
	struct mii_bus *bus = mdiodev->bus;
	int addr = mdiodev->addr;
	int ret;

	mutex_lock_nested(&bus->mdio_lock, MDIO_MUTEX_NESTED);

	ret = __mdiobus_write(bus, addr, YT9215_REG_ADDR_HI_LO, (u16)(reg >> 16));
	if (ret < 0)
		goto out;
	ret = __mdiobus_write(bus, addr, YT9215_REG_ADDR_HI_LO, (u16)(reg & 0xffff));
	if (ret < 0)
		goto out;

	ret = __mdiobus_write(bus, addr, YT9215_REG_DATA_WRITE, (u16)(val >> 16));
	if (ret < 0)
		goto out;
	ret = __mdiobus_write(bus, addr, YT9215_REG_DATA_WRITE, (u16)(val & 0xffff));

out:
	mutex_unlock(&bus->mdio_lock);
	return ret;
}

static int yt9215_smi_update_bits(struct mdio_device *mdiodev, u32 reg,
				  u32 mask, u32 set)
{
	u32 val = 0;
	int ret;

	ret = yt9215_smi_read(mdiodev, reg, &val);
	if (ret)
		return ret;

	val = (val & ~mask) | (set & mask);
	return yt9215_smi_write(mdiodev, reg, val);
}

static int yt9215_smi_wait(struct mdio_device *mdiodev, u32 reg, u32 mask, u32 expect)
{
	u32 val = 0;
	int i;

	for (i = 0; i < 100; i++) {
		if (yt9215_smi_read(mdiodev, reg, &val) == 0 &&
		    (val & mask) == expect)
			return 0;
		usleep_range(1000, 2000);
	}
	return -ETIMEDOUT;
}

static int yt9215_int_phy_write(struct mdio_device *mdiodev, int phy, int reg, u16 val)
{
	u32 ctrl;

	yt9215_smi_wait(mdiodev, YT921X_INT_MBUS_OP, 1, 0);
	ctrl = ((phy & 0x1f) << 21) | ((reg & 0x1f) << 16) | 0x4;
	yt9215_smi_update_bits(mdiodev, YT921X_INT_MBUS_ADDR, 0x03fff00c, ctrl);
	yt9215_smi_write(mdiodev, YT921X_INT_MBUS_DOUT, val);
	yt9215_smi_write(mdiodev, YT921X_INT_MBUS_OP, 1);
	yt9215_smi_wait(mdiodev, YT921X_INT_MBUS_OP, 1, 0);
	return 0;
}

static int yt9215_ra80v2_probe(struct mdio_device *mdiodev)
{
	u32 chip_id = 0, r;
	int p, q, ret;

	/* GPIO 39 hardware reset is pulsed by the parent mdio@90000 bus
	 * before child MDIO devices are registered and probed.
	 */
	msleep(50);

	ret = yt9215_smi_read(mdiodev, YT921X_CHIP_ID_REG, &chip_id);
	if (ret || (chip_id >> 16) != 0x9002) {
		dev_err(&mdiodev->dev, "YT9215 not ready (chip_id=0x%08x, ret=%d)\n",
			chip_id, ret);
		return -ENODEV;
	}

	/* 1. Exact yt921x_chip_reset sequence from working 102 driver */
	yt9215_smi_wait(mdiodev, 0xe0004, 0xf, 0x3);
	yt9215_smi_write(mdiodev, 0xe0000, 0xfb05);
	yt9215_smi_wait(mdiodev, 0xe0004, 0xf, 0x3);
	yt9215_smi_write(mdiodev, YT921X_GLOBAL_RESET, 0x80000000U);
	usleep_range(10000, 20000);
	yt9215_smi_wait(mdiodev, YT921X_GLOBAL_RESET, 0xffffffffU, 0x0);

	/* 2. Exact yt921x_chip_setup sequence */
	yt9215_smi_update_bits(mdiodev, YT921X_GLOBAL_CTRL1, 0x16, 0x16);

	/* Disable proprietary 0x9988 CPU tag (0x8000c = 0x0) so all frames on
	 * Port 4 (dp1/eth1) and Port 8 (dp2/eth0) are standard untagged Ethernet.
	 */
	yt9215_smi_write(mdiodev, YT921X_EXT_CPU_PORT_REG, 0x0);

	/* Enable L2 engine and disable hardware loop-detect */
	yt9215_smi_write(mdiodev, YT921X_L2_ENABLE_REG, 0x1);
	yt9215_smi_read(mdiodev, YT921X_LOOP_DETECT, &r);
	r = (r & ~0x0003fffdU) | 0x40000U;
	yt9215_smi_write(mdiodev, YT921X_LOOP_DETECT, r);

	/* RMA slow-action = 2 (forward standard slow protocols, STP/LACP) */
	yt9215_smi_update_bits(mdiodev, 0x1805d0, 0x3f0, 0x1bf);
	yt9215_smi_update_bits(mdiodev, 0x1805d8, 0x3f0, 0x2bf);
	yt9215_smi_update_bits(mdiodev, 0x1805dc, 0x3f0, 0x1bf);
	yt9215_smi_update_bits(mdiodev, 0x180608, 0x3f0, 0x1bf);

	/* Forward LLDP and EEE control packets (0x400) */
	yt9215_smi_write(mdiodev, YT921X_CTRLPKT_EEE_ACT, 0x400);
	yt9215_smi_write(mdiodev, YT921X_CTRLPKT_LLDP_ACT, 0x400);

	/* Egress masks and flood control across active ports (0..4, 8 -> 0x11f) */
	yt9215_smi_update_bits(mdiodev, YT921X_PORT_EGR_MASK1, 0x7ff, 0x11f);
	yt9215_smi_update_bits(mdiodev, YT921X_PORT_EGR_MASK2, 0x7ff0, 0x11f << 4);
	for (r = YT921X_FLOOD_CTRL_BASE; r < YT921X_FLOOD_CTRL_END; r += 4)
		yt9215_smi_update_bits(mdiodev, r, 0xff, 0xff);

	yt9215_smi_update_bits(mdiodev, 0x180280, 0x3ff800, 0x3ff800);
	yt9215_smi_write(mdiodev, 0x180508, 0x7ff);
	yt9215_smi_write(mdiodev, 0x18050c, 0x7ff);
	yt9215_smi_write(mdiodev, 0x180510, 0x7ff);
	yt9215_smi_write(mdiodev, 0x180514, 0x7ff);
	yt9215_smi_write(mdiodev, 0x180734, 0x0);
	yt9215_smi_write(mdiodev, 0x180738, 0x400000);
	yt9215_smi_write(mdiodev, 0x180448, 0x7ff);
	yt9215_smi_write(mdiodev, 0x300300, 0x0);
	yt9215_smi_write(mdiodev, 0x300304, 0x0);

	/* Default VLAN 1 membership: all 11 ports (0x7ff) untagged */
	yt9215_smi_write(mdiodev, YT921X_VLAN1_LOW, (1U << 23) | (0x107U << 7));
	yt9215_smi_write(mdiodev, YT921X_VLAN1_HIGH, 0x107U << 8);
	yt9215_smi_write(mdiodev, YT921X_VLAN2_LOW, (2U << 23) | (0x018U << 7));
	yt9215_smi_write(mdiodev, YT921X_VLAN2_HIGH, 0x018U << 8);

	/* Buffer / QoS / scheduler initialization from yt921x_chip_setup */
	yt9215_smi_write(mdiodev, 0x220104, 0x50);
	yt9215_smi_write(mdiodev, 0x220100, 0x50);
	yt9215_smi_write(mdiodev, 0x34000c, 0x50);
	yt9215_smi_write(mdiodev, 0x340008, 0x84);
	yt9215_smi_update_bits(mdiodev, 0x220140, 0x7ff, 0x0);
	for (r = 0x220200; r < 0x220284; r += 4)
		yt9215_smi_update_bits(mdiodev, r, 0x1, 0x0);
	yt9215_smi_write(mdiodev, 0x220bf0, 0x0);
	yt9215_smi_write(mdiodev, 0x220bf4, 0x0);
	yt9215_smi_write(mdiodev, 0x220bf8, 0x4000);
	yt9215_smi_write(mdiodev, 0x1806a0, 0x7ff);
	yt9215_smi_write(mdiodev, 0x202000, 0x7ff);
	for (p = 0; p < 64; p++)
		yt9215_smi_write(mdiodev, 0x180000 + p * 4, (p >> 3) << 2);
	for (p = 0; p < 8; p++) {
		u32 base = 0x180100 + p * 4;
		u32 val = base - 0x180100;

		yt9215_smi_write(mdiodev, base, val);
		yt9215_smi_write(mdiodev, base + 0x40, val);
		yt9215_smi_write(mdiodev, base + 0x20, val | 1);
		yt9215_smi_write(mdiodev, base + 0x60, val | 1);
	}
	for (p = 0; p < 16; p += 2) {
		for (q = 0; q < 4; q++) {
			u32 idx = ((p & 0x7f) << 1) | q;

			yt9215_smi_update_bits(mdiodev, (0x40040 + idx) * 4, 0x3f, p << 2);
			yt9215_smi_update_bits(mdiodev, (0x40040 + idx) * 4 + 0x100, 0xf, p | 1);
			yt9215_smi_update_bits(mdiodev, (0x40080 + (idx | 0x20)) * 4, 0xf, p | 1);
		}
	}

	/* Egress packet buffer & AC queue quota setup (yt921x_chip_setup 0x10390..0x10474) */
	yt9215_smi_write(mdiodev, 0x2801d0, 0xc8);
	for (p = 0; p < 11; p++) {
		if (p > 4 && p != 8 && p != 9)
			continue;
		if (p != 4) {
			yt9215_smi_write(mdiodev, 0x281000 + p * 8, 0x80402850U);
			yt9215_smi_write(mdiodev, 0x281004 + p * 8, 0x26f1bU);
		}
		for (q = 0; q < 8; q++)
			yt9215_smi_write(mdiodev, 0x301000 + (p * 8 + q) * 4, 0x40020U);
		for (q = 0; q < 4; q++)
			yt9215_smi_write(mdiodev, 0x301200 + (p * 4 + q) * 4, 0x40020U);
	}
	yt9215_smi_write(mdiodev, 0x281020, 0x1);
	yt9215_smi_write(mdiodev, 0x281024, 0x26765U);
	for (p = 0; p <= 3; p++)
		yt9215_smi_write(mdiodev, 0x303000 + p * 4, 0x78);
	yt9215_smi_write(mdiodev, 0x303020, 0x78);

	for (p = 0; p <= 4; p++)
		yt9215_smi_update_bits(mdiodev, 0x100000 + p * 4, 0x1c3, 0x1c1);
	yt9215_smi_update_bits(mdiodev, 0x100000 + 8 * 4, 0x1c3, 0x1c1);
	yt9215_smi_write(mdiodev, 0xc0004, 0x40000001U);
	yt9215_smi_update_bits(mdiodev, 0x8036c, 0x40000, 0x40000);
	yt9215_smi_update_bits(mdiodev, 0x180958, 0x1, 0x1);

	/* 3. Per-port setup (yt921x_dsa_port_setup + STP FORWARDING):
	 *    - 0x180200 + p*4 = 0x3b5ed1
	 *    - 0x1803d0 + p*4 &= ~0x20000 (enable hardware MAC learning!)
	 *    - 0x230010 + p*4 = 0x00000040 (default PVID = 1)
	 *    - 0x18038c: set STP state = 3 (FORWARDING) for all active ports 0..4, 8
	 */
	for (p = 0; p < 11; p++) {
		if (p > 4 && p != 8)
			continue;
		yt9215_smi_write(mdiodev, YT921X_PORT_LEARN_CTRL(p), 0x3b5ed1);
		yt9215_smi_update_bits(mdiodev, YT921X_PORT_LEARN_DIS(p), 0x70007, 0x0);
		yt9215_smi_update_bits(mdiodev, YT921X_PORT_VLAN_CTRL(p), 0x3ffc0,
				       ((p == 3 || p == 4) ? 2 : 1) << 6);
		yt9215_smi_update_bits(mdiodev, YT921X_STP_STATE_REG,
				       0x3 << (p * 2), 0x3 << (p * 2));
	}

	/* 4. Option B Hardware Port Isolation Matrix (0x180294 + port * 4):
	 *    In yt921x_userport_standalone (0xc504) and yt921x_userport_cpu_isolation_set
	 *    (0xc04c), bit=1 ISOLATES (blocks) a destination port and bit=0 ALLOWS
	 *    forwarding:
	 *    - LAN group {0, 1, 2, 8}: clear bits {0, 1, 2, 8}, set all other bits to 1
	 *    - WAN group {3, 4}:       clear bits {3, 4},       set all other bits to 1
	 */
	yt9215_smi_update_bits(mdiodev, YT921X_PORT_ISOLATION(0), 0x7ff, 0x7ff & ~0x106);
	yt9215_smi_update_bits(mdiodev, YT921X_PORT_ISOLATION(1), 0x7ff, 0x7ff & ~0x105);
	yt9215_smi_update_bits(mdiodev, YT921X_PORT_ISOLATION(2), 0x7ff, 0x7ff & ~0x103);
	yt9215_smi_update_bits(mdiodev, YT921X_PORT_ISOLATION(8), 0x7ff, 0x7ff & ~0x007);

	yt9215_smi_update_bits(mdiodev, YT921X_PORT_ISOLATION(3), 0x7ff, 0x7ff & ~0x010);
	yt9215_smi_update_bits(mdiodev, YT921X_PORT_ISOLATION(4), 0x7ff, 0x7ff & ~0x008);

	/* 5. Configure Port 8 (SGMII primary conduit -> dp2 / eth0):
	 *    - Enable interface (0x80028 |= BIT(0)) and ungate SerDes (0x80394 &= ~BIT(1))
	 *    - Rev-SGMII mode (0x8006c + 8*4: mask 0x380, val 0x80)
	 *    - Force 1000M full-duplex with RX/TX MAC + pause (0x80100 + 8*4 = 0x2fa,
	 *      0x802d4 + 8*4 = 0x7a, 0x80078 + 8*8 |= 0x80000, 0x8036c + 8*4 = 0x1a)
	 */
	yt9215_smi_update_bits(mdiodev, YT921X_INTERFACE_CTRL, BIT(0), BIT(0));
	yt9215_smi_update_bits(mdiodev, YT921X_SERDES_CTRL, BIT(1), 0);
	yt9215_smi_update_bits(mdiodev, YT921X_SGMII_MODE(8), 0x380, 0x80);
	yt9215_smi_update_bits(mdiodev, YT921X_PORT_CTRL(8), 0x2ff, 0x2fa);
	yt9215_smi_update_bits(mdiodev, YT921X_SGMII_LINK(8), 0x7f, 0x7a);
	yt9215_smi_update_bits(mdiodev, YT921X_MAC_EN(8), 0x80000, 0x80000);
	yt9215_smi_write(mdiodev, YT921X_XMII_CTRL(8), 0x1a);

	/* 6. Configure Port 4 (Internal GE PHY secondary conduit -> dp1 / eth1)
	 *    and user ports 0..3 (Rear LAN 1..3 and Rear WAN):
	 *    - Port 4 fixed 1000M full-duplex MAC (0x2fa)
	 *    - Ports 0..3 enable MAC auto-negotiation / RX+TX MAC (0x2ff -> 0x2fa)
	 *    - Power up and restart auto-negotiation on internal PHYs 0..4 (BMCR = 0x1340)
	 */
	yt9215_smi_update_bits(mdiodev, YT921X_PORT_CTRL(4), 0x2ff, 0x2fa);
	for (p = 0; p <= 3; p++)
		yt9215_smi_update_bits(mdiodev, YT921X_PORT_CTRL(p), 0x2ff, 0x2fa);

	for (p = 0; p <= 4; p++)
		yt9215_int_phy_write(mdiodev, p, MII_BMCR,
				     BMCR_ANENABLE | BMCR_ANRESTART | BMCR_FULLDPLX | BMCR_SPEED1000);

	dev_info(&mdiodev->dev,
		 "YT9215 Option B initialized (chip_id=0x%08x): WAN(P3<->P4/eth1) LAN(P0..2<->P8/eth0) untagged\n",
		 chip_id);
	return 0;
}

static const struct of_device_id yt9215_ra80v2_of_match[] = {
	{ .compatible = "motorcomm,yt9215-ra80v2" },
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, yt9215_ra80v2_of_match);

static struct mdio_driver yt9215_ra80v2_driver = {
	.mdiodrv.driver = {
		.name = "yt9215-ra80v2",
		.of_match_table = yt9215_ra80v2_of_match,
	},
	.probe = yt9215_ra80v2_probe,
};

mdio_module_driver(yt9215_ra80v2_driver);

MODULE_DESCRIPTION("Motorcomm YT9215 Option B Dual-Conduit Switch Initializer for Xiaomi AX3000 v2");
MODULE_LICENSE("GPL");