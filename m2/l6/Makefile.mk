$(FINAL_M2_L6_PDF): $(M2_L6_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M2_L6_DIR)/slides
