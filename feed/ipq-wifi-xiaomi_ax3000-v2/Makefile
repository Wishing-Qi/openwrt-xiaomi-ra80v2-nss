# Board data (BDF) for Xiaomi AX3000 v2 (RA80 v2, IPQ5018 + QCN6122).
include $(TOPDIR)/rules.mk

PKG_NAME:=ipq-wifi-xiaomi_ax3000-v2
PKG_RELEASE:=1
PKG_FLAGS:=nonshared

include $(INCLUDE_DIR)/package.mk

define Package/ipq-wifi-xiaomi_ax3000-v2
  SECTION:=firmware
  CATEGORY:=Firmware
  TITLE:=Board data for Xiaomi AX3000 v2 (IPQ5018 + QCN6122)
  DEPENDS:=@TARGET_qualcommax_ipq50xx
endef

define Package/ipq-wifi-xiaomi_ax3000-v2/description
  Device specific ath11k board data for the Xiaomi AX3000 v2 (RA80 v2).
endef

define Build/Compile
endef

define Package/ipq-wifi-xiaomi_ax3000-v2/install
	$(INSTALL_DIR) $(1)/lib/firmware/ath11k/IPQ5018/hw1.0
	python3 -c "import base64,zlib; open('$(1)/lib/firmware/ath11k/IPQ5018/hw1.0/board-2.bin','wb').write(zlib.decompress(base64.b64decode(open('./board-2.bin.IPQ5018.zb64').read())))"
	$(INSTALL_DIR) $(1)/lib/firmware/ath11k/QCN6122/hw1.0
	python3 -c "import base64,zlib; open('$(1)/lib/firmware/ath11k/QCN6122/hw1.0/board-2.bin','wb').write(zlib.decompress(base64.b64decode(open('./board-2.bin.QCN6122.zb64').read())))"
endef

$(eval $(call BuildPackage,ipq-wifi-xiaomi_ax3000-v2))
