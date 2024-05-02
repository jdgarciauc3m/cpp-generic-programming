$(FINAL_M5_L4_PDF): $(M5_L4_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M5_L4_DIR)/slides
