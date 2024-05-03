CC = gcc
OBJ_NAME = myStdLib
SOURCE_DIR = ./src
BIN_DIR = ./bin
INC_DIR = ../include
SOURCE = $(subst $(SOURCE_DIR),../$(SOURCE_DIR),$(wildcard $(SOURCE_DIR)/*.c))
OBJS = $(wildcard $(BIN_DIR)/*.o)

# if it works, it works
all:
# $(foreach source, $(wildcard $(SOURCE_DIR)/*.c), FILE=$(source) && export FILE && $(MAKE) object;)
# $(foreach source, $(wildcard $(SOURCE_DIR)/*.c), set FILE=$(source) && $(MAKE) object)
# $(foreach source, $(wildcard $(SOURCE_DIR)/*.c), $(MAKE) object)
	$(MAKE) object
	$(MAKE) shared

object:
# $(CC) -c -o$(subst $(SOURCE_DIR),$(BIN_DIR),$(FILE:.c=.o)) $(FILE) -I$(INC_DIR) -nostdlib
	cd $(BIN_DIR) && $(CC) -c $(SOURCE) -I$(INC_DIR) -nostdlib

shared:
	$(CC) -s -shared -o$(BIN_DIR)/$(OBJ_NAME).dll $(OBJS) -Wl,--subsystem,windows -nostdlib -lkernel32

clean:
	$(RM) try.a
	$(RM) *.o

purge:
	$(RM) $(BIN_DIR)/*