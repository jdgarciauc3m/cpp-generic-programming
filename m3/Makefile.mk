include $(M3_L1_DIR)/Makefile.mk
include $(M3_L2_DIR)/Makefile.mk
include $(M3_L3_DIR)/Makefile.mk

$(FINAL_M3_PDF): $(M3_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M3_DIR)/slides

