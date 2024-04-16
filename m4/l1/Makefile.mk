$(FINAL_M4_L1_PDF): $(M4_L1_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M4_L1_DIR)/slides
