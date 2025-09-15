# Project
PROJECT := log
CC := clang
CFLAGS := -Wall -Wextra -Werror -Wconversion -Wunused-result

# Dirs
BUILD_DIR := build
INC_DIR := include
EXAMPLE_DIR := example
LIB_INSTALL_DIR := /usr/local/lib
INC_INSTALL_DIR := /usr/local/include
OBJ_DIR := $(BUILD_DIR)/obj
DOC_DIR := doc

# Files
INC := $(INC_DIR)/$(PROJECT).h
EXAMPLE_MAIN := $(EXAMPLE_DIR)/example.c
EXAMPLE_EXE := $(BUILD_DIR)/example

# Rules
.PHONY: all clean install uninstall doc example

all:

clean:
	rm -rf $(BUILD_DIR) $(DOC_DIR) compile_commands.json

install:
	cp $(INC) $(INC_INSTALL_DIR)

uninstall:
	rm $(addprefix $(INC_INSTALL_DIR)/, $(notdir $(INC)))

doc:
	doxygen

example: $(EXAMPLE_EXE)
	./$<

$(EXAMPLE_EXE): $(EXAMPLE_MAIN) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR):
	mkdir -p $@
