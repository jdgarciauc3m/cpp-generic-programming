$(FINAL_M5_L5_PDF): $(M5_L5_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M5_L5_DIR)/slides
