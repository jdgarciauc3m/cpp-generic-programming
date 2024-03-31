$(FINAL_M2_L3_PDF): $(M2_L3_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M2_L3_DIR)/slides
