include $(M1_L1_DIR)/Makefile.mk
include $(M1_L2_DIR)/Makefile.mk

$(FINAL_M1_PDF): $(M1_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M1_DIR)/slides

