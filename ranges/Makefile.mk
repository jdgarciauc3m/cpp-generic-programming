include $(RANGES_INTRO_DIR)/Makefile.mk

$(FINAL_RANGES_PDF): $(RANGES_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(RANGES_DIR)/slides

