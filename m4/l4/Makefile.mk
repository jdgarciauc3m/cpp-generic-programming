$(FINAL_M4_L4_PDF): $(M4_L4_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M4_L4_DIR)/slides
