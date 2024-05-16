$(FINAL_M9_L2_PDF): $(M9_L2_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M9_L2_DIR)/slides
