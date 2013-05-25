
CC=g++
CFLAGS=-fopenmp 
DEBUG=-g 

MPI_FLAG=MPI_BUILD

SOURCES=test.cpp test_Matrix.cpp benchmark.cpp

MPI_SOURCES=test_mpi.cpp test_Matrix.cpp benchmark.cpp

HEADERS=Matrix.h

OBJECTS=$(SOURCES:.cpp=.o) 

OUTPUT=test

OUTPUT_MPI=test_mpi

all: $(OBJECTS)
			$(CC) $(CFLAGS) -include $(HEADERS) $(SOURCES) -o $(OUTPUT) 

mpi: $(OBJECTS)
			mpic++ $(CFLAGS) -include $(HEADERS) $(MPI_SOURCES) -o $(OUTPUT_MPI) -D $(MPI_FLAG)

debug: $(OBJECTS)
			$(CC) $(DEBUG) $(OBJECTS) -include $(HEADERS) -o $(OUTPUT)

clean: 
		rm -rf $(OBJECTS) $(OUTPUT) $(OUTPUT_MPI)
		
remake:
		make clean && make
		
remake_mpi:
		make clean && make mpi
