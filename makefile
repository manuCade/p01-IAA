# University of La Laguna
# School of Engineering and Technology
# Bachelor's Degree in Computer Engineering
# Course: Design and Analysis of Algorithms
# Year: 3rd
# Practice 1: Complexity analysis
# Author: Manuel Cadenas García
# Email: alu0101636849@ull.edu.es
# Date: 05/02/2026

# Compiler configuration
CXX = g++
STD = -std=c++20
CPPFLAGS := -Iinclude

# Build modes
DEBUG_FLAGS       = -g -Wall -Wextra -Wpedantic
RELEASE_FLAGS     = -O3

# Default build mode
BUILD ?= release

ifeq ($(BUILD),debug)
  CXXFLAGS = $(STD) $(DEBUG_FLAGS)
else
  CXXFLAGS = $(STD) $(RELEASE_FLAGS)
endif

# Directories
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
LIB_DIR := lib

# Targets and files
TARGET  := $(BIN_DIR)/p01
SOURCES := $(wildcard $(SRC_DIR)/*.cc)
OBJECTS := $(SOURCES:$(SRC_DIR)/%.cc=$(OBJ_DIR)/%.o)

# Main rules
all: $(TARGET)

# Rule to link the final executable
$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Generic rule to compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc | $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# Create necessary directories if they don't exist
$(BIN_DIR) $(OBJ_DIR) $(LIB_DIR):
	mkdir -p $@

# Utility rules
.PHONY: all clean debug release

debug:
	$(MAKE) BUILD=debug

release:
	$(MAKE) BUILD=release

clean:
	@rm -rvf $(OBJ_DIR) $(BIN_DIR)
	@echo "Limpieza completada."