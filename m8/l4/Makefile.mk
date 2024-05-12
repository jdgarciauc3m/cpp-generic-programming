$(FINAL_M8_L4_PDF): $(M8_L4_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M8_L4_DIR)/slides
