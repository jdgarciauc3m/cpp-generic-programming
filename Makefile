FINAL_DIR= final

LATEXMK=latexmk -pdf -file-line-error -halt-on-error -outdir=$(FINAL_DIR) 

CONFIG_SLIDES= \
	common/metadata.tex \
	config/common.tex  \
	config/common-title.tex  \
	config/config-lst.tex  \
	config/config-tc-one.tex  \
	config/footline.tex  \
	config/packages.tex\
	common/license-cc.tex \

LOGOS=logos/*

include m1/Makefile.def
include m2/Makefile.def
include m3/Makefile.def
include m4/Makefile.def
include m5/Makefile.def
include m11/Makefile.def
include guide/Makefile.def

.PHONY: all clean slides guide

all:	slides guide

clean:
	rm -Rf $(FINAL_DIR)

$(FINAL_DIR):
	mkdir -p $(FINAL_DIR)

slides: $(ALL_SLIDES_FINAL_PDF)

guide:	$(GUIDE_FINAL_PDF)

printall:
	echo $(ALL_SLIDES_FINAL_PDF)

include $(M1_DIR)/Makefile.mk
include $(M2_DIR)/Makefile.mk
include $(M3_DIR)/Makefile.mk
include $(M4_DIR)/Makefile.mk
include $(M5_DIR)/Makefile.mk
include $(M11_DIR)/Makefile.mk
include $(GUIDE_DIR)/Makefile.mk
