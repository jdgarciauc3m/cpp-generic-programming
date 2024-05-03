include $(M6_L1_DIR)/Makefile.mk

$(FINAL_M6_PDF): $(M6_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M6_DIR)/slides

