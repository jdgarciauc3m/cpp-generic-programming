$(FINAL_M4_L2_PDF): $(M4_L2_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M4_L2_DIR)/slides
