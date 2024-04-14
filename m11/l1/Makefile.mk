$(FINAL_M11_L1_PDF): $(M11_L1_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M11_L1_DIR)/slides
