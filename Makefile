APP 		:= game
CCFLAG 	:= -Wall -pedantic
CC 			:= g++
MKDIR 	:= mkdir -p
SRC 		:= src
OBJ 		:= obj

SUBDIRS 		:= $(shell find $(SRC) -type d)
OBJSUBDIRS 	:=$(patsubst $(SRC)%, $(OBJ)%, $(SUBDIRS))

.PHONY: dir

$(APP) : $(OBJSUBDIRS) $(SRC)/main.cpp
	$(CC) $(SRC)/main.cpp -c -o $(OBJ)/main.o $(CCFLAG)

dir:
	$(info $(SUBDIRS))
	$(info $(OBJSUBDIRS))

$(OBJSUBDIRS):
	$(MKDIR) $(OBJSUBDIRS)
