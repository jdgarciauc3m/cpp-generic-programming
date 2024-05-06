$(FINAL_M7_L1_PDF): $(M7_L1_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M7_L1_DIR)/slides
