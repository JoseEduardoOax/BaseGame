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
CFLAGS 	:= -Wall -Wextra -pedantic
CCFLAGS 	:= $(CFLAGS) -std=c++17
CC 				:= g++
C 				:= gcc
MKDIR 		:= mkdir -p
SRC 			:= src
OBJ 			:= obj
# LIBS 			:= -lX11 -lXext
LIBDIR 		:= lib
LIBS 			:= $(LIBDIR)/picoPNG/libpicopng.a $(LIBDIR)/tinyPTC/libtinyptc.a -lX11
INCDIRS 	:= -I$(SRC) -I$(LIBDIR)

ifdef DEBUG
   CCFLAGS += -g 
else ifdef SANITIZE
   CCFLAGS += -fsanitize=address -fno-omit-frame-pointer -O1 -g
else
   CCFLAGS += -O3
endif

#patsubst sustituye path por ejemplo el path src lo puedes sustituir por obj
# ALLCPPS 		:= $(shell find src/ -type f -iname "*.cpp")
ALLCPPS     := $(shell find src/ -type f \( -iname "*.cpp" ! -iname "main.cpp" \))
ALLCS 			:= $(shell find src/ -type f -iname "*.c")
ALLSOBJ 	:= $(foreach F, $(ALLCPPS) $(ALLCS),$(call C20,$(F)))
SUBDIRS 		:= $(shell find $(SRC) -type d)
OBJSUBDIRS 	:= $(patsubst $(SRC)%, $(OBJ)%, $(SUBDIRS))

.PHONY: info libs libs-clean libs-cleanall

$(APP) : $(OBJSUBDIRS) $(ALLSOBJ) obj/main.o
	$(CC) -o $(APP) obj/main.o $(ALLSOBJ) $(LIBS)

obj/main.o : src/main.cpp
	$(CC) $(CCFLAGS) $(INCDIRS) -c -o obj/main.o src/main.cpp

#Generate rules for all objects
$(foreach F,$(ALLCPPS),$(eval $(call COMPILE,$(CC),$(call C20,$(F)),$(F),$(call C2H,$(F)),$(CCFLAGS) $(INCDIRS))))
$(foreach F,$(ALLCS),$(eval $(call COMPILE,$(C),$(call C20,$(F)),$(F),$(call C2H,$(F)),$(CFLAGS) $(INCDIRS))))

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

## LIB rules
libs:
	$(MAKE) -C $(LIBDIR)

libs-clean:
	$(MAKE) -C $(LIBDIR) clean

libs-cleanall:
	$(MAKE) -C $(LIBDIR) cleanall


