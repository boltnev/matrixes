#include "test.h"
#include "benchmark.h"
#include <mpi.h>

int main(int argc, char **argv){

	MPI_Init(&argc, &argv);
    
	test_basic();
    test_Matrix();
	
	benchmark();

	MPI_Finalize();
	
    return 0;  
}
