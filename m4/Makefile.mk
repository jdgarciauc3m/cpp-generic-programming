include $(M4_L1_DIR)/Makefile.mk

$(FINAL_M4_PDF): $(M4_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M4_DIR)/slides

