$(FINAL_M3_L3_PDF): $(M3_L3_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M3_L3_DIR)/slides
