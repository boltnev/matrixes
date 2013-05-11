
CC=gcc
DEBUG=-g 

SOURCES=test_basic.c test.c matrix.c

OBJECTS=$(SOURCES:.c=.o)

OUTPUT=test

test: $(OBJECTS)
			$(CC) $(OBJECTS) -o $(OUTPUT)

test_debug: $(OBJECTS)
			$(CC) $(DEBUG) $(OBJECTS) -o $(OUTPUT)

clean: 
		rm -rf $(OBJECTS) $(OUTPUT)


