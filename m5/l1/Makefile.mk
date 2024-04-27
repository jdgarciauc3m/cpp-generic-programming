$(FINAL_M5_L1_PDF): $(M5_L1_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M5_L1_DIR)/slides
