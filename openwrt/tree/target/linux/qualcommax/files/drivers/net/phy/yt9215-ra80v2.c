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
#define YT921X_GLOBAL_CTRL1		0x80004
#define YT921X_CHIP_ID_REG		0x80008
#define YT921X_EXT_CPU_PORT_REG		0x8000c
#define YT921X_INTERFACE_CTRL		0x80028
#define YT921X_SERDES_CTRL		0x80394
#define YT921X_PORT_CTRL(p)		(0x80100 + (p) * 4)
#define YT921X_SGMII_MODE(p)		(0x8006c + (p) * 4)
#define YT921X_SGMII_LINK(p)		(0x802d4 + (p) * 4)
#define YT921X_XMII_CTRL(p)		(0x8036c + (p) * 4)
#define YT921X_MAC_EN(p)		(0x80078 + (p) * 8)

/* Internal PHY MBUS indirect controller */
#define YT921X_INT_MBUS_OP		0xf0000
#define YT921X_INT_MBUS_ADDR		0xf0004
#define YT921X_INT_MBUS_DOUT		0xf0008

/* L2 & Port Isolation Registers */
#define YT921X_PORT_LEARN_CTRL(p)	(0x180200 + (p) * 4)
#define YT921X_PORT_ISOLATION(p)	(0x180294 + (p) * 4)
#define YT921X_PORT_EGR_MASK1		0x180468
#define YT921X_PORT_EGR_MASK2		0x18046c
#define YT921X_FLOOD_CTRL_BASE		0x180480
#define YT921X_FLOOD_CTRL_END		0x1804ac
#define YT921X_L2_ENABLE_REG		0x180690

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

static int yt9215_int_phy_write(struct mdio_device *mdiodev, int phy, int reg, u16 val)
{
	u32 ctrl, status = 1;
	int i;

	for (i = 0; i < 50; i++) {
		if (yt9215_smi_read(mdiodev, YT921X_INT_MBUS_OP, &status) == 0 &&
		    !(status & 1))
			break;
		udelay(100);
	}

	ctrl = ((phy & 0x1f) << 21) | ((reg & 0x1f) << 16) | 0x4;
	yt9215_smi_update_bits(mdiodev, YT921X_INT_MBUS_ADDR, 0x03fff00c, ctrl);
	yt9215_smi_write(mdiodev, YT921X_INT_MBUS_DOUT, val);
	yt9215_smi_write(mdiodev, YT921X_INT_MBUS_OP, 1);

	for (i = 0; i < 50; i++) {
		if (yt9215_smi_read(mdiodev, YT921X_INT_MBUS_OP, &status) == 0 &&
		    !(status & 1))
			break;
		udelay(100);
	}
	return 0;
}

static int yt9215_ra80v2_probe(struct mdio_device *mdiodev)
{
	u32 chip_id = 0, r;
	int p, ret;

	/* Allow switch post-reset stabilization */
	msleep(50);

	ret = yt9215_smi_read(mdiodev, YT921X_CHIP_ID_REG, &chip_id);
	if (ret || (chip_id >> 16) != 0x9002) {
		dev_err(&mdiodev->dev, "YT9215 not ready (chip_id=0x%08x, ret=%d)\n",
			chip_id, ret);
		return -ENODEV;
	}

	/* 1. Enable switch global MAC/ACL/MIB engines (0x80004 |= 0x16) */
	yt9215_smi_update_bits(mdiodev, YT921X_GLOBAL_CTRL1, 0x16, 0x16);

	/* 2. Disable proprietary 0x9988 CPU tag on EXT_CPU_PORT (0x8000c = 0x0)
	 *    so all frames on Port 4 (dp1) and Port 8 (dp2) are plain Ethernet.
	 */
	yt9215_smi_write(mdiodev, YT921X_EXT_CPU_PORT_REG, 0x0);

	/* 3. Enable L2 forwarding engine (0x180690 = 1) */
	yt9215_smi_write(mdiodev, YT921X_L2_ENABLE_REG, 0x1);

	/* 4. Open egress masks & flood control across active ports (0..4, 8 -> 0x11f) */
	yt9215_smi_update_bits(mdiodev, YT921X_PORT_EGR_MASK1, 0x7ff, 0x11f);
	yt9215_smi_update_bits(mdiodev, YT921X_PORT_EGR_MASK2, 0x7ff0, 0x11f << 4);
	for (r = YT921X_FLOOD_CTRL_BASE; r < YT921X_FLOOD_CTRL_END; r += 4)
		yt9215_smi_update_bits(mdiodev, r, 0xff, 0xff);

	/* 5. Configure Port 8 (SGMII primary conduit -> dp2 / eth0):
	 *    - Enable interface (0x80028 |= BIT(0)) and ungate SerDes (0x80394 &= ~BIT(1))
	 *    - Rev-SGMII mode (0x8006c + 8*4: mask 0x380, val 0x80)
	 *    - Force 1000M full-duplex with RX/TX MAC + pause (0x80100 + 8*4 = 0x1fa,
	 *      0x802d4 + 8*4 = 0x1a, 0x8036c + 8*4 = 0x1a, 0x80078 + 8*8 |= 0x80000)
	 */
	yt9215_smi_update_bits(mdiodev, YT921X_INTERFACE_CTRL, BIT(0), BIT(0));
	yt9215_smi_update_bits(mdiodev, YT921X_SERDES_CTRL, BIT(1), 0);
	yt9215_smi_update_bits(mdiodev, YT921X_SGMII_MODE(8), 0x380, 0x80);
	yt9215_smi_update_bits(mdiodev, YT921X_SGMII_LINK(8), 0x7f, 0x7a);
	yt9215_smi_update_bits(mdiodev, YT921X_MAC_EN(8), 0x80000, 0x80000);
	yt9215_smi_write(mdiodev, YT921X_XMII_CTRL(8), 0x1a);
	yt9215_smi_update_bits(mdiodev, YT921X_PORT_CTRL(8), 0x2ff, 0x2fa);

	/* 6. Configure Port 4 (Internal GE PHY secondary conduit -> dp1 / eth1):
	 *    Force 1000M full-duplex MAC & enable internal PHY 0..4 auto-negotiation
	 */
	yt9215_smi_update_bits(mdiodev, YT921X_PORT_CTRL(4), 0x2ff, 0x2fa);
	for (p = 0; p <= 3; p++)
		yt9215_smi_update_bits(mdiodev, YT921X_PORT_CTRL(p), 0x218, 0x218);

	/* 7. Enable MAC learning on user ports 0..3 and conduit ports 4, 8 */
	for (p = 0; p <= 4; p++)
		yt9215_smi_write(mdiodev, YT921X_PORT_LEARN_CTRL(p), 0x3b5ed1 & ~0x20000);
	yt9215_smi_write(mdiodev, YT921X_PORT_LEARN_CTRL(8), 0x3b5ed1 & ~0x20000);

	/* 8. Option B Hardware Port Isolation Matrix (0x180294 + port * 4):
	 *    NOTE: In YT9215, bit=1 in 0x180294 BLOCKS forwarding to that destination port,
	 *    and bit=0 ALLOWS forwarding!
	 *    - WAN group (Port 3 <-> Port 4, mask of allowed dests = 0x018):
	 *      Port 3 allowed dest = BIT(4) (0x010) -> block mask = 0x7ff & ~0x010 = 0x7ef
	 *      Port 4 allowed dest = BIT(3) (0x008) -> block mask = 0x7ff & ~0x008 = 0x7f7
	 *    - LAN group (Port 0, 1, 2 <-> Port 8, mask of allowed dests = 0x107):
	 *      Port 0 allowed dest = 0x106 -> block mask = 0x7ff & ~0x106 = 0x6f9
	 *      Port 1 allowed dest = 0x105 -> block mask = 0x7ff & ~0x105 = 0x6fa
	 *      Port 2 allowed dest = 0x103 -> block mask = 0x7ff & ~0x103 = 0x6fc
	 *      Port 8 allowed dest = 0x007 -> block mask = 0x7ff & ~0x007 = 0x7f8
	 */
	yt9215_smi_update_bits(mdiodev, YT921X_PORT_ISOLATION(0), 0x7ff, 0x7ff & ~0x106);
	yt9215_smi_update_bits(mdiodev, YT921X_PORT_ISOLATION(1), 0x7ff, 0x7ff & ~0x105);
	yt9215_smi_update_bits(mdiodev, YT921X_PORT_ISOLATION(2), 0x7ff, 0x7ff & ~0x103);
	yt9215_smi_update_bits(mdiodev, YT921X_PORT_ISOLATION(8), 0x7ff, 0x7ff & ~0x007);

	yt9215_smi_update_bits(mdiodev, YT921X_PORT_ISOLATION(3), 0x7ff, 0x7ff & ~0x010);
	yt9215_smi_update_bits(mdiodev, YT921X_PORT_ISOLATION(4), 0x7ff, 0x7ff & ~0x008);

	/* 9. Power up and restart auto-negotiation on internal PHYs 0..4 (BMCR = 0x1340) */
	for (p = 0; p <= 4; p++)
		yt9215_int_phy_write(mdiodev, p, MII_BMCR, BMCR_ANENABLE | BMCR_ANRESTART | BMCR_FULLDPLX | BMCR_SPEED1000);

	dev_info(&mdiodev->dev,
		 "YT9215 Option B initialized (chip_id=0x%08x): WAN(P3<->P4/dp1) LAN(P0..2<->P8/dp2) untagged\n",
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
