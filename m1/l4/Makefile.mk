$(FINAL_M1_L4_PDF): $(M1_L4_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M1_L4_DIR)/slides
