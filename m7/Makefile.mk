include $(M7_L1_DIR)/Makefile.mk
include $(M7_L2_DIR)/Makefile.mk

$(FINAL_M7_PDF): $(M7_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M7_DIR)/slides

