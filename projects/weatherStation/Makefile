# Makefile for the Smart Weather Station Project - Day 1
#
# This Makefile defines how to build the project.
# It's a simple version that will become more complex as the project grows.

# Compiler and compiler flags
# -Wall: Enables all warnings about constructions that some users consider
#        questionable, and that are easy to avoid.
# -Wextra: Enables some extra warning flags that are not enabled by -Wall.
# -g: Produces debugging information.
# -std=c11: Specifies the C standard to use.
CC = gcc
CFLAGS = -Wall -Wextra -g -std=c11

# The name of the final executable
TARGET = weather_station

# The source file(s)
SOURCES = weather_station.c

# Default target: this is what 'make' will do if run without arguments
all: $(TARGET)

# Rule to link the object file into the final executable
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

# "Phony" targets are targets that don't represent actual files.
# 'clean' is a common phony target to remove built files.
.PHONY: clean
clean:
	rm -f $(TARGET) weather_log.txt

# A target to run the program
.PHONY: run
run: all
	./$(TARGET)

