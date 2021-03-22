APP_NAME = chessviz
LIB_NAME = libchessviz
TEST_NAME = $(APP_NAME)-test

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I src -MP -MMD -g

TESTFLAGS =

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
TEST_DIR = test

THIRDPARTY = thirdparty

APP_PATH = $(BIN_DIR)/$(APP_NAME)
OBJ_PATH = $(OBJ_DIR)/$(SRC_DIR)
OBJ_TEST_PATH = $(OBJ_DIR)/$(TEST_DIR)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a
TEST_PATH = $(BIN_DIR)/$(TEST_NAME)

APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.c')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.c=$(OBJ_PATH)/%.o)

TEST_SOURCES = $(shell find $(TEST_DIR) -name '*.c')
TEST_OBJECTS = $(TEST_SOURCES:$(TEST_DIR)/%.c=$(OBJ_TEST_PATH)/%.o)

LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.c')
LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%.c=$(OBJ_PATH)/%.o)

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d) $(TEST_OBJECTS:.o=.d)

all: $(APP_PATH)

-include $(DEPS)

# make bin/chessviz
$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ 

# make lib
$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

# make obj-files for lib
$(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/%.o: $(SRC_DIR)/$(LIB_NAME)/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS)  -c $< -o $@

# make obj-files
$(OBJ_PATH)/$(APP_NAME)/%.o: $(SRC_DIR)/$(APP_NAME)/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

test: $(TEST_PATH)

$(TEST_PATH): $(TEST_OBJECTS) $(LIB_PATH)
	$(CC) $(CPPFLAGS) $(TESTFLAGS) -I $(THIRDPARTY) $^ -o $@

$(OBJ_DIR)/$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CPPFLAGS) $(TESTFLAGS) -I $(THIRDPARTY) -c $< -o $@

clean: 
	$(RM) $(APP_PATH) $(LIB_PATH)
	find $(OBJ_DIR) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name '*.d' -exec $(RM) '{}' \;
	@echo Done!

.clang-format:
	wget -O $@ -c "https://csc-software-development.readthedocs.io/ru/2021/_static/.clang-format"

format: .clang-format
	find . -name "*.[ch]" | xargs clang-format -i
	@echo Done!

.PHONY: all clean format test
