$(FINAL_M6_L2_PDF): $(M6_L2_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M6_L2_DIR)/slides
