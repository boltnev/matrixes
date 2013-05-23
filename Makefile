
CC=g++
DEBUG=-g 
	
SOURCES=test_basic.cpp test.cpp test_Matrix.cpp old_matrix.cpp

HEADERS=Matrix.h

OBJECTS=$(SOURCES:.cpp=.o) 

OUTPUT=test

all: $(OBJECTS)
			$(CC) $(OBJECTS) -include $(HEADERS) -o $(OUTPUT)

debug: $(OBJECTS)
			$(CC) $(DEBUG) $(OBJECTS) -include $(HEADERS) -o $(OUTPUT)

clean: 
		rm -rf $(OBJECTS) $(OUTPUT)
		
