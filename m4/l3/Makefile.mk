$(FINAL_M4_L3_PDF): $(M4_L3_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M4_L3_DIR)/slides
