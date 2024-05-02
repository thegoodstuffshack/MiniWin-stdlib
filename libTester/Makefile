CC = gcc
OBJ_NAME = main
OBJS = $(wildcard src/*.c)
BIN_DIR = ./bin
INCLUDE = ../myStdLibs/include
LIBRARY = ../myStdLibs/bin
LINK = -lmyStdLib
FLAGS = -nostdlib -ffreestanding -e _start 

all: src/main.c
	$(CC) $(OBJS) -o$(BIN_DIR)/$(OBJ_NAME) -I$(INCLUDE) -L$(LIBRARY) $(LINK) $(FLAGS)

clean:
#	$(RM) $(BIN_DIR)/*.exe

purge:
	$(RM) $(BIN_DIR)/*