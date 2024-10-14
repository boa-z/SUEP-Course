extract \
  -selection all  -type rc_coupled

input_db -type def \
  -lef_file_list /qixin/library/SMIC0.18MS/IP/SCC018UG_HD_RVT_V0.3a/SCC018UG_HD_RVT_V0.3a/SCC018UG_HD_RVT_V0p3a/lef/tf/180MSE_1833/scc018ug_6m_1tma1.lef \
    /qixin/library/SMIC0.18MS/IP/SCC018UG_HD_RVT_V0.3a/SCC018UG_HD_RVT_V0.3a/SCC018UG_HD_RVT_V0p3a/lef/macro/scc018ug_hd_rvt_ant.lef \
    /qixin/library/SMIC0.18MS/IP/SP018W_V1p8a/lef/SP018W_V1p8_6MT.lef \
  -design_file ./route.def

log_file -file_name ./qrc.log -dump_options true

output_db \
  -type spef \
  -short_incomplete_net_pins true \
  -subtype standard

extraction_setup \
  -technology_layer_map \
  METAL1 metal1  \
  METAL2 metal2  \
  METAL3 metal3  \
  METAL4 metal4  \
  METAL5 metal5  \
  METAL6 metal6  \
  VIA12 via1  \
  VIA23 via2  \
  VIA34 via3  \
  VIA45 via4  \
  VIA56 via5a  \
  -max_fracture_length 25 

process_technology \
-technology_library_file ./techlib.defs \
-technology_name qrc_tech_file \
-technology_corner typical \
-temperature 25

output_setup \
  -write_incomplete_shorts_nets_file true \
  -directory_name ./qrc_test \
  -file_name frequency_counter_control
