$(FINAL_M2_L7_PDF): $(M2_L7_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M2_L7_DIR)/slides
