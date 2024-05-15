include $(M9_L1_DIR)/Makefile.mk
include $(M9_L4_DIR)/Makefile.mk

$(FINAL_M9_PDF): $(M9_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M9_DIR)/slides

