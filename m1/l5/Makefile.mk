$(FINAL_M1_L5_PDF): $(M1_L5_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M1_L5_DIR)/slides
