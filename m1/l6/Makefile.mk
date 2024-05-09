$(FINAL_M1_L6_PDF): $(M1_L6_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M1_L6_DIR)/slides
