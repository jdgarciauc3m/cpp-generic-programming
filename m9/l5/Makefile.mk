$(FINAL_M9_L5_PDF): $(M9_L5_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M9_L5_DIR)/slides
