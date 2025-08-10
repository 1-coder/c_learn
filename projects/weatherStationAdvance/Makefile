# Makefile for the Smart Weather Station Project - Day 3
#
# This Makefile handles our final multi-file project structure.
# No changes are needed from Day 2, as it's designed to be scalable.

# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -Wextra -g -std=c11

# The name of the final executable
TARGET = weather_station_final

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

