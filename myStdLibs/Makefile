CC = gcc
OBJ_NAME = myStdLib
SOURCE_DIR = ./src
BIN_DIR = ./bin
LIB_DIR = ./lib
INC_DIR = ./include
SOURCE = $(wildcard src/*.c)
OBJS = $(wildcard $(BIN_DIR)/*.o)

# if it works, it works
all:
	$(foreach source, $(wildcard $(SOURCE_DIR)/*.c), FILE=$(source) && export FILE && $(MAKE) object;)
	$(MAKE) shared

object:
	$(CC) -c -o$(subst $(SOURCE_DIR),$(BIN_DIR),$(FILE:.c=.o)) $(FILE) -I$(INC_DIR) -nostdlib

shared:
	$(CC) -s -shared -o$(BIN_DIR)/$(OBJ_NAME).dll $(OBJS) -Wl,--subsystem,windows -nostdlib -lkernel32

clean:
	$(RM) $(BIN_DIR)/*.o

purge:
	$(RM) $(BIN_DIR)/*