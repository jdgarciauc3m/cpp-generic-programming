$(FINAL_M5_L2_PDF): $(M5_L2_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M5_L2_DIR)/slides
