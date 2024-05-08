$(FINAL_M8_L3_PDF): $(M8_L3_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M8_L3_DIR)/slides
