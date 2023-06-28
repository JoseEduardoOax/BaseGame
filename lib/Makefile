# LIBS 		:= $(shell find . -maxdepth 1 -type d)
LIBS 			:= $(shell ls -d */)

.PHONY: info all clean cleanall
	
all:
	@-$(foreach DIR,$(LIBS),$(MAKE) -C $(DIR);)

clean:
	@-$(foreach DIR,$(LIBS),$(MAKE) -C $(DIR) clean;)
	
cleanall:
	@-$(foreach DIR,$(LIBS),$(MAKE) -C $(DIR) cleanall;)

info:
	$(info $(LIBS))
