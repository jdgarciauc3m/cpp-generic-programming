$(FINAL_M2_L1_PDF): $(M2_L1_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M2_L1_DIR)/slides
