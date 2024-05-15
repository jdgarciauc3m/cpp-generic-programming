$(FINAL_M9_L4_PDF): $(M9_L4_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M9_L4_DIR)/slides
