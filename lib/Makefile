# LIBS 		:= $(shell find . -maxdepth 1 -type d)
LIBS 			:= $(shell ls -d */)

.PHONY: info all clean cleanall
	
all:
	$(foreach DIR,$(LIBS),$(MAKE) -C $(DIR) &&) true
#
#
# all: $(LIBS)
# $(LIBS):
# 	$(MAKE) -C $@

clean:
	$(foreach DIR,$(LIBS),$(MAKE) -C $(DIR) clean &&) true
# $(MAKE) -C tinyPTC/ clean
# $(MAKE) -C picoPNG/ clean
	
cleanall:
	$(foreach DIR,$(LIBS),$(MAKE) -C $(DIR) cleanall &&) true
# $(MAKE) -C tinyPTC/ cleanall
# $(MAKE) -C picoPNG/ cleanall

info:
	$(info $(LIBS))
