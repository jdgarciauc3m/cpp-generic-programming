$(FINAL_M6_L3_PDF): $(M6_L3_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M6_L3_DIR)/slides
