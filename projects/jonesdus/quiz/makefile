#
# Makefile for testme.c
#

# The default C compiler
CC = gcc

# The CFLAGS variable sets compile flags for g++:
# -g				Compile with debug information

CFLAGS = -g 

# The LDFLAGS variable sets flags for linker
#
LDFLAGS = 0

# This section lists out the files of the project. 
# If you add/change names of source files, here is where you 
# edit this Makefile.
DEPS = 0
SOURCES = testme.c
OBJECTS = testme.o
TARGET = testme

# Compiles all of the object files
%.o: %.c 
	$(CC) -c -o $@ $< $(CFLAGS)

# Links all object code into executable 
$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)

# The phony target "clean" is used to remove all compiled object files.
.PHONY: clean
clean:
	rm -f *.o $(TARGET)