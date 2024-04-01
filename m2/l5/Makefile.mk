$(FINAL_M2_L5_PDF): $(M2_L5_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M2_L5_DIR)/slides
