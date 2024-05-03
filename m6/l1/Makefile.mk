$(FINAL_M6_L1_PDF): $(M6_L1_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M6_L1_DIR)/slides
