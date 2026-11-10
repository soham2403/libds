
CC = gcc
AR = ar

CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -g
CPPFLAGS = -Iinclude

BUILD = build
LIB = $(BUILD)/libds.a

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c,$(BUILD)/%.o,$(SRC))

.PHONY: all clean example test

all: $(LIB)

$(BUILD):
	mkdir -p $(BUILD)

$(BUILD)/%.o: src/%.c | $(BUILD)
	$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -MP -c $< -o $@

$(LIB): $(OBJ)
	$(AR) rcs $@ $^

example: $(LIB)
	$(CC) $(CPPFLAGS) $(CFLAGS) examples/DArray.c $(LIB) -o $(BUILD)/example

test: $(LIB)
	$(CC) $(CPPFLAGS) $(CFLAGS) tests/Test_DArray.c $(LIB) -o $(BUILD)/test_DArray
	./$(BUILD)/test_DArray

clean:
	rm -rf $(BUILD)

-include $(OBJ:.o=.d)
