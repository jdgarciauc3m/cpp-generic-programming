include $(M2_L1_DIR)/Makefile.mk
include $(M2_L2_DIR)/Makefile.mk
include $(M2_L3_DIR)/Makefile.mk
include $(M2_L4_DIR)/Makefile.mk
include $(M2_L5_DIR)/Makefile.mk

$(FINAL_M2_PDF): $(M2_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M2_DIR)/slides

