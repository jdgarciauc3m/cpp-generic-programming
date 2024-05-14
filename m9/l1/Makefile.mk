$(FINAL_M9_L1_PDF): $(M9_L1_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M9_L1_DIR)/slides
