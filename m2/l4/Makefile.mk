$(FINAL_M2_L4_PDF): $(M2_L4_PARTS) $(CONFIG_SLIDES)
	$(LATEXMK) -jobname=$(subst /,-,$(<D)) $(M2_L4_DIR)/slides
