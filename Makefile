
CC=g++
DEBUG=-g 
	
SOURCES=test_basic.cpp test.cpp test_Matrix.cpp old_matrix.cpp Matrix.cpp

OBJECTS=$(SOURCES:.cpp=.o)

OUTPUT=test

all: $(OBJECTS)
			$(CC) $(OBJECTS) -o $(OUTPUT)

debug: $(OBJECTS)
			$(CC) $(DEBUG) $(OBJECTS) -o $(OUTPUT)

clean: 
		rm -rf $(OBJECTS) $(OUTPUT)


