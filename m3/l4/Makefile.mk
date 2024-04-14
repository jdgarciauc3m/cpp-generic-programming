$(FINAL_M3_L4_PDF): $(M3_L4_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M3_L4_DIR)/slides
