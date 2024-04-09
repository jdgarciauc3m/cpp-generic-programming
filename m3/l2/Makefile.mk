$(FINAL_M3_L2_PDF): $(M3_L2_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M3_L2_DIR)/slides
