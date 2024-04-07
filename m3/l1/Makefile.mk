$(FINAL_M3_L1_PDF): $(M3_L1_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M3_L1_DIR)/slides
