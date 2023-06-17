APP 			:= game
CCFLAGS 	:= -Wall -pedantic
CFLAGS 	:= $(CCFLAGS)
CC 				:= g++
C 				:= gcc
MKDIR 		:= mkdir -p
SRC 			:= src
OBJ 			:= obj

#patsubst sustituye path por ejemplo el path src lo puedes sustituir por obj
ALLCPPS 		:= $(shell find src/ -type f -iname "*.cpp")
ALLCS 			:= $(shell find src/ -type f -iname "*.c")
ALLCSOBJ 		:= $(patsubst %.c, %.o, $(ALLCS))
ALLCPPSOBJ 		:= $(patsubst %.cpp, %.o, $(ALLCPPS))
SUBDIRS 		:= $(shell find $(SRC) -type d)
OBJSUBDIRS 	:= $(patsubst $(SRC)%, $(OBJ)%, $(SUBDIRS))

.PHONY: dir

$(APP) : $(OBJSUBDIRS) $(ALLCSOBJ) $(ALLCPPSOBJ)
	$(CC) -o $(APP) $(patsubst $(SRC)%,$(OBJ)%, $(ALLCSOBJ) $(ALLCPPSOBJ))

#incluye todos los archivos de .o son iguales a .c
%.o: %.c
	$(C) -o $(patsubst $(SRC)%,$(OBJ)%,$@) -c $^ $(CFLAGS)

%.o: %.cpp
	$(CC) -o $(patsubst $(SRC)%,$(OBJ)%,$@) -c $^ $(CCFLAGS)

dir:
	$(info $(SUBDIRS))
	$(info $(OBJSUBDIRS))
	$(info $(ALLCPPS))
	$(info $(ALLCS))
	$(info $(ALLCSOBJ))
	

$(OBJSUBDIRS):
	$(MKDIR) $(OBJSUBDIRS)
