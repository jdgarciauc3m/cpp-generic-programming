$(FINAL_M9_L3_PDF): $(M9_L3_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M9_L3_DIR)/slides
