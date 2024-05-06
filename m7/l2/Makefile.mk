$(FINAL_M7_L2_PDF): $(M7_L2_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M7_L2_DIR)/slides
