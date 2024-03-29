$(FINAL_M2_L2_PDF): $(M2_L2_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M2_L2_DIR)/slides
