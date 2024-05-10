$(FINAL_M5_L6_PDF): $(M5_L6_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M5_L6_DIR)/slides
