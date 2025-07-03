CC = gcc
CFLAGS = -g -O0
#CFLAGS = -O3
SOURCES = main.c MyString.c
OBJECTS= $(SOURCES:.c=.o)
EXECUTABLE = program 

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *.o program