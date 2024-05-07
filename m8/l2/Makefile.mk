$(FINAL_M8_L2_PDF): $(M8_L2_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M8_L2_DIR)/slides
