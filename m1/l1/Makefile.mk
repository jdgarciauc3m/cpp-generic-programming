$(FINAL_M1_L1_PDF): $(M1_L1_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M1_L1_DIR)/slides
