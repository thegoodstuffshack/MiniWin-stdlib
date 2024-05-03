CC = gcc
OBJ_NAME = myStdLib
SOURCE_DIR = ./src
BIN_DIR = ./bin
INC_DIR = ../include
SOURCE = $(subst $(SOURCE_DIR),../$(SOURCE_DIR),$(wildcard $(SOURCE_DIR)/*.c))
OBJS = $(wildcard $(BIN_DIR)/*.o)

all:
	$(MAKE) object
	$(MAKE) shared

object:
	cd $(BIN_DIR) && $(CC) -c $(SOURCE) -I$(INC_DIR) -nostdlib

shared:
	$(CC) -s -shared -o$(BIN_DIR)/$(OBJ_NAME).dll $(OBJS) -Wl,--subsystem,windows -nostdlib -lkernel32

clean:
	$(RM) try.a
	$(RM) *.o

purge:
	$(RM) $(BIN_DIR)/*