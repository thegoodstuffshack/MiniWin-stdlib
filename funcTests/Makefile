CC = gcc
OBJ_NAME = main
OBJS = $(wildcard *.c)
BIN_DIR = ./bin
INCLUDE = ../myStdLibs/include
LIBRARY = ../myStdLibs/bin
LINK = -lmingw32
FLAGS =

all:
	$(CC) $(OBJS) -o$(BIN_DIR)/$(OBJ_NAME) -I$(INCLUDE) -L$(LIBRARY) $(LINK) $(FLAGS)

clean:
#	$(RM) $(BIN_DIR)/*.exe

purge:
	$(RM) $(BIN_DIR)/*