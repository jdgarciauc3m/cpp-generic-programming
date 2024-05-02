include $(M5_L1_DIR)/Makefile.mk
include $(M5_L2_DIR)/Makefile.mk
include $(M5_L3_DIR)/Makefile.mk
include $(M5_L4_DIR)/Makefile.mk
include $(M5_L5_DIR)/Makefile.mk

$(FINAL_M5_PDF): $(M5_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M5_DIR)/slides

