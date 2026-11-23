#!/bin/bash
# Turn a clean OpenWrt v25.12.5 checkout into a buildable Xiaomi AX3000 (RA80 v2) NSS tree.
#
# Usage:  scripts/setup.sh /path/to/openwrt
set -euo pipefail

HERE=$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)
OW=${1:?usage: $0 /path/to/openwrt}
OW=$(cd "$OW" && pwd)

say() { printf '\n\033[1m==> %s\033[0m\n' "$*"; }

[ -f "$OW/rules.mk" ] || { echo "$OW does not look like an OpenWrt tree"; exit 1; }

# ---------------------------------------------------------------- 1. base version
if [ -d "$OW/.git" ]; then
    have=$(git -C "$OW" describe --tags --exact-match 2>/dev/null || echo "unknown")
    say "OpenWrt base: $have"
    if [ "$have" != "v25.12.5" ]; then
        echo "WARNING: this project is developed against v25.12.5."
        echo "         Patch 1 is a plain diff and will likely fail elsewhere."
    fi
fi

# ---------------------------------------------------------------- 2. tracked edits
say "Applying edits to upstream files"
PATCH="$HERE/openwrt/0001-xiaomi-ra80v2-nss.patch"
if git -C "$OW" apply --reverse --check "$PATCH" 2>/dev/null; then
    echo "already applied, skipping"
else
    git -C "$OW" apply --verbose "$PATCH"
fi

# ---------------------------------------------------------------- 2b. Xiaomi AX3000 v2 (RA80 v2) target integration
say "Integrating Xiaomi AX3000 v2 (RA80 v2) target & base-files"

IPQ_MK="$OW/target/linux/qualcommax/image/ipq50xx.mk"
if ! grep -q 'Device/xiaomi_ax3000-v2' "$IPQ_MK"; then
    cat >> "$IPQ_MK" << 'EOF'

define Device/xiaomi_ax3000-v2
	$(call Device/FitImageLzma)
	$(call Device/UbiFit)
	DEVICE_VENDOR := Xiaomi
	DEVICE_MODEL := AX3000
	DEVICE_VARIANT := v2
	BLOCKSIZE := 128k
	PAGESIZE := 2048
	NAND_SIZE := 128m
	SOC := ipq5018
	DEVICE_DTS_CONFIG := config@mp03.3
	DEVICE_PACKAGES := ath11k-firmware-ipq5018-qcn6122 ipq-wifi-xiaomi_ax3000-v2 \
		uboot-envtools zram-swap kmod-mtd-rw
endef
TARGET_DEVICES += xiaomi_ax3000-v2
EOF
fi

LEDS_SH="$OW/target/linux/qualcommax/ipq50xx/base-files/etc/board.d/01_leds"
if ! grep -q 'xiaomi,ax3000-v2)' "$LEDS_SH"; then
    sed -i '/case "\$board" in/a \
xiaomi,ax3000-v2)\
\tucidef_set_led_netdev "wan-blue" "WAN-BLUE" "blue:wan" "eth1" "tx rx link_1000"\
\tucidef_set_led_netdev "wan-orange" "WAN-ORANGE" "orange:wan" "eth1" "link_10 link_100"\
\t;;' "$LEDS_SH"
fi

NET_SH="$OW/target/linux/qualcommax/ipq50xx/base-files/etc/board.d/02_network"
if ! grep -q 'xiaomi,ax3000-v2)' "$NET_SH"; then
    sed -i '/case \$board in/a \
\txiaomi,ax3000-v2)\
\t\t# Option B Dual-Conduit Untagged Raw Ethernet on Motorcomm YT9215:\
\t\t#   dp2 (eth0) <- Port 8 (SGMII) <- LAN 1..3 (Port 0..2)\
\t\t#   dp1 (eth1) <- Port 4 (GE PHY) <- WAN (Port 3)\
\t\tucidef_set_interfaces_lan_wan "eth0" "eth1"\
\t\t;;' "$NET_SH"
fi

CAL_SH="$OW/target/linux/qualcommax/ipq50xx/base-files/etc/hotplug.d/firmware/11-ath11k-caldata"
if ! grep -q 'xiaomi,ax3000-v2)' "$CAL_SH"; then
    sed -i '/"ath11k\/IPQ5018\/hw1.0\/cal-ahb-c000000.wifi.bin")/,/esac/{
        /case "\$board" in/a \
\txiaomi,ax3000-v2)\
\t\tcaldata_extract "0:ART" 0x1000 0x20000\
\t\t;;
    }' "$CAL_SH"
    sed -i '/"ath11k\/QCN6122\/hw1.0\/cal-ahb-b00a040.wifi.bin")/,/esac/{
        /case "\$board" in/a \
\txiaomi,ax3000-v2)\
\t\tcaldata_extract "0:ART" 0x26800 0x20000\
\t\t;;
    }' "$CAL_SH"
fi

UBOOTENV_SH="$OW/target/linux/qualcommax/ipq50xx/base-files/etc/uci-defaults/30_uboot-envtools"
if [ -f "$UBOOTENV_SH" ] && ! grep -q 'xiaomi,ax3000-v2)' "$UBOOTENV_SH"; then
    sed -i '/case "\$board" in/a \
xiaomi,ax3000-v2)\
\tubootenv_add_mtd "0:APPSBLENV" "0x0" "0x10000" "0x20000"\
\t;;' "$UBOOTENV_SH"
fi

BOOTCOUNT_SH="$OW/target/linux/qualcommax/ipq50xx/base-files/etc/init.d/bootcount"
if [ -f "$BOOTCOUNT_SH" ] && ! grep -q 'xiaomi,ax3000-v2)' "$BOOTCOUNT_SH"; then
    sed -i '/case \$(board_name) in/a \
\txiaomi,ax3000-v2)\
\t\t[ "$(fw_printenv -n bootcmd 2>/dev/null)" = "bootmiwifi" ] || return 0\
\t\t[ "$(fw_printenv -n flag_ota_reboot 2>/dev/null)" = "0" ] || fw_setenv flag_ota_reboot 0\
\t\t[ "$(fw_printenv -n flag_boot_success 2>/dev/null)" = "1" ] || fw_setenv flag_boot_success 1\
\t\t[ "$(fw_printenv -n flag_try_sys1_failed 2>/dev/null)" = "0" ] || fw_setenv flag_try_sys1_failed 0\
\t;;' "$BOOTCOUNT_SH"
fi

PLAT_SH="$OW/target/linux/qualcommax/ipq50xx/base-files/lib/upgrade/platform.sh"
if ! grep -q 'xiaomi,ax3000-v2)' "$PLAT_SH"; then
    sed -i '/platform_do_upgrade() {/,/esac/{
        /case "\$(board_name)" in/a \
\txiaomi,ax3000-v2)\
\t\tif [ "$(fw_printenv -n bootcmd 2>/dev/null)" = "bootmiwifi" ]; then\
\t\t\tfw_setenv boot_wait on\
\t\t\tfw_setenv uart_en 1\
\t\t\tfw_setenv flag_boot_rootfs 0\
\t\t\tfw_setenv flag_last_success 0\
\t\t\tfw_setenv flag_boot_success 1\
\t\t\tfw_setenv flag_try_sys1_failed 0\
\t\t\tfw_setenv flag_try_sys2_failed 0\
\t\tfi\
\t\tCI_KERN_UBIPART="ubi_kernel"\
\t\tCI_ROOT_UBIPART="rootfs"\
\t\tCI_DATA_UBIPART="rootfs"\
\t\tnand_do_upgrade "$1"\
\t\t;;
    }' "$PLAT_SH"
fi

REGDB_MK="$OW/package/firmware/wireless-regdb/Makefile"
if [ -f "$REGDB_MK" ] && ! grep -q '5150 - 5350 @ 160' "$REGDB_MK"; then
    cat >> "$REGDB_MK" << 'EOF'

define Build/Prepare
	$(call Build/Prepare/Default)
	python3 -c 'import re, pathlib; p = pathlib.Path("$(PKG_BUILD_DIR)/db.txt"); t = p.read_text(); t = re.sub(r"country CN:.*?(?=\n\t# 60 GHz|\n\n)", "country CN: DFS-FCC\n\t(2400 - 2483.5 @ 40), (30)\n\t(5150 - 5350 @ 160), (30)\n\t(5725 - 5850 @ 80), (33)", t, flags=re.S); p.write_text(t)'
endef
EOF
fi

# ---------------------------------------------------------------- 3. new files
say "Copying files that do not exist upstream"
( cd "$HERE/openwrt/tree" && find . -type f -print0 |
  while IFS= read -r -d '' f; do
      install -Dm644 "$f" "$OW/${f#./}"
      echo "  ${f#./}"
  done )
rm -f "$OW/target/linux/qualcommax/patches-6.12/0820-arm64-dts-qcom-add-xiaomi-ax3000-v2.patch"

# ---------------------------------------------------------------- 4. feed
say "Registering the custom NSS package feed"
FEEDS="$OW/feeds.conf"
[ -f "$FEEDS" ] || cp "$OW/feeds.conf.default" "$FEEDS"
grep -q '^src-link ra80v2 ' "$FEEDS" ||
    echo "src-link ra80v2 $HERE/feed" >> "$FEEDS"
grep '^src-link ra80v2 ' "$FEEDS"

( cd "$OW" && ./scripts/feeds update -a >/dev/null && ./scripts/feeds install -a >/dev/null )
echo "feeds updated and installed"

# ---------------------------------------------------------------- 5. feed package patches
say "Adding patches to packages from other feeds"
( cd "$HERE/openwrt/feeds" && find . -type f -print0 |
  while IFS= read -r -d '' f; do
      install -Dm644 "$f" "$OW/feeds/${f#./}"
      echo "  feeds/${f#./}"
  done )

# ---------------------------------------------------------------- 6. rootfs overlay
say "Installing the rootfs overlay"
mkdir -p "$OW/files"
cp -a "$HERE/files/." "$OW/files/"
if [ -f "$OW/files/usr/lib/lua/luci/i18n/pzl8.zh-cn.lmo" ] && [ ! -f "$OW/files/usr/lib/lua/luci/i18n/ra80v2.zh-cn.lmo" ]; then
    mv "$OW/files/usr/lib/lua/luci/i18n/pzl8.zh-cn.lmo" "$OW/files/usr/lib/lua/luci/i18n/ra80v2.zh-cn.lmo"
fi
find "$OW/files" -name '*pzl8*' -delete 2>/dev/null || true
find "$OW/files" -type f | sed "s|$OW/|  |"
chmod +x "$OW"/files/etc/init.d/* 2>/dev/null || true
chmod +x "$OW"/files/usr/libexec/rpcd/* 2>/dev/null || true

# ---------------------------------------------------------------- 7. config
if [ -f "$OW/.config" ] && [ "${RESEED:-0}" != 1 ]; then
    say "Keeping the existing .config  (RESEED=1 to replace it with the seed)"
else
    say "Seeding .config"
    cp "$HERE/config/xiaomi_ra80v2.config" "$OW/.config"
fi

( cd "$OW" && make defconfig >/dev/null )
grep -E '^CONFIG_TARGET_(BOARD|SUBTARGET|PROFILE)' "$OW/.config" || true

missing=0
for sym in \
    CONFIG_TARGET_qualcommax_ipq50xx_DEVICE_xiaomi_ax3000-v2 \
    CONFIG_NSS_DRV_WIFIOFFLOAD_ENABLE \
    CONFIG_NSS_FIRMWARE_VERSION_12_5 \
    CONFIG_PACKAGE_kmod-qca-nss-drv \
    CONFIG_PACKAGE_nss-firmware-ipq50xx
do
    grep -q "^${sym}=y" "$OW/.config" || { echo "  MISSING: $sym"; missing=1; }
done
if [ "$missing" != 0 ]; then
    echo
    echo "WARNING: the above are required by the NSS offload in this tree."
    echo "         Re-enable them in menuconfig, or run RESEED=1 $0 $OW"
fi

say "Ready.  Build with:  cd $OW && make -j\$(nproc)"
echo "        Pick packages with:  cd $OW && make menuconfig"
echo "        Keep your selection: cd $OW && ./scripts/diffconfig.sh > $HERE/config/xiaomi_ra80v2.config"
