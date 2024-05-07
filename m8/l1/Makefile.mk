$(FINAL_M8_L1_PDF): $(M8_L1_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M8_L1_DIR)/slides
