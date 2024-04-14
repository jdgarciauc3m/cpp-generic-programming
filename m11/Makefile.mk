include $(M11_L1_DIR)/Makefile.mk

$(FINAL_M11_PDF): $(M11_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M11_DIR)/slides

