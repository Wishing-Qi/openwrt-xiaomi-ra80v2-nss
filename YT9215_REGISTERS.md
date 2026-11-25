# Motorcomm YT9215 Official Register & Bitfield Reference

Extracted directly from `tbl_reg_list` in Xiaomi AX3000 (RA80 v2) stock firmware `1.0.34` (`yt_switch.ko`).

## 1. Summary Table (`tbl_reg_list`, 237 Register Tables)

| ID | Register Name | Base Address | Stride | Bytes | Entries | Fields |
|---|---|---|---|---|---|---|
| `0x00` | `global_ctrl0` | `0x080000` | `0x4` | 4 | 1 | 1 |
| `0x01` | `global_ctrl1` | `0x080004` | `0x4` | 4 | 1 | 5 |
| `0x02` | `ext_cpu_port_ctrl` | `0x08000c` | `0x4` | 4 | 1 | 3 |
| `0x03` | `cpu_tag_tpid` | `0x080010` | `0x4` | 4 | 1 | 1 |
| `0x04` | `look_up_vlan_sel` | `0x080014` | `0x4` | 4 | 1 | 1 |
| `0x05` | `intr_mask` | `0x080040` | `0x4` | 4 | 1 | 29 |
| `0x06` | `intr_status` | `0x080044` | `0x4` | 4 | 1 | 29 |
| `0x07` | `global_mac_addr0` | `0x080080` | `0x4` | 4 | 1 | 2 |
| `0x08` | `global_mac_addr1` | `0x080084` | `0x4` | 4 | 1 | 4 |
| `0x09` | `eee_ctrl` | `0x080088` | `0x4` | 4 | 1 | 2 |
| `0x0a` | `sg_phy` | `0x08008c` | `0x4` | 4 | 2 | 5 |
| `0x0b` | `port_ctrl` | `0x080100` | `0x4` | 4 | 11 | 9 |
| `0x0c` | `port_status` | `0x080200` | `0x4` | 4 | 11 | 7 |
| `0x0d` | `loop_detect_top_ctrl` | `0x080230` | `0x4` | 4 | 1 | 9 |
| `0x0e` | `pon_strap_en` | `0x080320` | `0x4` | 4 | 1 | 1 |
| `0x0f` | `pon_strap_val` | `0x080324` | `0x4` | 4 | 1 | 1 |
| `0x10` | `pon_strap` | `0x080328` | `0x4` | 4 | 1 | 1 |
| `0x11` | `mdio_polling` | `0x080364` | `0x4` | 4 | 2 | 3 |
| `0x12` | `oam_dying_gasp` | `0x080380` | `0x4` | 4 | 1 | 5 |
| `0x13` | `acl2gpio` | `0x080384` | `0x4` | 4 | 1 | 4 |
| `0x14` | `extif0_mode` | `0x080400` | `0x4` | 4 | 1 | 18 |
| `0x15` | `extif0_mode2` | `0x080404` | `0x4` | 4 | 1 | 4 |
| `0x16` | `extif1_mode` | `0x080408` | `0x4` | 4 | 1 | 18 |
| `0x17` | `extif1_mode2` | `0x08040c` | `0x4` | 4 | 1 | 4 |
| `0x18` | `tpid_profile0` | `0x210000` | `0x4` | 4 | 2 | 1 |
| `0x19` | `tpid_profile1` | `0x210008` | `0x4` | 4 | 2 | 1 |
| `0x1a` | `parser_port_ctrln` | `0x210010` | `0x4` | 4 | 11 | 2 |
| `0x1b` | `link_agg_hash_ctrl` | `0x210090` | `0x4` | 4 | 1 | 1 |
| `0x1c` | `udf_ctrln` | `0x210094` | `0x4` | 4 | 16 | 2 |
| `0x1d` | `parser_erp_oui` | `0x2100d4` | `0x4` | 4 | 1 | 1 |
| `0x1e` | `parser_erp_ethtype` | `0x2100d8` | `0x4` | 4 | 1 | 1 |
| `0x1f` | `parser_erp_udf_ctrl` | `0x2100dc` | `0x4` | 4 | 1 | 1 |
| `0x20` | `parser_erp_udfn` | `0x2100e0` | `0x4` | 4 | 4 | 3 |
| `0x21` | `dos_tcp_flags0` | `0x2100f0` | `0x4` | 4 | 1 | 8 |
| `0x22` | `dos_tcp_flags1` | `0x2100f4` | `0x4` | 4 | 1 | 8 |
| `0x23` | `dos_tcp_flags2` | `0x2100f8` | `0x4` | 4 | 1 | 8 |
| `0x24` | `dos_tcp_flags3` | `0x2100fc` | `0x4` | 4 | 1 | 8 |
| `0x25` | `dos_tcp_flags4` | `0x210100` | `0x4` | 4 | 1 | 8 |
| `0x26` | `dos_tcp_flags5` | `0x210104` | `0x4` | 4 | 1 | 8 |
| `0x27` | `dos_ctrl` | `0x210108` | `0x4` | 4 | 1 | 20 |
| `0x28` | `dos_large_icmp_ctrl` | `0x21010c` | `0x4` | 4 | 1 | 2 |
| `0x29` | `oam_en_ctrl` | `0x210110` | `0x4` | 4 | 1 | 1 |
| `0x2a` | `wol_ctrl` | `0x21011c` | `0x4` | 4 | 1 | 2 |
| `0x2b` | `dos_ctrl1` | `0x210120` | `0x4` | 4 | 1 | 4 |
| `0x2c` | `protocol_based_vlann` | `0x230000` | `0x4` | 4 | 4 | 3 |
| `0x2d` | `port_vlan_ctrln` | `0x230010` | `0x4` | 4 | 11 | 6 |
| `0x2e` | `port_vlan_ctrl1n` | `0x230080` | `0x4` | 4 | 11 | 4 |
| `0x2f` | `vlan_trans_untag_vid_mode_ctrl` | `0x230108` | `0x4` | 4 | 1 | 1 |
| `0x30` | `vlan_range_profilen` | `0x230200` | `0x10` | 12 | 10 | 10 |
| `0x31` | `protocol_based_vlan_data_tbl` | `0x230300` | `0x4` | 4 | 44 | 4 |
| `0x32` | `vlan_xlate_action_tbl` | `0x230400` | `0x8` | 8 | 64 | 11 |
| `0x33` | `vlan_xlate_tbl` | `0x230600` | `0x8` | 8 | 64 | 11 |
| `0x34` | `acl_blk_keep_ctrl` | `0x201000` | `0x4` | 4 | 1 | 16 |
| `0x35` | `acl_port_ctrl` | `0x202000` | `0x4` | 4 | 1 | 1 |
| `0x36` | `acl_blk_cmd` | `0x202004` | `0x4` | 4 | 1 | 2 |
| `0x37` | `rule_ext_ctrl` | `0x203000` | `0x4` | 4 | 48 | 16 |
| `0x38` | `acl_rule_bin0` | `0x204000` | `0x8` | 8 | 48 | 0 |
| `0x39` | `acl_rule_bin1` | `0x204200` | `0x8` | 8 | 48 | 0 |
| `0x3a` | `acl_rule_bin2` | `0x204400` | `0x8` | 8 | 48 | 0 |
| `0x3b` | `acl_rule_bin3` | `0x204600` | `0x8` | 8 | 48 | 0 |
| `0x3c` | `acl_rule_bin4` | `0x204800` | `0x8` | 8 | 48 | 0 |
| `0x3d` | `acl_rule_bin5` | `0x204a00` | `0x8` | 8 | 48 | 0 |
| `0x3e` | `acl_rule_bin6` | `0x204c00` | `0x8` | 8 | 48 | 0 |
| `0x3f` | `acl_rule_bin7` | `0x204e00` | `0x8` | 8 | 48 | 0 |
| `0x40` | `acl_rule_mask_bin0` | `0x205000` | `0x8` | 8 | 48 | 0 |
| `0x41` | `acl_rule_mask_bin1` | `0x205200` | `0x8` | 8 | 48 | 0 |
| `0x42` | `acl_rule_mask_bin2` | `0x205400` | `0x8` | 8 | 48 | 0 |
| `0x43` | `acl_rule_mask_bin3` | `0x205600` | `0x8` | 8 | 48 | 0 |
| `0x44` | `acl_rule_mask_bin4` | `0x205800` | `0x8` | 8 | 48 | 0 |
| `0x45` | `acl_rule_mask_bin5` | `0x205a00` | `0x8` | 8 | 48 | 0 |
| `0x46` | `acl_rule_mask_bin6` | `0x205c00` | `0x8` | 8 | 48 | 0 |
| `0x47` | `acl_rule_mask_bin7` | `0x205e00` | `0x8` | 8 | 48 | 0 |
| `0x48` | `mac_da0_rule` | `0x000000` | `0x8` | 8 | 1 | 6 |
| `0x49` | `mac_da0_rule_mask` | `0x000000` | `0x8` | 8 | 1 | 2 |
| `0x4a` | `mac_da1_sa1_rule` | `0x000000` | `0x8` | 8 | 1 | 8 |
| `0x4b` | `mac_da1_sa1_rule_mask` | `0x000000` | `0x8` | 8 | 1 | 4 |
| `0x4c` | `mac_sa0_rule` | `0x000000` | `0x8` | 8 | 1 | 6 |
| `0x4d` | `mac_sa0_rule_mask` | `0x000000` | `0x8` | 8 | 1 | 2 |
| `0x4e` | `ipv4_da_rule` | `0x000000` | `0x8` | 8 | 1 | 8 |
| `0x4f` | `ipv4_da_rule_mask` | `0x000000` | `0x8` | 8 | 1 | 3 |
| `0x50` | `ipv4_sa_rule` | `0x000000` | `0x8` | 8 | 1 | 8 |
| `0x51` | `ipv4_sa_rule_mask` | `0x000000` | `0x8` | 8 | 1 | 3 |
| `0x52` | `l4_port_rule` | `0x000000` | `0x8` | 8 | 1 | 10 |
| `0x53` | `l4_port_rule_mask` | `0x000000` | `0x8` | 8 | 1 | 4 |
| `0x54` | `vlan_rule` | `0x000000` | `0x8` | 8 | 1 | 14 |
| `0x55` | `vlan_rule_mask` | `0x000000` | `0x8` | 8 | 1 | 8 |
| `0x56` | `misc_rule` | `0x000000` | `0x8` | 8 | 1 | 14 |
| `0x57` | `misc_rule_mask` | `0x000000` | `0x8` | 8 | 1 | 10 |
| `0x58` | `udf_rule` | `0x000000` | `0x8` | 8 | 1 | 8 |
| `0x59` | `udf_rule_mask` | `0x000000` | `0x8` | 8 | 1 | 4 |
| `0x5a` | `ipv6_da0_rule` | `0x000000` | `0x8` | 8 | 1 | 7 |
| `0x5b` | `ipv6_da0_rule_mask` | `0x000000` | `0x8` | 8 | 1 | 3 |
| `0x5c` | `ipv6_da1_rule` | `0x000000` | `0x8` | 8 | 1 | 7 |
| `0x5d` | `ipv6_da1_rule_mask` | `0x000000` | `0x8` | 8 | 1 | 3 |
| `0x5e` | `ipv6_da2_rule` | `0x000000` | `0x8` | 8 | 1 | 7 |
| `0x5f` | `ipv6_da2_rule_mask` | `0x000000` | `0x8` | 8 | 1 | 3 |
| `0x60` | `ipv6_da3_rule` | `0x000000` | `0x8` | 8 | 1 | 8 |
| `0x61` | `ipv6_da3_rule_mask` | `0x000000` | `0x8` | 8 | 1 | 3 |
| `0x62` | `ipv6_sa0_rule` | `0x000000` | `0x8` | 8 | 1 | 7 |
| `0x63` | `ipv6_sa0_rule_mask` | `0x000000` | `0x8` | 8 | 1 | 3 |
| `0x64` | `ipv6_sa1_rule` | `0x000000` | `0x8` | 8 | 1 | 7 |
| `0x65` | `ipv6_sa1_rule_mask` | `0x000000` | `0x8` | 8 | 1 | 3 |
| `0x66` | `ipv6_sa2_rule` | `0x000000` | `0x8` | 8 | 1 | 7 |
| `0x67` | `ipv6_sa2_rule_mask` | `0x000000` | `0x8` | 8 | 1 | 3 |
| `0x68` | `ipv6_sa3_rule` | `0x000000` | `0x8` | 8 | 1 | 8 |
| `0x69` | `ipv6_sa3_rule_mask` | `0x000000` | `0x8` | 8 | 1 | 3 |
| `0x6a` | `vid_pri_dei_rule` | `0x000000` | `0x8` | 8 | 1 | 13 |
| `0x6b` | `vid_pri_dei_rule_mask` | `0x000000` | `0x8` | 4 | 1 | 6 |
| `0x6c` | `ether_type_value_rule` | `0x000000` | `0x8` | 8 | 1 | 9 |
| `0x6d` | `ether_type_value_rule_mask` | `0x000000` | `0x8` | 8 | 1 | 4 |
| `0x6e` | `dscp_to_int_prio_map` | `0x180000` | `0x4` | 4 | 64 | 2 |
| `0x6f` | `pri_to_int_prio_map` | `0x180100` | `0x4` | 4 | 32 | 2 |
| `0x70` | `qos_port_ctrln` | `0x180180` | `0x4` | 4 | 11 | 4 |
| `0x71` | `qos_merge_precedence_ctrln` | `0x180200` | `0x4` | 4 | 11 | 8 |
| `0x72` | `hdr_err_action` | `0x180270` | `0x4` | 4 | 1 | 2 |
| `0x73` | `l2_vlan_ingress_filter_en` | `0x180280` | `0x4` | 4 | 1 | 2 |
| `0x74` | `l2_arp_bcast_per_port_ctrl` | `0x180284` | `0x4` | 4 | 1 | 2 |
| `0x75` | `l2_nd_per_port_ctrl` | `0x180288` | `0x4` | 4 | 1 | 2 |
| `0x76` | `l2_lldp_eee_per_port_ctrl` | `0x18028c` | `0x4` | 4 | 1 | 2 |
| `0x77` | `l2_lldp_per_port_ctrl` | `0x180290` | `0x4` | 4 | 1 | 2 |
| `0x78` | `l2_port_isolation_ctrln` | `0x180294` | `0x4` | 4 | 11 | 1 |
| `0x79` | `l2_erp_per_port_ctrl` | `0x18030c` | `0x4` | 4 | 11 | 5 |
| `0x7a` | `l2_stp_staten` | `0x18038c` | `0x4` | 4 | 16 | 1 |
| `0x7b` | `l2_src_match_ctrl` | `0x1803cc` | `0x4` | 4 | 1 | 1 |
| `0x7c` | `l2_learn_per_port_ctrln` | `0x1803d0` | `0x4` | 4 | 11 | 10 |
| `0x7d` | `l2_station_move_ctrl0` | `0x1803fc` | `0x4` | 4 | 1 | 2 |
| `0x7e` | `l2_station_move_ctrl1` | `0x180400` | `0x4` | 4 | 1 | 1 |
| `0x7f` | `l2_port_learn_mac_cntn` | `0x180404` | `0x4` | 4 | 13 | 1 |
| `0x80` | `l2_learn_global_ctrl` | `0x180438` | `0x4` | 4 | 1 | 6 |
| `0x81` | `l2_learn_mac_cnt` | `0x18043c` | `0x4` | 4 | 1 | 1 |
| `0x82` | `l2_aging_ctrl` | `0x180440` | `0x4` | 4 | 1 | 1 |
| `0x83` | `l2_aging_per_port_ctrl` | `0x180448` | `0x4` | 4 | 1 | 1 |
| `0x84` | `l2_fdb_tbl_op_data_0` | `0x180454` | `0x4` | 4 | 1 | 1 |
| `0x85` | `l2_fdb_tbl_op_data_1` | `0x180458` | `0x4` | 4 | 1 | 4 |
| `0x86` | `l2_fdb_tbl_op_data_2` | `0x18045c` | `0x4` | 4 | 1 | 8 |
| `0x87` | `l2_fdb_tbl_op` | `0x180460` | `0x4` | 4 | 1 | 7 |
| `0x88` | `l2_fdb_tbl_op_result` | `0x180464` | `0x4` | 4 | 1 | 5 |
| `0x89` | `l2_igmp_static_router_port_mask` | `0x180468` | `0x4` | 4 | 1 | 1 |
| `0x8a` | `l2_igmp_dynamic_router_port_ctrl` | `0x18046c` | `0x4` | 4 | 1 | 2 |
| `0x8b` | `l2_igmp_dynamic_router_port` | `0x180470` | `0x4` | 4 | 1 | 2 |
| `0x8c` | `l2_igmp_dynamic_router_port0_timer` | `0x180474` | `0x4` | 4 | 1 | 1 |
| `0x8d` | `l2_igmp_dynamic_router_port1_timer` | `0x180478` | `0x4` | 4 | 1 | 1 |
| `0x8e` | `l2_igmp_global_ctrl` | `0x18047c` | `0x4` | 4 | 1 | 10 |
| `0x8f` | `l2_igmp_per_port_ctrl` | `0x180480` | `0x4` | 4 | 11 | 8 |
| `0x90` | `l2_fdb_tbl_op_data_0_dummy` | `0x1804b0` | `0x4` | 4 | 1 | 1 |
| `0x91` | `l2_fdb_tbl_op_data_1_dummy` | `0x1804b4` | `0x4` | 4 | 1 | 4 |
| `0x92` | `l2_fdb_tbl_op_data_2_dummy` | `0x1804b8` | `0x4` | 4 | 1 | 8 |
| `0x93` | `l2_igmp_dynamic_router_port_dummy` | `0x1804bc` | `0x4` | 4 | 1 | 2 |
| `0x94` | `l2_igmp_dynamic_router_port0_timer_dummy` | `0x1804c0` | `0x4` | 4 | 1 | 1 |
| `0x95` | `l2_igmp_dynamic_router_port1_timer_dummy` | `0x1804c4` | `0x4` | 4 | 1 | 1 |
| `0x96` | `l2_igmp_learn_ctrl` | `0x180500` | `0x4` | 4 | 1 | 2 |
| `0x97` | `l2_igmp_learn_group_cnt` | `0x180504` | `0x4` | 4 | 1 | 1 |
| `0x98` | `l2_unknown_ucast_filter_mask` | `0x180508` | `0x4` | 4 | 1 | 1 |
| `0x99` | `l2_unknown_mcast_filter_mask` | `0x18050c` | `0x4` | 4 | 1 | 1 |
| `0x9a` | `l2_mcast_filter_mask` | `0x180510` | `0x4` | 4 | 1 | 1 |
| `0x9b` | `l2_bcast_filter_mask` | `0x180514` | `0x4` | 4 | 1 | 1 |
| `0x9c` | `l2_port_vlan_transparent_ctrl` | `0x180518` | `0x4` | 4 | 11 | 1 |
| `0x9d` | `l2_egr_vlan_filter_en` | `0x180598` | `0x4` | 4 | 1 | 1 |
| `0x9e` | `l2_dot1x_ctrl1` | `0x18059c` | `0x4` | 4 | 1 | 1 |
| `0x9f` | `l2_dot1x_ctrl2` | `0x1805a0` | `0x4` | 4 | 1 | 6 |
| `0xa0` | `ipmc_leaky_ctrl` | `0x1805a4` | `0x4` | 4 | 1 | 2 |
| `0xa1` | `link_agg_groupn` | `0x1805a8` | `0x4` | 4 | 2 | 2 |
| `0xa2` | `link_agg_membern` | `0x1805b0` | `0x4` | 4 | 8 | 1 |
| `0xa3` | `rma_ctrln` | `0x1805d0` | `0x4` | 4 | 48 | 8 |
| `0xa4` | `cpu_copy_dst_ctrl` | `0x180690` | `0x4` | 4 | 1 | 3 |
| `0xa5` | `acl_unmatch_permit_enable_ctrl` | `0x1806a0` | `0x4` | 4 | 1 | 1 |
| `0xa6` | `oam_mux_act` | `0x1806ac` | `0x4` | 4 | 1 | 1 |
| `0xa7` | `oam_par_act` | `0x1806b0` | `0x4` | 4 | 1 | 2 |
| `0xa8` | `cascade_ctrl` | `0x1806b4` | `0x4` | 4 | 1 | 3 |
| `0xa9` | `loop_detect_act_ctrl` | `0x1806b8` | `0x4` | 4 | 1 | 1 |
| `0xaa` | `igmp_router_port_aging_ctrl` | `0x1806bc` | `0x4` | 4 | 1 | 1 |
| `0xab` | `multi_vlan_tbl` | `0x180700` | `0x4` | 4 | 8 | 4 |
| `0xac` | `l2_learn_clear_op` | `0x180730` | `0x4` | 4 | 1 | 5 |
| `0xad` | `l2_uc_unknown_act_ctrl` | `0x180734` | `0x4` | 4 | 1 | 1 |
| `0xae` | `l2_mc_unknown_act_ctrl` | `0x180738` | `0x4` | 4 | 1 | 3 |
| `0xaf` | `l2_lag_learn_limit_ctrln` | `0x180808` | `0x4` | 4 | 2 | 3 |
| `0xb0` | `l2_loop_detect_flag` | `0x180810` | `0x4` | 4 | 1 | 2 |
| `0xb1` | `l2_loop_detect_flag_dummy` | `0x180814` | `0x4` | 4 | 1 | 1 |
| `0xb2` | `l2_loop_detect_timer` | `0x180818` | `0x4` | 4 | 1 | 10 |
| `0xb3` | `l2_arp_bcast_per_port_ctrl1` | `0x180940` | `0x4` | 4 | 1 | 2 |
| `0xb4` | `l2_nd_per_port_ctrl1` | `0x180944` | `0x4` | 4 | 1 | 2 |
| `0xb5` | `l2_lldp_eee_per_port_ctrl1` | `0x180948` | `0x4` | 4 | 1 | 2 |
| `0xb6` | `l2_lldp_per_port_ctrl1` | `0x18094c` | `0x4` | 4 | 1 | 2 |
| `0xb7` | `l2_arp_bcast_nd_per_port_ctrl2` | `0x180950` | `0x4` | 4 | 1 | 2 |
| `0xb8` | `l2_lldp_eee_per_port_ctrl2` | `0x180954` | `0x4` | 4 | 1 | 2 |
| `0xb9` | `l2_fdb_hw_flush_ctrl` | `0x180958` | `0x4` | 4 | 1 | 1 |
| `0xba` | `l2_uni_que_ctrl` | `0x18095c` | `0x4` | 4 | 1 | 1 |
| `0xbb` | `l2_vlan_tbl` | `0x188000` | `0x8` | 8 | 4096 | 12 |
| `0xbc` | `l2_fdb_tbl_bin0` | `0x198000` | `0x10` | 12 | 512 | 13 |
| `0xbd` | `l2_fdb_tbl_bin1` | `0x19a000` | `0x10` | 12 | 512 | 13 |
| `0xbe` | `l2_fdb_tbl_bin2` | `0x19c000` | `0x10` | 12 | 512 | 13 |
| `0xbf` | `l2_fdb_tbl_bin3` | `0x19e000` | `0x10` | 12 | 512 | 13 |
| `0xc0` | `l2_fdb_tbl_bin4` | `0x1a0000` | `0x10` | 12 | 512 | 13 |
| `0xc1` | `l2_fdb_tbl_bin5` | `0x1a2000` | `0x10` | 12 | 512 | 13 |
| `0xc2` | `l2_fdb_tbl_bin6` | `0x1a4000` | `0x10` | 12 | 512 | 13 |
| `0xc3` | `l2_fdb_tbl_bin7` | `0x1a6000` | `0x10` | 12 | 512 | 13 |
| `0xc4` | `acl_action_tbl` | `0x1c0000` | `0x10` | 12 | 384 | 33 |
| `0xc5` | `port_rate_ctrln` | `0x220000` | `0x4` | 4 | 11 | 1 |
| `0xc6` | `storm_ctrl_timeslot` | `0x220100` | `0x4` | 4 | 1 | 1 |
| `0xc7` | `meter_timeslot` | `0x220104` | `0x4` | 4 | 1 | 1 |
| `0xc8` | `port_meter_ctrln` | `0x220108` | `0x4` | 4 | 11 | 2 |
| `0xc9` | `storm_ctrl_mc_type_ctrl` | `0x220140` | `0x4` | 4 | 1 | 1 |
| `0xca` | `drop_event_log` | `0x220158` | `0x4` | 4 | 1 | 2 |
| `0xcb` | `stats_offset` | `0x22015c` | `0x4` | 4 | 1 | 2 |
| `0xcc` | `storm_ctrl_config_tbl` | `0x220200` | `0x4` | 4 | 33 | 5 |
| `0xcd` | `storm_ctrl_cnt_tbl` | `0x220400` | `0x4` | 4 | 33 | 2 |
| `0xce` | `meter_config_tbl` | `0x220800` | `0x10` | 12 | 75 | 14 |
| `0xcf` | `meter_token_tbl` | `0x221000` | `0x8` | 8 | 75 | 4 |
| `0xd0` | `flow_stats_tbl` | `0x221400` | `0x8` | 8 | 64 | 2 |
| `0xd1` | `flow_stats_cfg_tbl` | `0x221c00` | `0x4` | 4 | 64 | 3 |
| `0xd2` | `cpu_code_to_cpu_prio_mapn` | `0x300000` | `0x4` | 4 | 64 | 1 |
| `0xd3` | `int_prio_to_ucast_qid_mapn` | `0x300200` | `0x4` | 4 | 11 | 8 |
| `0xd4` | `int_prio_to_mcast_qid_mapn` | `0x300280` | `0x4` | 4 | 11 | 8 |
| `0xd5` | `mirror_ctrl` | `0x300300` | `0x4` | 4 | 1 | 3 |
| `0xd6` | `mirror_qos_ctrl` | `0x300304` | `0x4` | 4 | 1 | 4 |
| `0xd7` | `flush_cfg` | `0x300400` | `0x4` | 4 | 1 | 3 |
| `0xd8` | `oq_enq_dis_tbl` | `0x308000` | `0x4` | 4 | 132 | 1 |
| `0xd9` | `egr_port_ctrln` | `0x100000` | `0x4` | 4 | 11 | 9 |
| `0xda` | `egr_port_vlan_ctrln` | `0x100080` | `0x4` | 4 | 11 | 6 |
| `0xdb` | `egr_dscp_remarkn` | `0x100100` | `0x4` | 4 | 32 | 1 |
| `0xdc` | `egr_prio_remarkn` | `0x100200` | `0x4` | 4 | 64 | 2 |
| `0xdd` | `egr_tpid_profile` | `0x100300` | `0x4` | 4 | 4 | 1 |
| `0xde` | `egr_vlan_trans_rule_ctrln` | `0x100320` | `0x4` | 4 | 32 | 8 |
| `0xdf` | `egr_vlan_trans_rule_ctrl1n` | `0x1003a0` | `0x4` | 4 | 32 | 3 |
| `0xe0` | `egr_vlan_trans_data_ctrln` | `0x100420` | `0x4` | 4 | 32 | 4 |
| `0xe1` | `egr_vlan_tag_transparent_ctrl` | `0x1004a8` | `0x4` | 4 | 11 | 4 |
| `0xe2` | `cpu_pkt_bypassedit_ctrl` | `0x1004d4` | `0x4` | 4 | 1 | 2 |
| `0xe3` | `ipg_pre_len_cfg` | `0x340004` | `0x4` | 4 | 1 | 1 |
| `0xe4` | `qsch_shp_slot_time_cfg` | `0x340008` | `0x4` | 4 | 1 | 1 |
| `0xe5` | `psch_shp_slot_time_cfg` | `0x34000c` | `0x4` | 4 | 1 | 1 |
| `0xe6` | `qsch_flow_map_tbl` | `0x341000` | `0x4` | 4 | 132 | 4 |
| `0xe7` | `qsch_c_dwrr_cfg_tbl` | `0x342000` | `0x4` | 4 | 132 | 1 |
| `0xe8` | `qsch_e_dwrr_cfg_tbl` | `0x343000` | `0x4` | 4 | 132 | 1 |
| `0xe9` | `qsch_shp_cfg_tbl` | `0x34c000` | `0x10` | 12 | 132 | 9 |
| `0xea` | `qsch_meter_cfg_tbl` | `0x34f000` | `0x4` | 4 | 132 | 1 |
| `0xeb` | `psch_shp_cfg_tbl` | `0x354000` | `0x8` | 8 | 11 | 5 |
| `0xec` | `psch_meter_cfg_tbl` | `0x357000` | `0x4` | 4 | 11 | 1 |

## 2. Bitfield Definitions per Register

### `0x080000` — `global_ctrl0` (Table `0x00`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 1 | 1 | `[1:1]` | `0x00000002` |

### `0x080004` — `global_ctrl1` (Table `0x01`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 4 | 1 | `[4:4]` | `0x00000010` |
| 1 | +0 (`word[0]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 2 | +0 (`word[0]`) | 2 | 1 | `[2:2]` | `0x00000004` |
| 3 | +0 (`word[0]`) | 1 | 1 | `[1:1]` | `0x00000002` |
| 4 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x08000c` — `ext_cpu_port_ctrl` (Table `0x02`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 15 | 1 | `[15:15]` | `0x00008000` |
| 1 | +0 (`word[0]`) | 14 | 1 | `[14:14]` | `0x00004000` |
| 2 | +0 (`word[0]`) | 0 | 4 | `[3:0]` | `0x0000000f` |

### `0x080010` — `cpu_tag_tpid` (Table `0x03`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 16 | `[15:0]` | `0x0000ffff` |

### `0x080014` — `look_up_vlan_sel` (Table `0x04`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 11 | `[10:0]` | `0x000007ff` |

### `0x080040` — `intr_mask` (Table `0x05`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 28 | 1 | `[28:28]` | `0x10000000` |
| 1 | +0 (`word[0]`) | 27 | 1 | `[27:27]` | `0x08000000` |
| 2 | +0 (`word[0]`) | 26 | 1 | `[26:26]` | `0x04000000` |
| 3 | +0 (`word[0]`) | 25 | 1 | `[25:25]` | `0x02000000` |
| 4 | +0 (`word[0]`) | 24 | 1 | `[24:24]` | `0x01000000` |
| 5 | +0 (`word[0]`) | 23 | 1 | `[23:23]` | `0x00800000` |
| 6 | +0 (`word[0]`) | 22 | 1 | `[22:22]` | `0x00400000` |
| 7 | +0 (`word[0]`) | 21 | 1 | `[21:21]` | `0x00200000` |
| 8 | +0 (`word[0]`) | 20 | 1 | `[20:20]` | `0x00100000` |
| 9 | +0 (`word[0]`) | 19 | 1 | `[19:19]` | `0x00080000` |
| 10 | +0 (`word[0]`) | 18 | 1 | `[18:18]` | `0x00040000` |
| 11 | +0 (`word[0]`) | 17 | 1 | `[17:17]` | `0x00020000` |
| 12 | +0 (`word[0]`) | 16 | 1 | `[16:16]` | `0x00010000` |
| 13 | +0 (`word[0]`) | 15 | 1 | `[15:15]` | `0x00008000` |
| 14 | +0 (`word[0]`) | 14 | 1 | `[14:14]` | `0x00004000` |
| 15 | +0 (`word[0]`) | 13 | 1 | `[13:13]` | `0x00002000` |
| 16 | +0 (`word[0]`) | 12 | 1 | `[12:12]` | `0x00001000` |
| 17 | +0 (`word[0]`) | 11 | 1 | `[11:11]` | `0x00000800` |
| 18 | +0 (`word[0]`) | 10 | 1 | `[10:10]` | `0x00000400` |
| 19 | +0 (`word[0]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 20 | +0 (`word[0]`) | 8 | 1 | `[8:8]` | `0x00000100` |
| 21 | +0 (`word[0]`) | 7 | 1 | `[7:7]` | `0x00000080` |
| 22 | +0 (`word[0]`) | 6 | 1 | `[6:6]` | `0x00000040` |
| 23 | +0 (`word[0]`) | 5 | 1 | `[5:5]` | `0x00000020` |
| 24 | +0 (`word[0]`) | 4 | 1 | `[4:4]` | `0x00000010` |
| 25 | +0 (`word[0]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 26 | +0 (`word[0]`) | 2 | 1 | `[2:2]` | `0x00000004` |
| 27 | +0 (`word[0]`) | 1 | 1 | `[1:1]` | `0x00000002` |
| 28 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x080044` — `intr_status` (Table `0x06`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 28 | 1 | `[28:28]` | `0x10000000` |
| 1 | +0 (`word[0]`) | 27 | 1 | `[27:27]` | `0x08000000` |
| 2 | +0 (`word[0]`) | 26 | 1 | `[26:26]` | `0x04000000` |
| 3 | +0 (`word[0]`) | 25 | 1 | `[25:25]` | `0x02000000` |
| 4 | +0 (`word[0]`) | 24 | 1 | `[24:24]` | `0x01000000` |
| 5 | +0 (`word[0]`) | 23 | 1 | `[23:23]` | `0x00800000` |
| 6 | +0 (`word[0]`) | 22 | 1 | `[22:22]` | `0x00400000` |
| 7 | +0 (`word[0]`) | 21 | 1 | `[21:21]` | `0x00200000` |
| 8 | +0 (`word[0]`) | 20 | 1 | `[20:20]` | `0x00100000` |
| 9 | +0 (`word[0]`) | 19 | 1 | `[19:19]` | `0x00080000` |
| 10 | +0 (`word[0]`) | 18 | 1 | `[18:18]` | `0x00040000` |
| 11 | +0 (`word[0]`) | 17 | 1 | `[17:17]` | `0x00020000` |
| 12 | +0 (`word[0]`) | 16 | 1 | `[16:16]` | `0x00010000` |
| 13 | +0 (`word[0]`) | 15 | 1 | `[15:15]` | `0x00008000` |
| 14 | +0 (`word[0]`) | 14 | 1 | `[14:14]` | `0x00004000` |
| 15 | +0 (`word[0]`) | 13 | 1 | `[13:13]` | `0x00002000` |
| 16 | +0 (`word[0]`) | 12 | 1 | `[12:12]` | `0x00001000` |
| 17 | +0 (`word[0]`) | 11 | 1 | `[11:11]` | `0x00000800` |
| 18 | +0 (`word[0]`) | 10 | 1 | `[10:10]` | `0x00000400` |
| 19 | +0 (`word[0]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 20 | +0 (`word[0]`) | 8 | 1 | `[8:8]` | `0x00000100` |
| 21 | +0 (`word[0]`) | 7 | 1 | `[7:7]` | `0x00000080` |
| 22 | +0 (`word[0]`) | 6 | 1 | `[6:6]` | `0x00000040` |
| 23 | +0 (`word[0]`) | 5 | 1 | `[5:5]` | `0x00000020` |
| 24 | +0 (`word[0]`) | 4 | 1 | `[4:4]` | `0x00000010` |
| 25 | +0 (`word[0]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 26 | +0 (`word[0]`) | 2 | 1 | `[2:2]` | `0x00000004` |
| 27 | +0 (`word[0]`) | 1 | 1 | `[1:1]` | `0x00000002` |
| 28 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x080080` — `global_mac_addr0` (Table `0x07`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 8 | 8 | `[15:8]` | `0x0000ff00` |
| 1 | +0 (`word[0]`) | 0 | 8 | `[7:0]` | `0x000000ff` |

### `0x080084` — `global_mac_addr1` (Table `0x08`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 24 | 8 | `[31:24]` | `0xff000000` |
| 1 | +0 (`word[0]`) | 16 | 8 | `[23:16]` | `0x00ff0000` |
| 2 | +0 (`word[0]`) | 8 | 8 | `[15:8]` | `0x0000ff00` |
| 3 | +0 (`word[0]`) | 0 | 8 | `[7:0]` | `0x000000ff` |

### `0x080088` — `eee_ctrl` (Table `0x09`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 24 | 8 | `[31:24]` | `0xff000000` |
| 1 | +0 (`word[0]`) | 16 | 8 | `[23:16]` | `0x00ff0000` |

### `0x08008c` — `sg_phy` (Table `0x0a`, stride `0x4`, entries: 2)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 7 | 3 | `[9:7]` | `0x00000380` |
| 1 | +0 (`word[0]`) | 5 | 2 | `[6:5]` | `0x00000060` |
| 2 | +0 (`word[0]`) | 4 | 1 | `[4:4]` | `0x00000010` |
| 3 | +0 (`word[0]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 4 | +0 (`word[0]`) | 0 | 3 | `[2:0]` | `0x00000007` |

### `0x080100` — `port_ctrl` (Table `0x0b`, stride `0x4`, entries: 11)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 10 | 1 | `[10:10]` | `0x00000400` |
| 1 | +0 (`word[0]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 2 | +0 (`word[0]`) | 8 | 1 | `[8:8]` | `0x00000100` |
| 3 | +0 (`word[0]`) | 7 | 1 | `[7:7]` | `0x00000080` |
| 4 | +0 (`word[0]`) | 6 | 1 | `[6:6]` | `0x00000040` |
| 5 | +0 (`word[0]`) | 5 | 1 | `[5:5]` | `0x00000020` |
| 6 | +0 (`word[0]`) | 4 | 1 | `[4:4]` | `0x00000010` |
| 7 | +0 (`word[0]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 8 | +0 (`word[0]`) | 0 | 3 | `[2:0]` | `0x00000007` |

### `0x080200` — `port_status` (Table `0x0c`, stride `0x4`, entries: 11)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 8 | 1 | `[8:8]` | `0x00000100` |
| 1 | +0 (`word[0]`) | 7 | 1 | `[7:7]` | `0x00000080` |
| 2 | +0 (`word[0]`) | 6 | 1 | `[6:6]` | `0x00000040` |
| 3 | +0 (`word[0]`) | 5 | 1 | `[5:5]` | `0x00000020` |
| 4 | +0 (`word[0]`) | 4 | 1 | `[4:4]` | `0x00000010` |
| 5 | +0 (`word[0]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 6 | +0 (`word[0]`) | 0 | 3 | `[2:0]` | `0x00000007` |

### `0x080230` — `loop_detect_top_ctrl` (Table `0x0d`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 26 | 2 | `[27:26]` | `0x0c000000` |
| 1 | +0 (`word[0]`) | 25 | 1 | `[25:25]` | `0x02000000` |
| 2 | +0 (`word[0]`) | 23 | 2 | `[24:23]` | `0x01800000` |
| 3 | +0 (`word[0]`) | 21 | 2 | `[22:21]` | `0x00600000` |
| 4 | +0 (`word[0]`) | 19 | 2 | `[20:19]` | `0x00180000` |
| 5 | +0 (`word[0]`) | 18 | 1 | `[18:18]` | `0x00040000` |
| 6 | +0 (`word[0]`) | 2 | 16 | `[17:2]` | `0x0003fffc` |
| 7 | +0 (`word[0]`) | 1 | 1 | `[1:1]` | `0x00000002` |
| 8 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x080320` — `pon_strap_en` (Table `0x0e`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 26 | 2 | `[27:26]` | `0x0c000000` |

### `0x080324` — `pon_strap_val` (Table `0x0f`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 26 | 2 | `[27:26]` | `0x0c000000` |

### `0x080328` — `pon_strap` (Table `0x10`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 26 | 2 | `[27:26]` | `0x0c000000` |

### `0x080364` — `mdio_polling` (Table `0x11`, stride `0x4`, entries: 2)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 4 | 1 | `[4:4]` | `0x00000010` |
| 1 | +0 (`word[0]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 2 | +0 (`word[0]`) | 0 | 3 | `[2:0]` | `0x00000007` |

### `0x080380` — `oam_dying_gasp` (Table `0x12`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 4 | 1 | `[4:4]` | `0x00000010` |
| 1 | +0 (`word[0]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 2 | +0 (`word[0]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 3 | +0 (`word[0]`) | 26 | 2 | `[27:26]` | `0x0c000000` |
| 4 | +0 (`word[0]`) | 25 | 1 | `[25:25]` | `0x02000000` |

### `0x080384` — `acl2gpio` (Table `0x13`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 4 | 1 | `[4:4]` | `0x00000010` |
| 1 | +0 (`word[0]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 2 | +0 (`word[0]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 3 | +0 (`word[0]`) | 26 | 2 | `[27:26]` | `0x0c000000` |

### `0x080400` — `extif0_mode` (Table `0x14`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 29 | 3 | `[31:29]` | `0xe0000000` |
| 1 | +0 (`word[0]`) | 28 | 1 | `[28:28]` | `0x10000000` |
| 2 | +0 (`word[0]`) | 26 | 1 | `[26:26]` | `0x04000000` |
| 3 | +0 (`word[0]`) | 20 | 1 | `[20:20]` | `0x00100000` |
| 4 | +0 (`word[0]`) | 19 | 1 | `[19:19]` | `0x00080000` |
| 5 | +0 (`word[0]`) | 18 | 1 | `[18:18]` | `0x00040000` |
| 6 | +0 (`word[0]`) | 17 | 1 | `[17:17]` | `0x00020000` |
| 7 | +0 (`word[0]`) | 13 | 4 | `[16:13]` | `0x0001e000` |
| 8 | +0 (`word[0]`) | 12 | 1 | `[12:12]` | `0x00001000` |
| 9 | +0 (`word[0]`) | 11 | 1 | `[11:11]` | `0x00000800` |
| 10 | +0 (`word[0]`) | 10 | 1 | `[10:10]` | `0x00000400` |
| 11 | +0 (`word[0]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 12 | +0 (`word[0]`) | 8 | 1 | `[8:8]` | `0x00000100` |
| 13 | +0 (`word[0]`) | 7 | 1 | `[7:7]` | `0x00000080` |
| 14 | +0 (`word[0]`) | 3 | 4 | `[6:3]` | `0x00000078` |
| 15 | +0 (`word[0]`) | 2 | 1 | `[2:2]` | `0x00000004` |
| 16 | +0 (`word[0]`) | 1 | 1 | `[1:1]` | `0x00000002` |
| 17 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x080404` — `extif0_mode2` (Table `0x15`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 29 | 3 | `[31:29]` | `0xe0000000` |
| 1 | +0 (`word[0]`) | 28 | 1 | `[28:28]` | `0x10000000` |
| 2 | +0 (`word[0]`) | 26 | 1 | `[26:26]` | `0x04000000` |
| 3 | +0 (`word[0]`) | 20 | 1 | `[20:20]` | `0x00100000` |

### `0x080408` — `extif1_mode` (Table `0x16`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 29 | 3 | `[31:29]` | `0xe0000000` |
| 1 | +0 (`word[0]`) | 28 | 1 | `[28:28]` | `0x10000000` |
| 2 | +0 (`word[0]`) | 26 | 1 | `[26:26]` | `0x04000000` |
| 3 | +0 (`word[0]`) | 20 | 1 | `[20:20]` | `0x00100000` |
| 4 | +0 (`word[0]`) | 19 | 1 | `[19:19]` | `0x00080000` |
| 5 | +0 (`word[0]`) | 18 | 1 | `[18:18]` | `0x00040000` |
| 6 | +0 (`word[0]`) | 17 | 1 | `[17:17]` | `0x00020000` |
| 7 | +0 (`word[0]`) | 13 | 4 | `[16:13]` | `0x0001e000` |
| 8 | +0 (`word[0]`) | 12 | 1 | `[12:12]` | `0x00001000` |
| 9 | +0 (`word[0]`) | 11 | 1 | `[11:11]` | `0x00000800` |
| 10 | +0 (`word[0]`) | 10 | 1 | `[10:10]` | `0x00000400` |
| 11 | +0 (`word[0]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 12 | +0 (`word[0]`) | 8 | 1 | `[8:8]` | `0x00000100` |
| 13 | +0 (`word[0]`) | 7 | 1 | `[7:7]` | `0x00000080` |
| 14 | +0 (`word[0]`) | 3 | 4 | `[6:3]` | `0x00000078` |
| 15 | +0 (`word[0]`) | 2 | 1 | `[2:2]` | `0x00000004` |
| 16 | +0 (`word[0]`) | 1 | 1 | `[1:1]` | `0x00000002` |
| 17 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x08040c` — `extif1_mode2` (Table `0x17`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 29 | 3 | `[31:29]` | `0xe0000000` |
| 1 | +0 (`word[0]`) | 28 | 1 | `[28:28]` | `0x10000000` |
| 2 | +0 (`word[0]`) | 26 | 1 | `[26:26]` | `0x04000000` |
| 3 | +0 (`word[0]`) | 20 | 1 | `[20:20]` | `0x00100000` |

### `0x210000` — `tpid_profile0` (Table `0x18`, stride `0x4`, entries: 2)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 16 | `[15:0]` | `0x0000ffff` |

### `0x210008` — `tpid_profile1` (Table `0x19`, stride `0x4`, entries: 2)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 16 | `[15:0]` | `0x0000ffff` |

### `0x210010` — `parser_port_ctrln` (Table `0x1a`, stride `0x4`, entries: 11)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 4 | 4 | `[7:4]` | `0x000000f0` |
| 1 | +0 (`word[0]`) | 0 | 4 | `[3:0]` | `0x0000000f` |

### `0x210090` — `link_agg_hash_ctrl` (Table `0x1b`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 8 | `[7:0]` | `0x000000ff` |

### `0x210094` — `udf_ctrln` (Table `0x1c`, stride `0x4`, entries: 16)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 7 | 2 | `[8:7]` | `0x00000180` |
| 1 | +0 (`word[0]`) | 0 | 7 | `[6:0]` | `0x0000007f` |

### `0x2100d4` — `parser_erp_oui` (Table `0x1d`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 7 | 2 | `[8:7]` | `0x00000180` |

### `0x2100d8` — `parser_erp_ethtype` (Table `0x1e`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 7 | 2 | `[8:7]` | `0x00000180` |

### `0x2100dc` — `parser_erp_udf_ctrl` (Table `0x1f`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 7 | 2 | `[8:7]` | `0x00000180` |

### `0x2100e0` — `parser_erp_udfn` (Table `0x20`, stride `0x4`, entries: 4)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 7 | 2 | `[8:7]` | `0x00000180` |
| 1 | +0 (`word[0]`) | 0 | 7 | `[6:0]` | `0x0000007f` |
| 2 | +0 (`word[0]`) | 0 | 8 | `[7:0]` | `0x000000ff` |

### `0x2100f0` — `dos_tcp_flags0` (Table `0x21`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 17 | 1 | `[17:17]` | `0x00020000` |
| 1 | +0 (`word[0]`) | 16 | 1 | `[16:16]` | `0x00010000` |
| 2 | +0 (`word[0]`) | 10 | 6 | `[15:10]` | `0x0000fc00` |
| 3 | +0 (`word[0]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 4 | +0 (`word[0]`) | 8 | 1 | `[8:8]` | `0x00000100` |
| 5 | +0 (`word[0]`) | 2 | 6 | `[7:2]` | `0x000000fc` |
| 6 | +0 (`word[0]`) | 1 | 1 | `[1:1]` | `0x00000002` |
| 7 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x2100f4` — `dos_tcp_flags1` (Table `0x22`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 17 | 1 | `[17:17]` | `0x00020000` |
| 1 | +0 (`word[0]`) | 16 | 1 | `[16:16]` | `0x00010000` |
| 2 | +0 (`word[0]`) | 10 | 6 | `[15:10]` | `0x0000fc00` |
| 3 | +0 (`word[0]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 4 | +0 (`word[0]`) | 8 | 1 | `[8:8]` | `0x00000100` |
| 5 | +0 (`word[0]`) | 2 | 6 | `[7:2]` | `0x000000fc` |
| 6 | +0 (`word[0]`) | 1 | 1 | `[1:1]` | `0x00000002` |
| 7 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x2100f8` — `dos_tcp_flags2` (Table `0x23`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 17 | 1 | `[17:17]` | `0x00020000` |
| 1 | +0 (`word[0]`) | 16 | 1 | `[16:16]` | `0x00010000` |
| 2 | +0 (`word[0]`) | 10 | 6 | `[15:10]` | `0x0000fc00` |
| 3 | +0 (`word[0]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 4 | +0 (`word[0]`) | 8 | 1 | `[8:8]` | `0x00000100` |
| 5 | +0 (`word[0]`) | 2 | 6 | `[7:2]` | `0x000000fc` |
| 6 | +0 (`word[0]`) | 1 | 1 | `[1:1]` | `0x00000002` |
| 7 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x2100fc` — `dos_tcp_flags3` (Table `0x24`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 17 | 1 | `[17:17]` | `0x00020000` |
| 1 | +0 (`word[0]`) | 16 | 1 | `[16:16]` | `0x00010000` |
| 2 | +0 (`word[0]`) | 10 | 6 | `[15:10]` | `0x0000fc00` |
| 3 | +0 (`word[0]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 4 | +0 (`word[0]`) | 8 | 1 | `[8:8]` | `0x00000100` |
| 5 | +0 (`word[0]`) | 2 | 6 | `[7:2]` | `0x000000fc` |
| 6 | +0 (`word[0]`) | 1 | 1 | `[1:1]` | `0x00000002` |
| 7 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x210100` — `dos_tcp_flags4` (Table `0x25`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 17 | 1 | `[17:17]` | `0x00020000` |
| 1 | +0 (`word[0]`) | 16 | 1 | `[16:16]` | `0x00010000` |
| 2 | +0 (`word[0]`) | 10 | 6 | `[15:10]` | `0x0000fc00` |
| 3 | +0 (`word[0]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 4 | +0 (`word[0]`) | 8 | 1 | `[8:8]` | `0x00000100` |
| 5 | +0 (`word[0]`) | 2 | 6 | `[7:2]` | `0x000000fc` |
| 6 | +0 (`word[0]`) | 1 | 1 | `[1:1]` | `0x00000002` |
| 7 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x210104` — `dos_tcp_flags5` (Table `0x26`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 17 | 1 | `[17:17]` | `0x00020000` |
| 1 | +0 (`word[0]`) | 16 | 1 | `[16:16]` | `0x00010000` |
| 2 | +0 (`word[0]`) | 10 | 6 | `[15:10]` | `0x0000fc00` |
| 3 | +0 (`word[0]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 4 | +0 (`word[0]`) | 8 | 1 | `[8:8]` | `0x00000100` |
| 5 | +0 (`word[0]`) | 2 | 6 | `[7:2]` | `0x000000fc` |
| 6 | +0 (`word[0]`) | 1 | 1 | `[1:1]` | `0x00000002` |
| 7 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x210108` — `dos_ctrl` (Table `0x27`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 29 | 1 | `[29:29]` | `0x20000000` |
| 1 | +0 (`word[0]`) | 18 | 11 | `[28:18]` | `0x1ffc0000` |
| 2 | +0 (`word[0]`) | 17 | 1 | `[17:17]` | `0x00020000` |
| 3 | +0 (`word[0]`) | 16 | 1 | `[16:16]` | `0x00010000` |
| 4 | +0 (`word[0]`) | 15 | 1 | `[15:15]` | `0x00008000` |
| 5 | +0 (`word[0]`) | 14 | 1 | `[14:14]` | `0x00004000` |
| 6 | +0 (`word[0]`) | 13 | 1 | `[13:13]` | `0x00002000` |
| 7 | +0 (`word[0]`) | 12 | 1 | `[12:12]` | `0x00001000` |
| 8 | +0 (`word[0]`) | 11 | 1 | `[11:11]` | `0x00000800` |
| 9 | +0 (`word[0]`) | 10 | 1 | `[10:10]` | `0x00000400` |
| 10 | +0 (`word[0]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 11 | +0 (`word[0]`) | 8 | 1 | `[8:8]` | `0x00000100` |
| 12 | +0 (`word[0]`) | 7 | 1 | `[7:7]` | `0x00000080` |
| 13 | +0 (`word[0]`) | 6 | 1 | `[6:6]` | `0x00000040` |
| 14 | +0 (`word[0]`) | 5 | 1 | `[5:5]` | `0x00000020` |
| 15 | +0 (`word[0]`) | 4 | 1 | `[4:4]` | `0x00000010` |
| 16 | +0 (`word[0]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 17 | +0 (`word[0]`) | 2 | 1 | `[2:2]` | `0x00000004` |
| 18 | +0 (`word[0]`) | 1 | 1 | `[1:1]` | `0x00000002` |
| 19 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x21010c` — `dos_large_icmp_ctrl` (Table `0x28`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 16 | 13 | `[28:16]` | `0x1fff0000` |
| 1 | +0 (`word[0]`) | 0 | 13 | `[12:0]` | `0x00001fff` |

### `0x210110` — `oam_en_ctrl` (Table `0x29`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 11 | `[10:0]` | `0x000007ff` |

### `0x21011c` — `wol_ctrl` (Table `0x2a`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 1 | 16 | `[16:1]` | `0x0001fffe` |
| 1 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x210120` — `dos_ctrl1` (Table `0x2b`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 1 | +0 (`word[0]`) | 2 | 1 | `[2:2]` | `0x00000004` |
| 2 | +0 (`word[0]`) | 1 | 1 | `[1:1]` | `0x00000002` |
| 3 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x230000` — `protocol_based_vlann` (Table `0x2c`, stride `0x4`, entries: 4)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 19 | 1 | `[19:19]` | `0x00080000` |
| 1 | +0 (`word[0]`) | 16 | 3 | `[18:16]` | `0x00070000` |
| 2 | +0 (`word[0]`) | 0 | 16 | `[15:0]` | `0x0000ffff` |

### `0x230010` — `port_vlan_ctrln` (Table `0x2d`, stride `0x4`, entries: 11)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 31 | 1 | `[31:31]` | `0x80000000` |
| 1 | +0 (`word[0]`) | 30 | 1 | `[30:30]` | `0x40000000` |
| 2 | +0 (`word[0]`) | 18 | 12 | `[29:18]` | `0x3ffc0000` |
| 3 | +0 (`word[0]`) | 6 | 12 | `[17:6]` | `0x0003ffc0` |
| 4 | +0 (`word[0]`) | 3 | 3 | `[5:3]` | `0x00000038` |
| 5 | +0 (`word[0]`) | 0 | 3 | `[2:0]` | `0x00000007` |

### `0x230080` — `port_vlan_ctrl1n` (Table `0x2e`, stride `0x4`, entries: 11)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 8 | 1 | `[8:8]` | `0x00000100` |
| 1 | +0 (`word[0]`) | 4 | 4 | `[7:4]` | `0x000000f0` |
| 2 | +0 (`word[0]`) | 2 | 2 | `[3:2]` | `0x0000000c` |
| 3 | +0 (`word[0]`) | 0 | 2 | `[1:0]` | `0x00000003` |

### `0x230108` — `vlan_trans_untag_vid_mode_ctrl` (Table `0x2f`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 22 | `[21:0]` | `0x003fffff` |

### `0x230200` — `vlan_range_profilen` (Table `0x30`, stride `0x10`, entries: 10)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +8 (`word[2]`) | 20 | 12 | `[31:20]` | `0xfff00000` |
| 1 | +8 (`word[2]`) | 8 | 12 | `[19:8]` | `0x000fff00` |
| 2 | +8 (`word[2]`) | 0 | 8 | `[7:0]` | `0x000000ff` |
| 3 | +4 (`word[1]`) | 28 | 4 | `[31:28]` | `0xf0000000` |
| 4 | +4 (`word[1]`) | 16 | 12 | `[27:16]` | `0x0fff0000` |
| 5 | +4 (`word[1]`) | 4 | 12 | `[15:4]` | `0x0000fff0` |
| 6 | +4 (`word[1]`) | 0 | 4 | `[3:0]` | `0x0000000f` |
| 7 | +0 (`word[0]`) | 24 | 8 | `[31:24]` | `0xff000000` |
| 8 | +0 (`word[0]`) | 12 | 12 | `[23:12]` | `0x00fff000` |
| 9 | +0 (`word[0]`) | 0 | 12 | `[11:0]` | `0x00000fff` |

### `0x230300` — `protocol_based_vlan_data_tbl` (Table `0x31`, stride `0x4`, entries: 44)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 26 | 2 | `[27:26]` | `0x0c000000` |
| 1 | +0 (`word[0]`) | 14 | 12 | `[25:14]` | `0x03ffc000` |
| 2 | +0 (`word[0]`) | 12 | 2 | `[13:12]` | `0x00003000` |
| 3 | +0 (`word[0]`) | 0 | 12 | `[11:0]` | `0x00000fff` |

### `0x230400` — `vlan_xlate_action_tbl` (Table `0x32`, stride `0x8`, entries: 64)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 6 | 2 | `[7:6]` | `0x000000c0` |
| 1 | +4 (`word[1]`) | 0 | 6 | `[5:0]` | `0x0000003f` |
| 2 | +0 (`word[0]`) | 26 | 6 | `[31:26]` | `0xfc000000` |
| 3 | +0 (`word[0]`) | 24 | 2 | `[25:24]` | `0x03000000` |
| 4 | +0 (`word[0]`) | 12 | 12 | `[23:12]` | `0x00fff000` |
| 5 | +0 (`word[0]`) | 10 | 2 | `[11:10]` | `0x00000c00` |
| 6 | +0 (`word[0]`) | 7 | 3 | `[9:7]` | `0x00000380` |
| 7 | +0 (`word[0]`) | 6 | 1 | `[6:6]` | `0x00000040` |
| 8 | +0 (`word[0]`) | 4 | 2 | `[5:4]` | `0x00000030` |
| 9 | +0 (`word[0]`) | 1 | 3 | `[3:1]` | `0x0000000e` |
| 10 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x230600` — `vlan_xlate_tbl` (Table `0x33`, stride `0x8`, entries: 64)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 11 | 1 | `[11:11]` | `0x00000800` |
| 1 | +4 (`word[1]`) | 0 | 11 | `[10:0]` | `0x000007ff` |
| 2 | +0 (`word[0]`) | 31 | 1 | `[31:31]` | `0x80000000` |
| 3 | +0 (`word[0]`) | 30 | 1 | `[30:30]` | `0x40000000` |
| 4 | +0 (`word[0]`) | 28 | 2 | `[29:28]` | `0x30000000` |
| 5 | +0 (`word[0]`) | 27 | 1 | `[27:27]` | `0x08000000` |
| 6 | +0 (`word[0]`) | 15 | 12 | `[26:15]` | `0x07ff8000` |
| 7 | +0 (`word[0]`) | 14 | 1 | `[14:14]` | `0x00004000` |
| 8 | +0 (`word[0]`) | 12 | 2 | `[13:12]` | `0x00003000` |
| 9 | +0 (`word[0]`) | 11 | 1 | `[11:11]` | `0x00000800` |
| 10 | +0 (`word[0]`) | 0 | 11 | `[10:0]` | `0x000007ff` |

### `0x201000` — `acl_blk_keep_ctrl` (Table `0x34`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 29 | 3 | `[31:29]` | `0xe0000000` |
| 1 | +0 (`word[0]`) | 28 | 1 | `[28:28]` | `0x10000000` |
| 2 | +0 (`word[0]`) | 25 | 3 | `[27:25]` | `0x0e000000` |
| 3 | +0 (`word[0]`) | 24 | 1 | `[24:24]` | `0x01000000` |
| 4 | +0 (`word[0]`) | 21 | 3 | `[23:21]` | `0x00e00000` |
| 5 | +0 (`word[0]`) | 20 | 1 | `[20:20]` | `0x00100000` |
| 6 | +0 (`word[0]`) | 17 | 3 | `[19:17]` | `0x000e0000` |
| 7 | +0 (`word[0]`) | 16 | 1 | `[16:16]` | `0x00010000` |
| 8 | +0 (`word[0]`) | 13 | 3 | `[15:13]` | `0x0000e000` |
| 9 | +0 (`word[0]`) | 12 | 1 | `[12:12]` | `0x00001000` |
| 10 | +0 (`word[0]`) | 9 | 3 | `[11:9]` | `0x00000e00` |
| 11 | +0 (`word[0]`) | 8 | 1 | `[8:8]` | `0x00000100` |
| 12 | +0 (`word[0]`) | 5 | 3 | `[7:5]` | `0x000000e0` |
| 13 | +0 (`word[0]`) | 4 | 1 | `[4:4]` | `0x00000010` |
| 14 | +0 (`word[0]`) | 1 | 3 | `[3:1]` | `0x0000000e` |
| 15 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x202000` — `acl_port_ctrl` (Table `0x35`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 11 | `[10:0]` | `0x000007ff` |

### `0x202004` — `acl_blk_cmd` (Table `0x36`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 1 | 6 | `[6:1]` | `0x0000007e` |
| 1 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x203000` — `rule_ext_ctrl` (Table `0x37`, stride `0x4`, entries: 48)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 29 | 3 | `[31:29]` | `0xe0000000` |
| 1 | +0 (`word[0]`) | 28 | 1 | `[28:28]` | `0x10000000` |
| 2 | +0 (`word[0]`) | 25 | 3 | `[27:25]` | `0x0e000000` |
| 3 | +0 (`word[0]`) | 24 | 1 | `[24:24]` | `0x01000000` |
| 4 | +0 (`word[0]`) | 21 | 3 | `[23:21]` | `0x00e00000` |
| 5 | +0 (`word[0]`) | 20 | 1 | `[20:20]` | `0x00100000` |
| 6 | +0 (`word[0]`) | 17 | 3 | `[19:17]` | `0x000e0000` |
| 7 | +0 (`word[0]`) | 16 | 1 | `[16:16]` | `0x00010000` |
| 8 | +0 (`word[0]`) | 13 | 3 | `[15:13]` | `0x0000e000` |
| 9 | +0 (`word[0]`) | 12 | 1 | `[12:12]` | `0x00001000` |
| 10 | +0 (`word[0]`) | 9 | 3 | `[11:9]` | `0x00000e00` |
| 11 | +0 (`word[0]`) | 8 | 1 | `[8:8]` | `0x00000100` |
| 12 | +0 (`word[0]`) | 5 | 3 | `[7:5]` | `0x000000e0` |
| 13 | +0 (`word[0]`) | 4 | 1 | `[4:4]` | `0x00000010` |
| 14 | +0 (`word[0]`) | 1 | 3 | `[3:1]` | `0x0000000e` |
| 15 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x204000` — `acl_rule_bin0` (Table `0x38`, stride `0x8`, entries: 48)

### `0x204200` — `acl_rule_bin1` (Table `0x39`, stride `0x8`, entries: 48)

### `0x204400` — `acl_rule_bin2` (Table `0x3a`, stride `0x8`, entries: 48)

### `0x204600` — `acl_rule_bin3` (Table `0x3b`, stride `0x8`, entries: 48)

### `0x204800` — `acl_rule_bin4` (Table `0x3c`, stride `0x8`, entries: 48)

### `0x204a00` — `acl_rule_bin5` (Table `0x3d`, stride `0x8`, entries: 48)

### `0x204c00` — `acl_rule_bin6` (Table `0x3e`, stride `0x8`, entries: 48)

### `0x204e00` — `acl_rule_bin7` (Table `0x3f`, stride `0x8`, entries: 48)

### `0x205000` — `acl_rule_mask_bin0` (Table `0x40`, stride `0x8`, entries: 48)

### `0x205200` — `acl_rule_mask_bin1` (Table `0x41`, stride `0x8`, entries: 48)

### `0x205400` — `acl_rule_mask_bin2` (Table `0x42`, stride `0x8`, entries: 48)

### `0x205600` — `acl_rule_mask_bin3` (Table `0x43`, stride `0x8`, entries: 48)

### `0x205800` — `acl_rule_mask_bin4` (Table `0x44`, stride `0x8`, entries: 48)

### `0x205a00` — `acl_rule_mask_bin5` (Table `0x45`, stride `0x8`, entries: 48)

### `0x205c00` — `acl_rule_mask_bin6` (Table `0x46`, stride `0x8`, entries: 48)

### `0x205e00` — `acl_rule_mask_bin7` (Table `0x47`, stride `0x8`, entries: 48)

### `0x000000` — `mac_da0_rule` (Table `0x48`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 21 | 9 | `[29:21]` | `0x3fe00000` |
| 1 | +4 (`word[1]`) | 10 | 11 | `[20:10]` | `0x001ffc00` |
| 2 | +4 (`word[1]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 3 | +4 (`word[1]`) | 4 | 5 | `[8:4]` | `0x000001f0` |
| 4 | +4 (`word[1]`) | 0 | 4 | `[3:0]` | `0x0000000f` |
| 5 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x000000` — `mac_da0_rule_mask` (Table `0x49`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 0 | 4 | `[3:0]` | `0x0000000f` |
| 1 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x000000` — `mac_da1_sa1_rule` (Table `0x4a`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 21 | 9 | `[29:21]` | `0x3fe00000` |
| 1 | +4 (`word[1]`) | 10 | 11 | `[20:10]` | `0x001ffc00` |
| 2 | +4 (`word[1]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 3 | +4 (`word[1]`) | 4 | 5 | `[8:4]` | `0x000001f0` |
| 4 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 5 | +4 (`word[1]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 6 | +0 (`word[0]`) | 16 | 16 | `[31:16]` | `0xffff0000` |
| 7 | +0 (`word[0]`) | 0 | 16 | `[15:0]` | `0x0000ffff` |

### `0x000000` — `mac_da1_sa1_rule_mask` (Table `0x4b`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 1 | +4 (`word[1]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 2 | +0 (`word[0]`) | 16 | 16 | `[31:16]` | `0xffff0000` |
| 3 | +0 (`word[0]`) | 0 | 16 | `[15:0]` | `0x0000ffff` |

### `0x000000` — `mac_sa0_rule` (Table `0x4c`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 21 | 9 | `[29:21]` | `0x3fe00000` |
| 1 | +4 (`word[1]`) | 10 | 11 | `[20:10]` | `0x001ffc00` |
| 2 | +4 (`word[1]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 3 | +4 (`word[1]`) | 4 | 5 | `[8:4]` | `0x000001f0` |
| 4 | +4 (`word[1]`) | 0 | 4 | `[3:0]` | `0x0000000f` |
| 5 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x000000` — `mac_sa0_rule_mask` (Table `0x4d`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 0 | 4 | `[3:0]` | `0x0000000f` |
| 1 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x000000` — `ipv4_da_rule` (Table `0x4e`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 30 | 1 | `[30:30]` | `0x40000000` |
| 1 | +4 (`word[1]`) | 21 | 9 | `[29:21]` | `0x3fe00000` |
| 2 | +4 (`word[1]`) | 10 | 11 | `[20:10]` | `0x001ffc00` |
| 3 | +4 (`word[1]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 4 | +4 (`word[1]`) | 4 | 5 | `[8:4]` | `0x000001f0` |
| 5 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 6 | +4 (`word[1]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 7 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x000000` — `ipv4_da_rule_mask` (Table `0x4f`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 1 | +4 (`word[1]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 2 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x000000` — `ipv4_sa_rule` (Table `0x50`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 30 | 1 | `[30:30]` | `0x40000000` |
| 1 | +4 (`word[1]`) | 21 | 9 | `[29:21]` | `0x3fe00000` |
| 2 | +4 (`word[1]`) | 10 | 11 | `[20:10]` | `0x001ffc00` |
| 3 | +4 (`word[1]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 4 | +4 (`word[1]`) | 4 | 5 | `[8:4]` | `0x000001f0` |
| 5 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 6 | +4 (`word[1]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 7 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x000000` — `ipv4_sa_rule_mask` (Table `0x51`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 1 | +4 (`word[1]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 2 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x000000` — `l4_port_rule` (Table `0x52`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 31 | 1 | `[31:31]` | `0x80000000` |
| 1 | +4 (`word[1]`) | 30 | 1 | `[30:30]` | `0x40000000` |
| 2 | +4 (`word[1]`) | 21 | 9 | `[29:21]` | `0x3fe00000` |
| 3 | +4 (`word[1]`) | 10 | 11 | `[20:10]` | `0x001ffc00` |
| 4 | +4 (`word[1]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 5 | +4 (`word[1]`) | 4 | 5 | `[8:4]` | `0x000001f0` |
| 6 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 7 | +4 (`word[1]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 8 | +0 (`word[0]`) | 16 | 16 | `[31:16]` | `0xffff0000` |
| 9 | +0 (`word[0]`) | 0 | 16 | `[15:0]` | `0x0000ffff` |

### `0x000000` — `l4_port_rule_mask` (Table `0x53`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 1 | +4 (`word[1]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 2 | +0 (`word[0]`) | 16 | 16 | `[31:16]` | `0xffff0000` |
| 3 | +0 (`word[0]`) | 0 | 16 | `[15:0]` | `0x0000ffff` |

### `0x000000` — `vlan_rule` (Table `0x54`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 31 | 1 | `[31:31]` | `0x80000000` |
| 1 | +4 (`word[1]`) | 30 | 1 | `[30:30]` | `0x40000000` |
| 2 | +4 (`word[1]`) | 21 | 9 | `[29:21]` | `0x3fe00000` |
| 3 | +4 (`word[1]`) | 10 | 11 | `[20:10]` | `0x001ffc00` |
| 4 | +4 (`word[1]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 5 | +4 (`word[1]`) | 4 | 5 | `[8:4]` | `0x000001f0` |
| 6 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 7 | +4 (`word[1]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 8 | +0 (`word[0]`) | 30 | 2 | `[31:30]` | `0xc0000000` |
| 9 | +0 (`word[0]`) | 29 | 1 | `[29:29]` | `0x20000000` |
| 10 | +0 (`word[0]`) | 26 | 3 | `[28:26]` | `0x1c000000` |
| 11 | +0 (`word[0]`) | 24 | 2 | `[25:24]` | `0x03000000` |
| 12 | +0 (`word[0]`) | 12 | 12 | `[23:12]` | `0x00fff000` |
| 13 | +0 (`word[0]`) | 0 | 12 | `[11:0]` | `0x00000fff` |

### `0x000000` — `vlan_rule_mask` (Table `0x55`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 1 | +4 (`word[1]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 2 | +0 (`word[0]`) | 30 | 2 | `[31:30]` | `0xc0000000` |
| 3 | +0 (`word[0]`) | 29 | 1 | `[29:29]` | `0x20000000` |
| 4 | +0 (`word[0]`) | 26 | 3 | `[28:26]` | `0x1c000000` |
| 5 | +0 (`word[0]`) | 24 | 2 | `[25:24]` | `0x03000000` |
| 6 | +0 (`word[0]`) | 12 | 12 | `[23:12]` | `0x00fff000` |
| 7 | +0 (`word[0]`) | 0 | 12 | `[11:0]` | `0x00000fff` |

### `0x000000` — `misc_rule` (Table `0x56`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 21 | 9 | `[29:21]` | `0x3fe00000` |
| 1 | +4 (`word[1]`) | 10 | 11 | `[20:10]` | `0x001ffc00` |
| 2 | +4 (`word[1]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 3 | +4 (`word[1]`) | 4 | 5 | `[8:4]` | `0x000001f0` |
| 4 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 5 | +4 (`word[1]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 6 | +0 (`word[0]`) | 31 | 1 | `[31:31]` | `0x80000000` |
| 7 | +0 (`word[0]`) | 30 | 1 | `[30:30]` | `0x40000000` |
| 8 | +0 (`word[0]`) | 29 | 1 | `[29:29]` | `0x20000000` |
| 9 | +0 (`word[0]`) | 28 | 1 | `[28:28]` | `0x10000000` |
| 10 | +0 (`word[0]`) | 20 | 8 | `[27:20]` | `0x0ff00000` |
| 11 | +0 (`word[0]`) | 12 | 8 | `[19:12]` | `0x000ff000` |
| 12 | +0 (`word[0]`) | 4 | 8 | `[11:4]` | `0x00000ff0` |
| 13 | +0 (`word[0]`) | 0 | 4 | `[3:0]` | `0x0000000f` |

### `0x000000` — `misc_rule_mask` (Table `0x57`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 1 | +4 (`word[1]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 2 | +0 (`word[0]`) | 31 | 1 | `[31:31]` | `0x80000000` |
| 3 | +0 (`word[0]`) | 30 | 1 | `[30:30]` | `0x40000000` |
| 4 | +0 (`word[0]`) | 29 | 1 | `[29:29]` | `0x20000000` |
| 5 | +0 (`word[0]`) | 28 | 1 | `[28:28]` | `0x10000000` |
| 6 | +0 (`word[0]`) | 20 | 8 | `[27:20]` | `0x0ff00000` |
| 7 | +0 (`word[0]`) | 12 | 8 | `[19:12]` | `0x000ff000` |
| 8 | +0 (`word[0]`) | 4 | 8 | `[11:4]` | `0x00000ff0` |
| 9 | +0 (`word[0]`) | 0 | 4 | `[3:0]` | `0x0000000f` |

### `0x000000` — `udf_rule` (Table `0x58`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 21 | 9 | `[29:21]` | `0x3fe00000` |
| 1 | +4 (`word[1]`) | 10 | 11 | `[20:10]` | `0x001ffc00` |
| 2 | +4 (`word[1]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 3 | +4 (`word[1]`) | 4 | 5 | `[8:4]` | `0x000001f0` |
| 4 | +4 (`word[1]`) | 1 | 3 | `[3:1]` | `0x0000000e` |
| 5 | +4 (`word[1]`) | 0 | 1 | `[0:0]` | `0x00000001` |
| 6 | +0 (`word[0]`) | 16 | 16 | `[31:16]` | `0xffff0000` |
| 7 | +0 (`word[0]`) | 0 | 16 | `[15:0]` | `0x0000ffff` |

### `0x000000` — `udf_rule_mask` (Table `0x59`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 1 | 3 | `[3:1]` | `0x0000000e` |
| 1 | +4 (`word[1]`) | 0 | 1 | `[0:0]` | `0x00000001` |
| 2 | +0 (`word[0]`) | 16 | 16 | `[31:16]` | `0xffff0000` |
| 3 | +0 (`word[0]`) | 0 | 16 | `[15:0]` | `0x0000ffff` |

### `0x000000` — `ipv6_da0_rule` (Table `0x5a`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 21 | 9 | `[29:21]` | `0x3fe00000` |
| 1 | +4 (`word[1]`) | 10 | 11 | `[20:10]` | `0x001ffc00` |
| 2 | +4 (`word[1]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 3 | +4 (`word[1]`) | 4 | 5 | `[8:4]` | `0x000001f0` |
| 4 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 5 | +4 (`word[1]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 6 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x000000` — `ipv6_da0_rule_mask` (Table `0x5b`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 1 | +4 (`word[1]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 2 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x000000` — `ipv6_da1_rule` (Table `0x5c`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 21 | 9 | `[29:21]` | `0x3fe00000` |
| 1 | +4 (`word[1]`) | 10 | 11 | `[20:10]` | `0x001ffc00` |
| 2 | +4 (`word[1]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 3 | +4 (`word[1]`) | 4 | 5 | `[8:4]` | `0x000001f0` |
| 4 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 5 | +4 (`word[1]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 6 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x000000` — `ipv6_da1_rule_mask` (Table `0x5d`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 1 | +4 (`word[1]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 2 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x000000` — `ipv6_da2_rule` (Table `0x5e`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 21 | 9 | `[29:21]` | `0x3fe00000` |
| 1 | +4 (`word[1]`) | 10 | 11 | `[20:10]` | `0x001ffc00` |
| 2 | +4 (`word[1]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 3 | +4 (`word[1]`) | 4 | 5 | `[8:4]` | `0x000001f0` |
| 4 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 5 | +4 (`word[1]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 6 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x000000` — `ipv6_da2_rule_mask` (Table `0x5f`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 1 | +4 (`word[1]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 2 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x000000` — `ipv6_da3_rule` (Table `0x60`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 30 | 1 | `[30:30]` | `0x40000000` |
| 1 | +4 (`word[1]`) | 21 | 9 | `[29:21]` | `0x3fe00000` |
| 2 | +4 (`word[1]`) | 10 | 11 | `[20:10]` | `0x001ffc00` |
| 3 | +4 (`word[1]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 4 | +4 (`word[1]`) | 4 | 5 | `[8:4]` | `0x000001f0` |
| 5 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 6 | +4 (`word[1]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 7 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x000000` — `ipv6_da3_rule_mask` (Table `0x61`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 1 | +4 (`word[1]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 2 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x000000` — `ipv6_sa0_rule` (Table `0x62`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 21 | 9 | `[29:21]` | `0x3fe00000` |
| 1 | +4 (`word[1]`) | 10 | 11 | `[20:10]` | `0x001ffc00` |
| 2 | +4 (`word[1]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 3 | +4 (`word[1]`) | 4 | 5 | `[8:4]` | `0x000001f0` |
| 4 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 5 | +4 (`word[1]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 6 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x000000` — `ipv6_sa0_rule_mask` (Table `0x63`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 1 | +4 (`word[1]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 2 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x000000` — `ipv6_sa1_rule` (Table `0x64`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 21 | 9 | `[29:21]` | `0x3fe00000` |
| 1 | +4 (`word[1]`) | 10 | 11 | `[20:10]` | `0x001ffc00` |
| 2 | +4 (`word[1]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 3 | +4 (`word[1]`) | 4 | 5 | `[8:4]` | `0x000001f0` |
| 4 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 5 | +4 (`word[1]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 6 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x000000` — `ipv6_sa1_rule_mask` (Table `0x65`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 1 | +4 (`word[1]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 2 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x000000` — `ipv6_sa2_rule` (Table `0x66`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 21 | 9 | `[29:21]` | `0x3fe00000` |
| 1 | +4 (`word[1]`) | 10 | 11 | `[20:10]` | `0x001ffc00` |
| 2 | +4 (`word[1]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 3 | +4 (`word[1]`) | 4 | 5 | `[8:4]` | `0x000001f0` |
| 4 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 5 | +4 (`word[1]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 6 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x000000` — `ipv6_sa2_rule_mask` (Table `0x67`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 1 | +4 (`word[1]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 2 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x000000` — `ipv6_sa3_rule` (Table `0x68`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 30 | 1 | `[30:30]` | `0x40000000` |
| 1 | +4 (`word[1]`) | 21 | 9 | `[29:21]` | `0x3fe00000` |
| 2 | +4 (`word[1]`) | 10 | 11 | `[20:10]` | `0x001ffc00` |
| 3 | +4 (`word[1]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 4 | +4 (`word[1]`) | 4 | 5 | `[8:4]` | `0x000001f0` |
| 5 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 6 | +4 (`word[1]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 7 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x000000` — `ipv6_sa3_rule_mask` (Table `0x69`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 1 | +4 (`word[1]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 2 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x000000` — `vid_pri_dei_rule` (Table `0x6a`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 31 | 1 | `[31:31]` | `0x80000000` |
| 1 | +4 (`word[1]`) | 30 | 1 | `[30:30]` | `0x40000000` |
| 2 | +4 (`word[1]`) | 21 | 9 | `[29:21]` | `0x3fe00000` |
| 3 | +4 (`word[1]`) | 10 | 11 | `[20:10]` | `0x001ffc00` |
| 4 | +4 (`word[1]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 5 | +4 (`word[1]`) | 4 | 5 | `[8:4]` | `0x000001f0` |
| 6 | +4 (`word[1]`) | 0 | 4 | `[3:0]` | `0x0000000f` |
| 7 | +0 (`word[0]`) | 31 | 1 | `[31:31]` | `0x80000000` |
| 8 | +0 (`word[0]`) | 28 | 3 | `[30:28]` | `0x70000000` |
| 9 | +0 (`word[0]`) | 27 | 1 | `[27:27]` | `0x08000000` |
| 10 | +0 (`word[0]`) | 24 | 3 | `[26:24]` | `0x07000000` |
| 11 | +0 (`word[0]`) | 12 | 12 | `[23:12]` | `0x00fff000` |
| 12 | +0 (`word[0]`) | 0 | 12 | `[11:0]` | `0x00000fff` |

### `0x000000` — `vid_pri_dei_rule_mask` (Table `0x6b`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 31 | 1 | `[31:31]` | `0x80000000` |
| 1 | +0 (`word[0]`) | 28 | 3 | `[30:28]` | `0x70000000` |
| 2 | +0 (`word[0]`) | 27 | 1 | `[27:27]` | `0x08000000` |
| 3 | +0 (`word[0]`) | 24 | 3 | `[26:24]` | `0x07000000` |
| 4 | +0 (`word[0]`) | 12 | 12 | `[23:12]` | `0x00fff000` |
| 5 | +0 (`word[0]`) | 0 | 12 | `[11:0]` | `0x00000fff` |

### `0x000000` — `ether_type_value_rule` (Table `0x6c`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 30 | 1 | `[30:30]` | `0x40000000` |
| 1 | +4 (`word[1]`) | 21 | 9 | `[29:21]` | `0x3fe00000` |
| 2 | +4 (`word[1]`) | 10 | 11 | `[20:10]` | `0x001ffc00` |
| 3 | +4 (`word[1]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 4 | +4 (`word[1]`) | 4 | 5 | `[8:4]` | `0x000001f0` |
| 5 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 6 | +4 (`word[1]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 7 | +0 (`word[0]`) | 16 | 16 | `[31:16]` | `0xffff0000` |
| 8 | +0 (`word[0]`) | 0 | 16 | `[15:0]` | `0x0000ffff` |

### `0x000000` — `ether_type_value_rule_mask` (Table `0x6d`, stride `0x8`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 1 | +4 (`word[1]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 2 | +0 (`word[0]`) | 16 | 16 | `[31:16]` | `0xffff0000` |
| 3 | +0 (`word[0]`) | 0 | 16 | `[15:0]` | `0x0000ffff` |

### `0x180000` — `dscp_to_int_prio_map` (Table `0x6e`, stride `0x4`, entries: 64)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 2 | 3 | `[4:2]` | `0x0000001c` |
| 1 | +0 (`word[0]`) | 0 | 2 | `[1:0]` | `0x00000003` |

### `0x180100` — `pri_to_int_prio_map` (Table `0x6f`, stride `0x4`, entries: 32)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 2 | 3 | `[4:2]` | `0x0000001c` |
| 1 | +0 (`word[0]`) | 0 | 2 | `[1:0]` | `0x00000003` |

### `0x180180` — `qos_port_ctrln` (Table `0x70`, stride `0x4`, entries: 11)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 5 | 1 | `[5:5]` | `0x00000020` |
| 1 | +0 (`word[0]`) | 4 | 1 | `[4:4]` | `0x00000010` |
| 2 | +0 (`word[0]`) | 1 | 3 | `[3:1]` | `0x0000000e` |
| 3 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x180200` — `qos_merge_precedence_ctrln` (Table `0x71`, stride `0x4`, entries: 11)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 21 | 3 | `[23:21]` | `0x00e00000` |
| 1 | +0 (`word[0]`) | 18 | 3 | `[20:18]` | `0x001c0000` |
| 2 | +0 (`word[0]`) | 15 | 3 | `[17:15]` | `0x00038000` |
| 3 | +0 (`word[0]`) | 12 | 3 | `[14:12]` | `0x00007000` |
| 4 | +0 (`word[0]`) | 9 | 3 | `[11:9]` | `0x00000e00` |
| 5 | +0 (`word[0]`) | 6 | 3 | `[8:6]` | `0x000001c0` |
| 6 | +0 (`word[0]`) | 3 | 3 | `[5:3]` | `0x00000038` |
| 7 | +0 (`word[0]`) | 0 | 3 | `[2:0]` | `0x00000007` |

### `0x180270` — `hdr_err_action` (Table `0x72`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 21 | 3 | `[23:21]` | `0x00e00000` |
| 1 | +0 (`word[0]`) | 18 | 3 | `[20:18]` | `0x001c0000` |

### `0x180280` — `l2_vlan_ingress_filter_en` (Table `0x73`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 11 | 11 | `[21:11]` | `0x003ff800` |
| 1 | +0 (`word[0]`) | 0 | 11 | `[10:0]` | `0x000007ff` |

### `0x180284` — `l2_arp_bcast_per_port_ctrl` (Table `0x74`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 11 | 11 | `[21:11]` | `0x003ff800` |
| 1 | +0 (`word[0]`) | 0 | 11 | `[10:0]` | `0x000007ff` |

### `0x180288` — `l2_nd_per_port_ctrl` (Table `0x75`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 11 | 11 | `[21:11]` | `0x003ff800` |
| 1 | +0 (`word[0]`) | 0 | 11 | `[10:0]` | `0x000007ff` |

### `0x18028c` — `l2_lldp_eee_per_port_ctrl` (Table `0x76`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 11 | 11 | `[21:11]` | `0x003ff800` |
| 1 | +0 (`word[0]`) | 0 | 11 | `[10:0]` | `0x000007ff` |

### `0x180290` — `l2_lldp_per_port_ctrl` (Table `0x77`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 11 | 11 | `[21:11]` | `0x003ff800` |
| 1 | +0 (`word[0]`) | 0 | 11 | `[10:0]` | `0x000007ff` |

### `0x180294` — `l2_port_isolation_ctrln` (Table `0x78`, stride `0x4`, entries: 11)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 11 | `[10:0]` | `0x000007ff` |

### `0x18030c` — `l2_erp_per_port_ctrl` (Table `0x79`, stride `0x4`, entries: 11)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 11 | `[10:0]` | `0x000007ff` |
| 1 | +0 (`word[0]`) | 11 | 11 | `[21:11]` | `0x003ff800` |
| 2 | +0 (`word[0]`) | 0 | 11 | `[10:0]` | `0x000007ff` |
| 3 | +0 (`word[0]`) | 11 | 11 | `[21:11]` | `0x003ff800` |
| 4 | +0 (`word[0]`) | 0 | 11 | `[10:0]` | `0x000007ff` |

### `0x18038c` — `l2_stp_staten` (Table `0x7a`, stride `0x4`, entries: 16)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 22 | `[21:0]` | `0x003fffff` |

### `0x1803cc` — `l2_src_match_ctrl` (Table `0x7b`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 11 | `[10:0]` | `0x000007ff` |

### `0x1803d0` — `l2_learn_per_port_ctrln` (Table `0x7c`, stride `0x4`, entries: 11)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 22 | 1 | `[22:22]` | `0x00400000` |
| 1 | +0 (`word[0]`) | 21 | 1 | `[21:21]` | `0x00200000` |
| 2 | +0 (`word[0]`) | 20 | 1 | `[20:20]` | `0x00100000` |
| 3 | +0 (`word[0]`) | 19 | 1 | `[19:19]` | `0x00080000` |
| 4 | +0 (`word[0]`) | 18 | 1 | `[18:18]` | `0x00040000` |
| 5 | +0 (`word[0]`) | 17 | 1 | `[17:17]` | `0x00020000` |
| 6 | +0 (`word[0]`) | 16 | 1 | `[16:16]` | `0x00010000` |
| 7 | +0 (`word[0]`) | 3 | 13 | `[15:3]` | `0x0000fff8` |
| 8 | +0 (`word[0]`) | 2 | 1 | `[2:2]` | `0x00000004` |
| 9 | +0 (`word[0]`) | 0 | 2 | `[1:0]` | `0x00000003` |

### `0x1803fc` — `l2_station_move_ctrl0` (Table `0x7d`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 22 | 1 | `[22:22]` | `0x00400000` |
| 1 | +0 (`word[0]`) | 21 | 1 | `[21:21]` | `0x00200000` |

### `0x180400` — `l2_station_move_ctrl1` (Table `0x7e`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 22 | 1 | `[22:22]` | `0x00400000` |

### `0x180404` — `l2_port_learn_mac_cntn` (Table `0x7f`, stride `0x4`, entries: 13)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 13 | `[12:0]` | `0x00001fff` |

### `0x180438` — `l2_learn_global_ctrl` (Table `0x80`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 17 | 2 | `[18:17]` | `0x00060000` |
| 1 | +0 (`word[0]`) | 16 | 1 | `[16:16]` | `0x00010000` |
| 2 | +0 (`word[0]`) | 15 | 1 | `[15:15]` | `0x00008000` |
| 3 | +0 (`word[0]`) | 14 | 1 | `[14:14]` | `0x00004000` |
| 4 | +0 (`word[0]`) | 1 | 13 | `[13:1]` | `0x00003ffe` |
| 5 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x18043c` — `l2_learn_mac_cnt` (Table `0x81`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 13 | `[12:0]` | `0x00001fff` |

### `0x180440` — `l2_aging_ctrl` (Table `0x82`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 16 | `[15:0]` | `0x0000ffff` |

### `0x180448` — `l2_aging_per_port_ctrl` (Table `0x83`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 11 | `[10:0]` | `0x000007ff` |

### `0x180454` — `l2_fdb_tbl_op_data_0` (Table `0x84`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x180458` — `l2_fdb_tbl_op_data_1` (Table `0x85`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 31 | 1 | `[31:31]` | `0x80000000` |
| 1 | +0 (`word[0]`) | 28 | 3 | `[30:28]` | `0x70000000` |
| 2 | +0 (`word[0]`) | 16 | 12 | `[27:16]` | `0x0fff0000` |
| 3 | +0 (`word[0]`) | 0 | 16 | `[15:0]` | `0x0000ffff` |

### `0x18045c` — `l2_fdb_tbl_op_data_2` (Table `0x86`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 30 | 2 | `[31:30]` | `0xc0000000` |
| 1 | +0 (`word[0]`) | 29 | 1 | `[29:29]` | `0x20000000` |
| 2 | +0 (`word[0]`) | 18 | 11 | `[28:18]` | `0x1ffc0000` |
| 3 | +0 (`word[0]`) | 17 | 1 | `[17:17]` | `0x00020000` |
| 4 | +0 (`word[0]`) | 16 | 1 | `[16:16]` | `0x00010000` |
| 5 | +0 (`word[0]`) | 15 | 1 | `[15:15]` | `0x00008000` |
| 6 | +0 (`word[0]`) | 12 | 3 | `[14:12]` | `0x00007000` |
| 7 | +0 (`word[0]`) | 0 | 12 | `[11:0]` | `0x00000fff` |

### `0x180460` — `l2_fdb_tbl_op` (Table `0x87`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 11 | 12 | `[22:11]` | `0x007ff800` |
| 1 | +0 (`word[0]`) | 10 | 1 | `[10:10]` | `0x00000400` |
| 2 | +0 (`word[0]`) | 7 | 3 | `[9:7]` | `0x00000380` |
| 3 | +0 (`word[0]`) | 6 | 1 | `[6:6]` | `0x00000040` |
| 4 | +0 (`word[0]`) | 4 | 2 | `[5:4]` | `0x00000030` |
| 5 | +0 (`word[0]`) | 1 | 3 | `[3:1]` | `0x0000000e` |
| 6 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x180464` — `l2_fdb_tbl_op_result` (Table `0x88`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 15 | 1 | `[15:15]` | `0x00008000` |
| 1 | +0 (`word[0]`) | 14 | 1 | `[14:14]` | `0x00004000` |
| 2 | +0 (`word[0]`) | 13 | 1 | `[13:13]` | `0x00002000` |
| 3 | +0 (`word[0]`) | 12 | 1 | `[12:12]` | `0x00001000` |
| 4 | +0 (`word[0]`) | 0 | 12 | `[11:0]` | `0x00000fff` |

### `0x180468` — `l2_igmp_static_router_port_mask` (Table `0x89`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 11 | `[10:0]` | `0x000007ff` |

### `0x18046c` — `l2_igmp_dynamic_router_port_ctrl` (Table `0x8a`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 4 | 11 | `[14:4]` | `0x00007ff0` |
| 1 | +0 (`word[0]`) | 0 | 4 | `[3:0]` | `0x0000000f` |

### `0x180470` — `l2_igmp_dynamic_router_port` (Table `0x8b`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 4 | 11 | `[14:4]` | `0x00007ff0` |
| 1 | +0 (`word[0]`) | 0 | 4 | `[3:0]` | `0x0000000f` |

### `0x180474` — `l2_igmp_dynamic_router_port0_timer` (Table `0x8c`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 4 | 11 | `[14:4]` | `0x00007ff0` |

### `0x180478` — `l2_igmp_dynamic_router_port1_timer` (Table `0x8d`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 4 | 11 | `[14:4]` | `0x00007ff0` |

### `0x18047c` — `l2_igmp_global_ctrl` (Table `0x8e`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 11 | 1 | `[11:11]` | `0x00000800` |
| 1 | +0 (`word[0]`) | 10 | 1 | `[10:10]` | `0x00000400` |
| 2 | +0 (`word[0]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 3 | +0 (`word[0]`) | 7 | 2 | `[8:7]` | `0x00000180` |
| 4 | +0 (`word[0]`) | 5 | 2 | `[6:5]` | `0x00000060` |
| 5 | +0 (`word[0]`) | 4 | 1 | `[4:4]` | `0x00000010` |
| 6 | +0 (`word[0]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 7 | +0 (`word[0]`) | 2 | 1 | `[2:2]` | `0x00000004` |
| 8 | +0 (`word[0]`) | 1 | 1 | `[1:1]` | `0x00000002` |
| 9 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x180480` — `l2_igmp_per_port_ctrl` (Table `0x8f`, stride `0x4`, entries: 11)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 7 | 1 | `[7:7]` | `0x00000080` |
| 1 | +0 (`word[0]`) | 6 | 1 | `[6:6]` | `0x00000040` |
| 2 | +0 (`word[0]`) | 5 | 1 | `[5:5]` | `0x00000020` |
| 3 | +0 (`word[0]`) | 4 | 1 | `[4:4]` | `0x00000010` |
| 4 | +0 (`word[0]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 5 | +0 (`word[0]`) | 2 | 1 | `[2:2]` | `0x00000004` |
| 6 | +0 (`word[0]`) | 1 | 1 | `[1:1]` | `0x00000002` |
| 7 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x1804b0` — `l2_fdb_tbl_op_data_0_dummy` (Table `0x90`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x1804b4` — `l2_fdb_tbl_op_data_1_dummy` (Table `0x91`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 31 | 1 | `[31:31]` | `0x80000000` |
| 1 | +0 (`word[0]`) | 28 | 3 | `[30:28]` | `0x70000000` |
| 2 | +0 (`word[0]`) | 16 | 12 | `[27:16]` | `0x0fff0000` |
| 3 | +0 (`word[0]`) | 0 | 16 | `[15:0]` | `0x0000ffff` |

### `0x1804b8` — `l2_fdb_tbl_op_data_2_dummy` (Table `0x92`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 30 | 2 | `[31:30]` | `0xc0000000` |
| 1 | +0 (`word[0]`) | 29 | 1 | `[29:29]` | `0x20000000` |
| 2 | +0 (`word[0]`) | 18 | 11 | `[28:18]` | `0x1ffc0000` |
| 3 | +0 (`word[0]`) | 17 | 1 | `[17:17]` | `0x00020000` |
| 4 | +0 (`word[0]`) | 16 | 1 | `[16:16]` | `0x00010000` |
| 5 | +0 (`word[0]`) | 15 | 1 | `[15:15]` | `0x00008000` |
| 6 | +0 (`word[0]`) | 12 | 3 | `[14:12]` | `0x00007000` |
| 7 | +0 (`word[0]`) | 0 | 12 | `[11:0]` | `0x00000fff` |

### `0x1804bc` — `l2_igmp_dynamic_router_port_dummy` (Table `0x93`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 4 | 4 | `[7:4]` | `0x000000f0` |
| 1 | +0 (`word[0]`) | 0 | 4 | `[3:0]` | `0x0000000f` |

### `0x1804c0` — `l2_igmp_dynamic_router_port0_timer_dummy` (Table `0x94`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 4 | 4 | `[7:4]` | `0x000000f0` |

### `0x1804c4` — `l2_igmp_dynamic_router_port1_timer_dummy` (Table `0x95`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 4 | 4 | `[7:4]` | `0x000000f0` |

### `0x180500` — `l2_igmp_learn_ctrl` (Table `0x96`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 13 | 1 | `[13:13]` | `0x00002000` |
| 1 | +0 (`word[0]`) | 0 | 13 | `[12:0]` | `0x00001fff` |

### `0x180504` — `l2_igmp_learn_group_cnt` (Table `0x97`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 13 | `[12:0]` | `0x00001fff` |

### `0x180508` — `l2_unknown_ucast_filter_mask` (Table `0x98`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 11 | `[10:0]` | `0x000007ff` |

### `0x18050c` — `l2_unknown_mcast_filter_mask` (Table `0x99`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 11 | `[10:0]` | `0x000007ff` |

### `0x180510` — `l2_mcast_filter_mask` (Table `0x9a`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 11 | `[10:0]` | `0x000007ff` |

### `0x180514` — `l2_bcast_filter_mask` (Table `0x9b`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 11 | `[10:0]` | `0x000007ff` |

### `0x180518` — `l2_port_vlan_transparent_ctrl` (Table `0x9c`, stride `0x4`, entries: 11)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 11 | `[10:0]` | `0x000007ff` |

### `0x180598` — `l2_egr_vlan_filter_en` (Table `0x9d`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 11 | `[10:0]` | `0x000007ff` |

### `0x18059c` — `l2_dot1x_ctrl1` (Table `0x9e`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 11 | `[10:0]` | `0x000007ff` |

### `0x1805a0` — `l2_dot1x_ctrl2` (Table `0x9f`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 25 | 1 | `[25:25]` | `0x02000000` |
| 1 | +0 (`word[0]`) | 24 | 1 | `[24:24]` | `0x01000000` |
| 2 | +0 (`word[0]`) | 23 | 1 | `[23:23]` | `0x00800000` |
| 3 | +0 (`word[0]`) | 22 | 1 | `[22:22]` | `0x00400000` |
| 4 | +0 (`word[0]`) | 11 | 11 | `[21:11]` | `0x003ff800` |
| 5 | +0 (`word[0]`) | 0 | 11 | `[10:0]` | `0x000007ff` |

### `0x1805a4` — `ipmc_leaky_ctrl` (Table `0xa0`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 1 | 1 | `[1:1]` | `0x00000002` |
| 1 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x1805a8` — `link_agg_groupn` (Table `0xa1`, stride `0x4`, entries: 2)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 3 | 11 | `[13:3]` | `0x00003ff8` |
| 1 | +0 (`word[0]`) | 0 | 3 | `[2:0]` | `0x00000007` |

### `0x1805b0` — `link_agg_membern` (Table `0xa2`, stride `0x4`, entries: 8)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 4 | `[3:0]` | `0x0000000f` |

### `0x1805d0` — `rma_ctrln` (Table `0xa3`, stride `0x4`, entries: 48)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 12 | 1 | `[12:12]` | `0x00001000` |
| 1 | +0 (`word[0]`) | 11 | 1 | `[11:11]` | `0x00000800` |
| 2 | +0 (`word[0]`) | 10 | 1 | `[10:10]` | `0x00000400` |
| 3 | +0 (`word[0]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 4 | +0 (`word[0]`) | 8 | 1 | `[8:8]` | `0x00000100` |
| 5 | +0 (`word[0]`) | 7 | 1 | `[7:7]` | `0x00000080` |
| 6 | +0 (`word[0]`) | 6 | 1 | `[6:6]` | `0x00000040` |
| 7 | +0 (`word[0]`) | 0 | 6 | `[5:0]` | `0x0000003f` |

### `0x180690` — `cpu_copy_dst_ctrl` (Table `0xa4`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 2 | 1 | `[2:2]` | `0x00000004` |
| 1 | +0 (`word[0]`) | 1 | 1 | `[1:1]` | `0x00000002` |
| 2 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x1806a0` — `acl_unmatch_permit_enable_ctrl` (Table `0xa5`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 11 | `[10:0]` | `0x000007ff` |

### `0x1806ac` — `oam_mux_act` (Table `0xa6`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 22 | `[21:0]` | `0x003fffff` |

### `0x1806b0` — `oam_par_act` (Table `0xa7`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 1 | 22 | `[22:1]` | `0x007ffffe` |
| 1 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x1806b4` — `cascade_ctrl` (Table `0xa8`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 5 | 4 | `[8:5]` | `0x000001e0` |
| 1 | +0 (`word[0]`) | 1 | 4 | `[4:1]` | `0x0000001e` |
| 2 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x1806b8` — `loop_detect_act_ctrl` (Table `0xa9`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 5 | 4 | `[8:5]` | `0x000001e0` |

### `0x1806bc` — `igmp_router_port_aging_ctrl` (Table `0xaa`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 8 | `[7:0]` | `0x000000ff` |

### `0x180700` — `multi_vlan_tbl` (Table `0xab`, stride `0x4`, entries: 8)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 14 | 12 | `[25:14]` | `0x03ffc000` |
| 1 | +0 (`word[0]`) | 13 | 1 | `[13:13]` | `0x00002000` |
| 2 | +0 (`word[0]`) | 1 | 12 | `[12:1]` | `0x00001ffe` |
| 3 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x180730` — `l2_learn_clear_op` (Table `0xac`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 14 | 12 | `[25:14]` | `0x03ffc000` |
| 1 | +0 (`word[0]`) | 13 | 1 | `[13:13]` | `0x00002000` |
| 2 | +0 (`word[0]`) | 1 | 12 | `[12:1]` | `0x00001ffe` |
| 3 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |
| 4 | +0 (`word[0]`) | 0 | 8 | `[7:0]` | `0x000000ff` |

### `0x180734` — `l2_uc_unknown_act_ctrl` (Table `0xad`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 22 | `[21:0]` | `0x003fffff` |

### `0x180738` — `l2_mc_unknown_act_ctrl` (Table `0xae`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 23 | 1 | `[23:23]` | `0x00800000` |
| 1 | +0 (`word[0]`) | 22 | 1 | `[22:22]` | `0x00400000` |
| 2 | +0 (`word[0]`) | 0 | 22 | `[21:0]` | `0x003fffff` |

### `0x180808` — `l2_lag_learn_limit_ctrln` (Table `0xaf`, stride `0x4`, entries: 2)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 14 | 1 | `[14:14]` | `0x00004000` |
| 1 | +0 (`word[0]`) | 1 | 13 | `[13:1]` | `0x00003ffe` |
| 2 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x180810` — `l2_loop_detect_flag` (Table `0xb0`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 14 | 1 | `[14:14]` | `0x00004000` |
| 1 | +0 (`word[0]`) | 1 | 13 | `[13:1]` | `0x00003ffe` |

### `0x180814` — `l2_loop_detect_flag_dummy` (Table `0xb1`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 14 | 1 | `[14:14]` | `0x00004000` |

### `0x180818` — `l2_loop_detect_timer` (Table `0xb2`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 14 | 1 | `[14:14]` | `0x00004000` |
| 1 | +0 (`word[0]`) | 1 | 13 | `[13:1]` | `0x00003ffe` |
| 2 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |
| 3 | +0 (`word[0]`) | 23 | 1 | `[23:23]` | `0x00800000` |
| 4 | +0 (`word[0]`) | 22 | 1 | `[22:22]` | `0x00400000` |
| 5 | +0 (`word[0]`) | 0 | 22 | `[21:0]` | `0x003fffff` |
| 6 | +0 (`word[0]`) | 0 | 22 | `[21:0]` | `0x003fffff` |
| 7 | +0 (`word[0]`) | 14 | 12 | `[25:14]` | `0x03ffc000` |
| 8 | +0 (`word[0]`) | 13 | 1 | `[13:13]` | `0x00002000` |
| 9 | +0 (`word[0]`) | 1 | 12 | `[12:1]` | `0x00001ffe` |

### `0x180940` — `l2_arp_bcast_per_port_ctrl1` (Table `0xb3`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 14 | 1 | `[14:14]` | `0x00004000` |
| 1 | +0 (`word[0]`) | 1 | 13 | `[13:1]` | `0x00003ffe` |

### `0x180944` — `l2_nd_per_port_ctrl1` (Table `0xb4`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 14 | 1 | `[14:14]` | `0x00004000` |
| 1 | +0 (`word[0]`) | 1 | 13 | `[13:1]` | `0x00003ffe` |

### `0x180948` — `l2_lldp_eee_per_port_ctrl1` (Table `0xb5`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 14 | 1 | `[14:14]` | `0x00004000` |
| 1 | +0 (`word[0]`) | 1 | 13 | `[13:1]` | `0x00003ffe` |

### `0x18094c` — `l2_lldp_per_port_ctrl1` (Table `0xb6`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 14 | 1 | `[14:14]` | `0x00004000` |
| 1 | +0 (`word[0]`) | 1 | 13 | `[13:1]` | `0x00003ffe` |

### `0x180950` — `l2_arp_bcast_nd_per_port_ctrl2` (Table `0xb7`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 14 | 1 | `[14:14]` | `0x00004000` |
| 1 | +0 (`word[0]`) | 1 | 13 | `[13:1]` | `0x00003ffe` |

### `0x180954` — `l2_lldp_eee_per_port_ctrl2` (Table `0xb8`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 14 | 1 | `[14:14]` | `0x00004000` |
| 1 | +0 (`word[0]`) | 1 | 13 | `[13:1]` | `0x00003ffe` |

### `0x180958` — `l2_fdb_hw_flush_ctrl` (Table `0xb9`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x18095c` — `l2_uni_que_ctrl` (Table `0xba`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x188000` — `l2_vlan_tbl` (Table `0xbb`, stride `0x8`, entries: 4096)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 8 | 11 | `[18:8]` | `0x0007ff00` |
| 1 | +4 (`word[1]`) | 4 | 4 | `[7:4]` | `0x000000f0` |
| 2 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 3 | +4 (`word[1]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 4 | +0 (`word[0]`) | 23 | 9 | `[31:23]` | `0xff800000` |
| 5 | +0 (`word[0]`) | 22 | 1 | `[22:22]` | `0x00400000` |
| 6 | +0 (`word[0]`) | 21 | 1 | `[21:21]` | `0x00200000` |
| 7 | +0 (`word[0]`) | 18 | 3 | `[20:18]` | `0x001c0000` |
| 8 | +0 (`word[0]`) | 7 | 11 | `[17:7]` | `0x0003ff80` |
| 9 | +0 (`word[0]`) | 6 | 1 | `[6:6]` | `0x00000040` |
| 10 | +0 (`word[0]`) | 5 | 1 | `[5:5]` | `0x00000020` |
| 11 | +0 (`word[0]`) | 0 | 5 | `[4:0]` | `0x0000001f` |

### `0x198000` — `l2_fdb_tbl_bin0` (Table `0xbc`, stride `0x10`, entries: 512)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +8 (`word[2]`) | 30 | 2 | `[31:30]` | `0xc0000000` |
| 1 | +8 (`word[2]`) | 29 | 1 | `[29:29]` | `0x20000000` |
| 2 | +8 (`word[2]`) | 18 | 11 | `[28:18]` | `0x1ffc0000` |
| 3 | +8 (`word[2]`) | 17 | 1 | `[17:17]` | `0x00020000` |
| 4 | +8 (`word[2]`) | 16 | 1 | `[16:16]` | `0x00010000` |
| 5 | +8 (`word[2]`) | 15 | 1 | `[15:15]` | `0x00008000` |
| 6 | +8 (`word[2]`) | 12 | 3 | `[14:12]` | `0x00007000` |
| 7 | +8 (`word[2]`) | 0 | 12 | `[11:0]` | `0x00000fff` |
| 8 | +4 (`word[1]`) | 31 | 1 | `[31:31]` | `0x80000000` |
| 9 | +4 (`word[1]`) | 28 | 3 | `[30:28]` | `0x70000000` |
| 10 | +4 (`word[1]`) | 16 | 12 | `[27:16]` | `0x0fff0000` |
| 11 | +4 (`word[1]`) | 0 | 16 | `[15:0]` | `0x0000ffff` |
| 12 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x19a000` — `l2_fdb_tbl_bin1` (Table `0xbd`, stride `0x10`, entries: 512)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +8 (`word[2]`) | 30 | 2 | `[31:30]` | `0xc0000000` |
| 1 | +8 (`word[2]`) | 29 | 1 | `[29:29]` | `0x20000000` |
| 2 | +8 (`word[2]`) | 18 | 11 | `[28:18]` | `0x1ffc0000` |
| 3 | +8 (`word[2]`) | 17 | 1 | `[17:17]` | `0x00020000` |
| 4 | +8 (`word[2]`) | 16 | 1 | `[16:16]` | `0x00010000` |
| 5 | +8 (`word[2]`) | 15 | 1 | `[15:15]` | `0x00008000` |
| 6 | +8 (`word[2]`) | 12 | 3 | `[14:12]` | `0x00007000` |
| 7 | +8 (`word[2]`) | 0 | 12 | `[11:0]` | `0x00000fff` |
| 8 | +4 (`word[1]`) | 31 | 1 | `[31:31]` | `0x80000000` |
| 9 | +4 (`word[1]`) | 28 | 3 | `[30:28]` | `0x70000000` |
| 10 | +4 (`word[1]`) | 16 | 12 | `[27:16]` | `0x0fff0000` |
| 11 | +4 (`word[1]`) | 0 | 16 | `[15:0]` | `0x0000ffff` |
| 12 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x19c000` — `l2_fdb_tbl_bin2` (Table `0xbe`, stride `0x10`, entries: 512)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +8 (`word[2]`) | 30 | 2 | `[31:30]` | `0xc0000000` |
| 1 | +8 (`word[2]`) | 29 | 1 | `[29:29]` | `0x20000000` |
| 2 | +8 (`word[2]`) | 18 | 11 | `[28:18]` | `0x1ffc0000` |
| 3 | +8 (`word[2]`) | 17 | 1 | `[17:17]` | `0x00020000` |
| 4 | +8 (`word[2]`) | 16 | 1 | `[16:16]` | `0x00010000` |
| 5 | +8 (`word[2]`) | 15 | 1 | `[15:15]` | `0x00008000` |
| 6 | +8 (`word[2]`) | 12 | 3 | `[14:12]` | `0x00007000` |
| 7 | +8 (`word[2]`) | 0 | 12 | `[11:0]` | `0x00000fff` |
| 8 | +4 (`word[1]`) | 31 | 1 | `[31:31]` | `0x80000000` |
| 9 | +4 (`word[1]`) | 28 | 3 | `[30:28]` | `0x70000000` |
| 10 | +4 (`word[1]`) | 16 | 12 | `[27:16]` | `0x0fff0000` |
| 11 | +4 (`word[1]`) | 0 | 16 | `[15:0]` | `0x0000ffff` |
| 12 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x19e000` — `l2_fdb_tbl_bin3` (Table `0xbf`, stride `0x10`, entries: 512)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +8 (`word[2]`) | 30 | 2 | `[31:30]` | `0xc0000000` |
| 1 | +8 (`word[2]`) | 29 | 1 | `[29:29]` | `0x20000000` |
| 2 | +8 (`word[2]`) | 18 | 11 | `[28:18]` | `0x1ffc0000` |
| 3 | +8 (`word[2]`) | 17 | 1 | `[17:17]` | `0x00020000` |
| 4 | +8 (`word[2]`) | 16 | 1 | `[16:16]` | `0x00010000` |
| 5 | +8 (`word[2]`) | 15 | 1 | `[15:15]` | `0x00008000` |
| 6 | +8 (`word[2]`) | 12 | 3 | `[14:12]` | `0x00007000` |
| 7 | +8 (`word[2]`) | 0 | 12 | `[11:0]` | `0x00000fff` |
| 8 | +4 (`word[1]`) | 31 | 1 | `[31:31]` | `0x80000000` |
| 9 | +4 (`word[1]`) | 28 | 3 | `[30:28]` | `0x70000000` |
| 10 | +4 (`word[1]`) | 16 | 12 | `[27:16]` | `0x0fff0000` |
| 11 | +4 (`word[1]`) | 0 | 16 | `[15:0]` | `0x0000ffff` |
| 12 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x1a0000` — `l2_fdb_tbl_bin4` (Table `0xc0`, stride `0x10`, entries: 512)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +8 (`word[2]`) | 30 | 2 | `[31:30]` | `0xc0000000` |
| 1 | +8 (`word[2]`) | 29 | 1 | `[29:29]` | `0x20000000` |
| 2 | +8 (`word[2]`) | 18 | 11 | `[28:18]` | `0x1ffc0000` |
| 3 | +8 (`word[2]`) | 17 | 1 | `[17:17]` | `0x00020000` |
| 4 | +8 (`word[2]`) | 16 | 1 | `[16:16]` | `0x00010000` |
| 5 | +8 (`word[2]`) | 15 | 1 | `[15:15]` | `0x00008000` |
| 6 | +8 (`word[2]`) | 12 | 3 | `[14:12]` | `0x00007000` |
| 7 | +8 (`word[2]`) | 0 | 12 | `[11:0]` | `0x00000fff` |
| 8 | +4 (`word[1]`) | 31 | 1 | `[31:31]` | `0x80000000` |
| 9 | +4 (`word[1]`) | 28 | 3 | `[30:28]` | `0x70000000` |
| 10 | +4 (`word[1]`) | 16 | 12 | `[27:16]` | `0x0fff0000` |
| 11 | +4 (`word[1]`) | 0 | 16 | `[15:0]` | `0x0000ffff` |
| 12 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x1a2000` — `l2_fdb_tbl_bin5` (Table `0xc1`, stride `0x10`, entries: 512)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +8 (`word[2]`) | 30 | 2 | `[31:30]` | `0xc0000000` |
| 1 | +8 (`word[2]`) | 29 | 1 | `[29:29]` | `0x20000000` |
| 2 | +8 (`word[2]`) | 18 | 11 | `[28:18]` | `0x1ffc0000` |
| 3 | +8 (`word[2]`) | 17 | 1 | `[17:17]` | `0x00020000` |
| 4 | +8 (`word[2]`) | 16 | 1 | `[16:16]` | `0x00010000` |
| 5 | +8 (`word[2]`) | 15 | 1 | `[15:15]` | `0x00008000` |
| 6 | +8 (`word[2]`) | 12 | 3 | `[14:12]` | `0x00007000` |
| 7 | +8 (`word[2]`) | 0 | 12 | `[11:0]` | `0x00000fff` |
| 8 | +4 (`word[1]`) | 31 | 1 | `[31:31]` | `0x80000000` |
| 9 | +4 (`word[1]`) | 28 | 3 | `[30:28]` | `0x70000000` |
| 10 | +4 (`word[1]`) | 16 | 12 | `[27:16]` | `0x0fff0000` |
| 11 | +4 (`word[1]`) | 0 | 16 | `[15:0]` | `0x0000ffff` |
| 12 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x1a4000` — `l2_fdb_tbl_bin6` (Table `0xc2`, stride `0x10`, entries: 512)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +8 (`word[2]`) | 30 | 2 | `[31:30]` | `0xc0000000` |
| 1 | +8 (`word[2]`) | 29 | 1 | `[29:29]` | `0x20000000` |
| 2 | +8 (`word[2]`) | 18 | 11 | `[28:18]` | `0x1ffc0000` |
| 3 | +8 (`word[2]`) | 17 | 1 | `[17:17]` | `0x00020000` |
| 4 | +8 (`word[2]`) | 16 | 1 | `[16:16]` | `0x00010000` |
| 5 | +8 (`word[2]`) | 15 | 1 | `[15:15]` | `0x00008000` |
| 6 | +8 (`word[2]`) | 12 | 3 | `[14:12]` | `0x00007000` |
| 7 | +8 (`word[2]`) | 0 | 12 | `[11:0]` | `0x00000fff` |
| 8 | +4 (`word[1]`) | 31 | 1 | `[31:31]` | `0x80000000` |
| 9 | +4 (`word[1]`) | 28 | 3 | `[30:28]` | `0x70000000` |
| 10 | +4 (`word[1]`) | 16 | 12 | `[27:16]` | `0x0fff0000` |
| 11 | +4 (`word[1]`) | 0 | 16 | `[15:0]` | `0x0000ffff` |
| 12 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x1a6000` — `l2_fdb_tbl_bin7` (Table `0xc3`, stride `0x10`, entries: 512)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +8 (`word[2]`) | 30 | 2 | `[31:30]` | `0xc0000000` |
| 1 | +8 (`word[2]`) | 29 | 1 | `[29:29]` | `0x20000000` |
| 2 | +8 (`word[2]`) | 18 | 11 | `[28:18]` | `0x1ffc0000` |
| 3 | +8 (`word[2]`) | 17 | 1 | `[17:17]` | `0x00020000` |
| 4 | +8 (`word[2]`) | 16 | 1 | `[16:16]` | `0x00010000` |
| 5 | +8 (`word[2]`) | 15 | 1 | `[15:15]` | `0x00008000` |
| 6 | +8 (`word[2]`) | 12 | 3 | `[14:12]` | `0x00007000` |
| 7 | +8 (`word[2]`) | 0 | 12 | `[11:0]` | `0x00000fff` |
| 8 | +4 (`word[1]`) | 31 | 1 | `[31:31]` | `0x80000000` |
| 9 | +4 (`word[1]`) | 28 | 3 | `[30:28]` | `0x70000000` |
| 10 | +4 (`word[1]`) | 16 | 12 | `[27:16]` | `0x0fff0000` |
| 11 | +4 (`word[1]`) | 0 | 16 | `[15:0]` | `0x0000ffff` |
| 12 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x1c0000` — `acl_action_tbl` (Table `0xc4`, stride `0x10`, entries: 384)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +8 (`word[2]`) | 25 | 2 | `[26:25]` | `0x06000000` |
| 1 | +8 (`word[2]`) | 23 | 2 | `[24:23]` | `0x01800000` |
| 2 | +8 (`word[2]`) | 21 | 2 | `[22:21]` | `0x00600000` |
| 3 | +8 (`word[2]`) | 10 | 11 | `[20:10]` | `0x001ffc00` |
| 4 | +8 (`word[2]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 5 | +8 (`word[2]`) | 8 | 1 | `[8:8]` | `0x00000100` |
| 6 | +8 (`word[2]`) | 7 | 1 | `[7:7]` | `0x00000080` |
| 7 | +8 (`word[2]`) | 4 | 3 | `[6:4]` | `0x00000070` |
| 8 | +8 (`word[2]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 9 | +8 (`word[2]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 10 | +4 (`word[1]`) | 23 | 9 | `[31:23]` | `0xff800000` |
| 11 | +4 (`word[1]`) | 22 | 1 | `[22:22]` | `0x00400000` |
| 12 | +4 (`word[1]`) | 21 | 1 | `[21:21]` | `0x00200000` |
| 13 | +4 (`word[1]`) | 20 | 1 | `[20:20]` | `0x00100000` |
| 14 | +4 (`word[1]`) | 17 | 3 | `[19:17]` | `0x000e0000` |
| 15 | +4 (`word[1]`) | 16 | 1 | `[16:16]` | `0x00010000` |
| 16 | +4 (`word[1]`) | 4 | 12 | `[15:4]` | `0x0000fff0` |
| 17 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 18 | +4 (`word[1]`) | 1 | 2 | `[2:1]` | `0x00000006` |
| 19 | +4 (`word[1]`) | 0 | 1 | `[0:0]` | `0x00000001` |
| 20 | +0 (`word[0]`) | 31 | 1 | `[31:31]` | `0x80000000` |
| 21 | +0 (`word[0]`) | 29 | 2 | `[30:29]` | `0x60000000` |
| 22 | +0 (`word[0]`) | 28 | 1 | `[28:28]` | `0x10000000` |
| 23 | +0 (`word[0]`) | 22 | 6 | `[27:22]` | `0x0fc00000` |
| 24 | +0 (`word[0]`) | 21 | 1 | `[21:21]` | `0x00200000` |
| 25 | +0 (`word[0]`) | 15 | 6 | `[20:15]` | `0x001f8000` |
| 26 | +0 (`word[0]`) | 14 | 1 | `[14:14]` | `0x00004000` |
| 27 | +0 (`word[0]`) | 13 | 1 | `[13:13]` | `0x00002000` |
| 28 | +0 (`word[0]`) | 12 | 1 | `[12:12]` | `0x00001000` |
| 29 | +0 (`word[0]`) | 6 | 6 | `[11:6]` | `0x00000fc0` |
| 30 | +0 (`word[0]`) | 5 | 1 | `[5:5]` | `0x00000020` |
| 31 | +0 (`word[0]`) | 1 | 4 | `[4:1]` | `0x0000001e` |
| 32 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x220000` — `port_rate_ctrln` (Table `0xc5`, stride `0x4`, entries: 11)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 5 | `[4:0]` | `0x0000001f` |

### `0x220100` — `storm_ctrl_timeslot` (Table `0xc6`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 12 | `[11:0]` | `0x00000fff` |

### `0x220104` — `meter_timeslot` (Table `0xc7`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 12 | `[11:0]` | `0x00000fff` |

### `0x220108` — `port_meter_ctrln` (Table `0xc8`, stride `0x4`, entries: 11)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 4 | 1 | `[4:4]` | `0x00000010` |
| 1 | +0 (`word[0]`) | 0 | 4 | `[3:0]` | `0x0000000f` |

### `0x220140` — `storm_ctrl_mc_type_ctrl` (Table `0xc9`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 11 | `[10:0]` | `0x000007ff` |

### `0x220158` — `drop_event_log` (Table `0xca`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 11 | `[10:0]` | `0x000007ff` |
| 1 | +0 (`word[0]`) | 4 | 1 | `[4:4]` | `0x00000010` |

### `0x22015c` — `stats_offset` (Table `0xcb`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 11 | `[10:0]` | `0x000007ff` |
| 1 | +0 (`word[0]`) | 4 | 1 | `[4:4]` | `0x00000010` |

### `0x220200` — `storm_ctrl_config_tbl` (Table `0xcc`, stride `0x4`, entries: 33)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 13 | 19 | `[31:13]` | `0xffffe000` |
| 1 | +0 (`word[0]`) | 3 | 10 | `[12:3]` | `0x00001ff8` |
| 2 | +0 (`word[0]`) | 2 | 1 | `[2:2]` | `0x00000004` |
| 3 | +0 (`word[0]`) | 1 | 1 | `[1:1]` | `0x00000002` |
| 4 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x220400` — `storm_ctrl_cnt_tbl` (Table `0xcd`, stride `0x4`, entries: 33)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 13 | 19 | `[31:13]` | `0xffffe000` |
| 1 | +0 (`word[0]`) | 3 | 10 | `[12:3]` | `0x00001ff8` |

### `0x220800` — `meter_config_tbl` (Table `0xce`, stride `0x10`, entries: 75)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +8 (`word[2]`) | 14 | 1 | `[14:14]` | `0x00004000` |
| 1 | +8 (`word[2]`) | 13 | 1 | `[13:13]` | `0x00002000` |
| 2 | +8 (`word[2]`) | 11 | 2 | `[12:11]` | `0x00001800` |
| 3 | +8 (`word[2]`) | 10 | 1 | `[10:10]` | `0x00000400` |
| 4 | +8 (`word[2]`) | 7 | 3 | `[9:7]` | `0x00000380` |
| 5 | +8 (`word[2]`) | 6 | 1 | `[6:6]` | `0x00000040` |
| 6 | +8 (`word[2]`) | 5 | 1 | `[5:5]` | `0x00000020` |
| 7 | +8 (`word[2]`) | 4 | 1 | `[4:4]` | `0x00000010` |
| 8 | +8 (`word[2]`) | 0 | 4 | `[3:0]` | `0x0000000f` |
| 9 | +4 (`word[1]`) | 20 | 12 | `[31:20]` | `0xfff00000` |
| 10 | +4 (`word[1]`) | 2 | 18 | `[19:2]` | `0x000ffffc` |
| 11 | +4 (`word[1]`) | 0 | 2 | `[1:0]` | `0x00000003` |
| 12 | +0 (`word[0]`) | 18 | 14 | `[31:18]` | `0xfffc0000` |
| 13 | +0 (`word[0]`) | 0 | 18 | `[17:0]` | `0x0003ffff` |

### `0x221000` — `meter_token_tbl` (Table `0xcf`, stride `0x8`, entries: 75)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +8 (`word[2]`) | 14 | 1 | `[14:14]` | `0x00004000` |
| 1 | +8 (`word[2]`) | 13 | 1 | `[13:13]` | `0x00002000` |
| 2 | +8 (`word[2]`) | 11 | 2 | `[12:11]` | `0x00001800` |
| 3 | +8 (`word[2]`) | 10 | 1 | `[10:10]` | `0x00000400` |

### `0x221400` — `flow_stats_tbl` (Table `0xd0`, stride `0x8`, entries: 64)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 0 | 12 | `[11:0]` | `0x00000fff` |
| 1 | +0 (`word[0]`) | 0 | 32 | `[31:0]` | `0xffffffff` |

### `0x221c00` — `flow_stats_cfg_tbl` (Table `0xd1`, stride `0x4`, entries: 64)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 1 | +0 (`word[0]`) | 2 | 1 | `[2:2]` | `0x00000004` |
| 2 | +0 (`word[0]`) | 0 | 2 | `[1:0]` | `0x00000003` |

### `0x300000` — `cpu_code_to_cpu_prio_mapn` (Table `0xd2`, stride `0x4`, entries: 64)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 3 | 1 | `[3:3]` | `0x00000008` |

### `0x300200` — `int_prio_to_ucast_qid_mapn` (Table `0xd3`, stride `0x4`, entries: 11)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 28 | 3 | `[30:28]` | `0x70000000` |
| 1 | +0 (`word[0]`) | 24 | 3 | `[26:24]` | `0x07000000` |
| 2 | +0 (`word[0]`) | 20 | 3 | `[22:20]` | `0x00700000` |
| 3 | +0 (`word[0]`) | 16 | 3 | `[18:16]` | `0x00070000` |
| 4 | +0 (`word[0]`) | 12 | 3 | `[14:12]` | `0x00007000` |
| 5 | +0 (`word[0]`) | 8 | 3 | `[10:8]` | `0x00000700` |
| 6 | +0 (`word[0]`) | 4 | 3 | `[6:4]` | `0x00000070` |
| 7 | +0 (`word[0]`) | 0 | 3 | `[2:0]` | `0x00000007` |

### `0x300280` — `int_prio_to_mcast_qid_mapn` (Table `0xd4`, stride `0x4`, entries: 11)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 14 | 2 | `[15:14]` | `0x0000c000` |
| 1 | +0 (`word[0]`) | 12 | 2 | `[13:12]` | `0x00003000` |
| 2 | +0 (`word[0]`) | 10 | 2 | `[11:10]` | `0x00000c00` |
| 3 | +0 (`word[0]`) | 8 | 2 | `[9:8]` | `0x00000300` |
| 4 | +0 (`word[0]`) | 6 | 2 | `[7:6]` | `0x000000c0` |
| 5 | +0 (`word[0]`) | 4 | 2 | `[5:4]` | `0x00000030` |
| 6 | +0 (`word[0]`) | 2 | 2 | `[3:2]` | `0x0000000c` |
| 7 | +0 (`word[0]`) | 0 | 2 | `[1:0]` | `0x00000003` |

### `0x300300` — `mirror_ctrl` (Table `0xd5`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 16 | 11 | `[26:16]` | `0x07ff0000` |
| 1 | +0 (`word[0]`) | 4 | 11 | `[14:4]` | `0x00007ff0` |
| 2 | +0 (`word[0]`) | 0 | 4 | `[3:0]` | `0x0000000f` |

### `0x300304` — `mirror_qos_ctrl` (Table `0xd6`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 7 | 1 | `[7:7]` | `0x00000080` |
| 1 | +0 (`word[0]`) | 4 | 3 | `[6:4]` | `0x00000070` |
| 2 | +0 (`word[0]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 3 | +0 (`word[0]`) | 0 | 3 | `[2:0]` | `0x00000007` |

### `0x300400` — `flush_cfg` (Table `0xd7`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 31 | 1 | `[31:31]` | `0x80000000` |
| 1 | +0 (`word[0]`) | 30 | 1 | `[30:30]` | `0x40000000` |
| 2 | +0 (`word[0]`) | 0 | 8 | `[7:0]` | `0x000000ff` |

### `0x308000` — `oq_enq_dis_tbl` (Table `0xd8`, stride `0x4`, entries: 132)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x100000` — `egr_port_ctrln` (Table `0xd9`, stride `0x4`, entries: 11)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 10 | 1 | `[10:10]` | `0x00000400` |
| 1 | +0 (`word[0]`) | 9 | 1 | `[9:9]` | `0x00000200` |
| 2 | +0 (`word[0]`) | 8 | 1 | `[8:8]` | `0x00000100` |
| 3 | +0 (`word[0]`) | 7 | 1 | `[7:7]` | `0x00000080` |
| 4 | +0 (`word[0]`) | 6 | 1 | `[6:6]` | `0x00000040` |
| 5 | +0 (`word[0]`) | 4 | 2 | `[5:4]` | `0x00000030` |
| 6 | +0 (`word[0]`) | 2 | 2 | `[3:2]` | `0x0000000c` |
| 7 | +0 (`word[0]`) | 1 | 1 | `[1:1]` | `0x00000002` |
| 8 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x100080` — `egr_port_vlan_ctrln` (Table `0xda`, stride `0x4`, entries: 11)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 31 | 1 | `[31:31]` | `0x80000000` |
| 1 | +0 (`word[0]`) | 30 | 1 | `[30:30]` | `0x40000000` |
| 2 | +0 (`word[0]`) | 27 | 3 | `[29:27]` | `0x38000000` |
| 3 | +0 (`word[0]`) | 15 | 12 | `[26:15]` | `0x07ff8000` |
| 4 | +0 (`word[0]`) | 12 | 3 | `[14:12]` | `0x00007000` |
| 5 | +0 (`word[0]`) | 0 | 12 | `[11:0]` | `0x00000fff` |

### `0x100100` — `egr_dscp_remarkn` (Table `0xdb`, stride `0x4`, entries: 32)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 6 | `[5:0]` | `0x0000003f` |

### `0x100200` — `egr_prio_remarkn` (Table `0xdc`, stride `0x4`, entries: 64)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 1 | 3 | `[3:1]` | `0x0000000e` |
| 1 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x100300` — `egr_tpid_profile` (Table `0xdd`, stride `0x4`, entries: 4)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 16 | `[15:0]` | `0x0000ffff` |

### `0x100320` — `egr_vlan_trans_rule_ctrln` (Table `0xde`, stride `0x4`, entries: 32)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 28 | 1 | `[28:28]` | `0x10000000` |
| 1 | +0 (`word[0]`) | 27 | 1 | `[27:27]` | `0x08000000` |
| 2 | +0 (`word[0]`) | 15 | 12 | `[26:15]` | `0x07ff8000` |
| 3 | +0 (`word[0]`) | 4 | 11 | `[14:4]` | `0x00007ff0` |
| 4 | +0 (`word[0]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 5 | +0 (`word[0]`) | 2 | 1 | `[2:2]` | `0x00000004` |
| 6 | +0 (`word[0]`) | 1 | 1 | `[1:1]` | `0x00000002` |
| 7 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x1003a0` — `egr_vlan_trans_rule_ctrl1n` (Table `0xdf`, stride `0x4`, entries: 32)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 13 | 12 | `[24:13]` | `0x01ffe000` |
| 1 | +0 (`word[0]`) | 1 | 12 | `[12:1]` | `0x00001ffe` |
| 2 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x100420` — `egr_vlan_trans_data_ctrln` (Table `0xe0`, stride `0x4`, entries: 32)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 14 | 12 | `[25:14]` | `0x03ffc000` |
| 1 | +0 (`word[0]`) | 2 | 12 | `[13:2]` | `0x00003ffc` |
| 2 | +0 (`word[0]`) | 1 | 1 | `[1:1]` | `0x00000002` |
| 3 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x1004a8` — `egr_vlan_tag_transparent_ctrl` (Table `0xe1`, stride `0x4`, entries: 11)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 13 | 11 | `[23:13]` | `0x00ffe000` |
| 1 | +0 (`word[0]`) | 2 | 11 | `[12:2]` | `0x00001ffc` |
| 2 | +0 (`word[0]`) | 1 | 1 | `[1:1]` | `0x00000002` |
| 3 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x1004d4` — `cpu_pkt_bypassedit_ctrl` (Table `0xe2`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 13 | 11 | `[23:13]` | `0x00ffe000` |
| 1 | +0 (`word[0]`) | 2 | 11 | `[12:2]` | `0x00001ffc` |

### `0x340004` — `ipg_pre_len_cfg` (Table `0xe3`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 13 | 11 | `[23:13]` | `0x00ffe000` |

### `0x340008` — `qsch_shp_slot_time_cfg` (Table `0xe4`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 12 | `[11:0]` | `0x00000fff` |

### `0x34000c` — `psch_shp_slot_time_cfg` (Table `0xe5`, stride `0x4`, entries: 1)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 12 | `[11:0]` | `0x00000fff` |

### `0x341000` — `qsch_flow_map_tbl` (Table `0xe6`, stride `0x4`, entries: 132)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 18 | 10 | `[27:18]` | `0x0ffc0000` |
| 1 | +0 (`word[0]`) | 8 | 10 | `[17:8]` | `0x0003ff00` |
| 2 | +0 (`word[0]`) | 4 | 4 | `[7:4]` | `0x000000f0` |
| 3 | +0 (`word[0]`) | 0 | 4 | `[3:0]` | `0x0000000f` |

### `0x342000` — `qsch_c_dwrr_cfg_tbl` (Table `0xe7`, stride `0x4`, entries: 132)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x343000` — `qsch_e_dwrr_cfg_tbl` (Table `0xe8`, stride `0x4`, entries: 132)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 1 | `[0:0]` | `0x00000001` |

### `0x34c000` — `qsch_shp_cfg_tbl` (Table `0xe9`, stride `0x10`, entries: 132)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +8 (`word[2]`) | 6 | 1 | `[6:6]` | `0x00000040` |
| 1 | +8 (`word[2]`) | 5 | 1 | `[5:5]` | `0x00000020` |
| 2 | +8 (`word[2]`) | 4 | 1 | `[4:4]` | `0x00000010` |
| 3 | +8 (`word[2]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 4 | +8 (`word[2]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 5 | +4 (`word[1]`) | 18 | 14 | `[31:18]` | `0xfffc0000` |
| 6 | +4 (`word[1]`) | 0 | 18 | `[17:0]` | `0x0003ffff` |
| 7 | +0 (`word[0]`) | 18 | 14 | `[31:18]` | `0xfffc0000` |
| 8 | +0 (`word[0]`) | 0 | 18 | `[17:0]` | `0x0003ffff` |

### `0x34f000` — `qsch_meter_cfg_tbl` (Table `0xea`, stride `0x4`, entries: 132)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 2 | `[1:0]` | `0x00000003` |

### `0x354000` — `psch_shp_cfg_tbl` (Table `0xeb`, stride `0x8`, entries: 11)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +4 (`word[1]`) | 4 | 1 | `[4:4]` | `0x00000010` |
| 1 | +4 (`word[1]`) | 3 | 1 | `[3:3]` | `0x00000008` |
| 2 | +4 (`word[1]`) | 0 | 3 | `[2:0]` | `0x00000007` |
| 3 | +0 (`word[0]`) | 18 | 14 | `[31:18]` | `0xfffc0000` |
| 4 | +0 (`word[0]`) | 0 | 18 | `[17:0]` | `0x0003ffff` |

### `0x357000` — `psch_meter_cfg_tbl` (Table `0xec`, stride `0x4`, entries: 11)

| Field ID | Word Offset | Bit Offset | Bit Width | Bit Range | Mask (Hex) |
|---|---|---|---|---|---|
| 0 | +0 (`word[0]`) | 0 | 2 | `[1:0]` | `0x00000003` |
