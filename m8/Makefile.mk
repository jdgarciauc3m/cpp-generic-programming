include $(M8_L1_DIR)/Makefile.mk
include $(M8_L2_DIR)/Makefile.mk

$(FINAL_M8_PDF): $(M8_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M8_DIR)/slides

