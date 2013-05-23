
CC=g++
CFLAGS= -fopenmp 
DEBUG=-g 


SOURCES=test_basic.cpp test.cpp test_Matrix.cpp old_matrix.cpp benchmark.cpp

HEADERS=Matrix.h

OBJECTS=$(SOURCES:.cpp=.o) 

OUTPUT=test

all: $(OBJECTS)
			$(CC) $(CFLAGS) -include $(HEADERS) $(SOURCES) -o $(OUTPUT) 

mpi: $(OBJECTS)
			mpic++ $(CFLAGS) -include $(HEADERS) $(SOURCES) -o $(OUTPUT) 

debug: $(OBJECTS)
			$(CC) $(DEBUG) $(OBJECTS) -include $(HEADERS) -o $(OUTPUT)

clean: 
		rm -rf $(OBJECTS) $(OUTPUT)
		
remake:
		make clean && make
		
remake_mpi:
		make clean && make mpi