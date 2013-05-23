#include "benchmark.h"

#define MAT_SIZE 20000
 
int randomize(){
	double seconds;
    time_t s_time, f_time;
	time(&s_time);
	
	//
	Matrix<double> *a = new Matrix<double>(MAT_SIZE, MAT_SIZE);
	a->randomize();
	//

	time(&f_time);
	seconds = difftime(f_time, s_time);
	
    printf ("randomize test, %d X %d : %.f seconds \n", MAT_SIZE, MAT_SIZE, seconds);	  
}


int benchmark(){
	randomize();
		
}
