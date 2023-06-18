##################################################
### MACROS
##################################################

# $(1): COMPILER
# $(2): Object file to generate
# $(3): Source file
# $(4): Additional dependencies
# $(5): Compiler flags
define COMPILE
$(2): $(3) $(4)
	$(1) -c -o $(2) $(3) $(5)
endef

# $(1): Source file
# $(1): src/tinyPTC/xbcde.cpp
# $(1): obj/tinyPTC/xbcde.cpp
define C20
$(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(patsubst $(SRC)%,$(OBJ)%,$(1))))
endef

define C2H
$(patsubst %.c,%.h,$(patsubst %.cpp,%.hpp,$(1)))
endef

##################################################
### CONFIG
##################################################

APP 			:= game
CCFLAGS 	:= -Wall -Wextra -pedantic
CFLAGS 	:= $(CCFLAGS)
CC 				:= g++
C 				:= gcc
MKDIR 		:= mkdir -p
SRC 			:= src
OBJ 			:= obj
# LIBS 			:= -lX11 -lXext
LIBS 			:= -lX11

#patsubst sustituye path por ejemplo el path src lo puedes sustituir por obj

ALLCPPS 		:= $(shell find src/ -type f -iname "*.cpp")
ALLCS 			:= $(shell find src/ -type f -iname "*.c")
ALLSOBJ 	:= $(foreach F, $(ALLCPPS) $(ALLCS),$(call C20,$(F)))
SUBDIRS 		:= $(shell find $(SRC) -type d)
OBJSUBDIRS 	:= $(patsubst $(SRC)%, $(OBJ)%, $(SUBDIRS))

.PHONY: info

$(APP) : $(OBJSUBDIRS) $(ALLSOBJ)
	$(CC) -o $(APP) $(ALLSOBJ) $(LIBS)

#Generate rules for all objects
$(foreach F,$(ALLCPPS),$(eval $(call COMPILE,$(CC),$(call C20,$(F)),$(F),$(call C2H,$(F)),$(CCFLAGS))))
$(foreach F,$(ALLCS),$(eval $(call COMPILE,$(C),$(call C20,$(F)),$(F),$(call C2H,$(F)),$(CFLAGS))))

info:
	$(info $(SUBDIRS))
	$(info $(OBJSUBDIRS))
	$(info $(ALLCPPS))
	$(info $(ALLCS))
	$(info $(ALLCSOBJ))
	

$(OBJSUBDIRS):
	$(MKDIR) $(OBJSUBDIRS)

##CLEAN rules
clean:
	$(RM) -r "./$(OBJ)"

cleanall: clean
	$(RM) "./$(APP)"
