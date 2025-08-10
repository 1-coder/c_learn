# Makefile for the Smart Weather Station Project - Day 2
#
# This Makefile handles a multi-file project structure.

# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -Wextra -g -std=c11

# The name of the final executable
TARGET = weather_station_modular

# Use wildcard to find all .c files in the current directory
SOURCES = $(wildcard *.c)
# Replace the .c extension with .o to get the object file names
OBJECTS = $(SOURCES:.c=.o)

# Default target: build the executable
all: $(TARGET)

# Rule to link the object files into the final executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Rule to compile a .c file into a .o file
# The '$<' is an automatic variable that means "the first prerequisite" (the .c file).
# The '$@' is an automatic variable that means "the target" (the .o file).
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Phony target to clean up build artifacts
.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJECTS) weather_log.txt

# Phony target to run the program
.PHONY: run
run: all
	./$(TARGET)

