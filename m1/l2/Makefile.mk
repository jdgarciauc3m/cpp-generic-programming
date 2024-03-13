$(FINAL_M1_L2_PDF): $(M1_L2_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M1_L2_DIR)/slides
