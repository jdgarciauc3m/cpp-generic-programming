$(FINAL_M1_L3_PDF): $(M1_L3_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M1_L3_DIR)/slides
