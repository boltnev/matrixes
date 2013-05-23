#include "benchmark.h"
#define MAT_SIZE 1000
#include <omp.h>

void randomize(){
	double seconds;
    time_t s_time, f_time;
	time(&s_time);
	
	//
	Matrix<double> *a = new Matrix<double>(MAT_SIZE, MAT_SIZE);
	a->randomize();
	//

	time(&f_time);
	seconds = difftime(f_time, s_time);
	
    printf ("randomize, %d X %d : %.f seconds \n", MAT_SIZE, MAT_SIZE, seconds);	  
}

void multiplication(){
	double seconds;
    time_t s_time, f_time;
	
	Matrix<double> a(MAT_SIZE, MAT_SIZE);
	Matrix<double> b(MAT_SIZE, MAT_SIZE);
	a.randomize();
	b.randomize();
	
	time(&s_time);
	
	//	
	Matrix<double> c = a * b;
	//

	time(&f_time);
	seconds = difftime(f_time, s_time);
	
    printf ("Simple multiplication, %d X %d : %.f seconds \n", MAT_SIZE, MAT_SIZE, seconds);	  
}

void gauss(){
	double seconds;
    time_t s_time, f_time;
	
	Matrix<double> a(MAT_SIZE, MAT_SIZE + 1);
	a.randomize();

	time(&s_time);
	
	//	
	a.gauss();
	//

	time(&f_time);
	seconds = difftime(f_time, s_time);
	
  printf ("Simple gauss solution, %d X %d : %.f seconds \n", MAT_SIZE, MAT_SIZE, seconds);	  
}

void multiplicatioOMP(){
	double seconds;
    time_t s_time, f_time;
	
	Matrix<double> a(MAT_SIZE, MAT_SIZE);
	Matrix<double> b(MAT_SIZE, MAT_SIZE);
	a.randomize();
	b.randomize();
	
	time(&s_time);
	
	//	
	Matrix<double> c = a.mulOmp(b);
	//

	time(&f_time);
	seconds = difftime(f_time, s_time);
	
  printf ("OMP multiplication, %d X %d : %.f seconds \n", MAT_SIZE, MAT_SIZE, seconds);	  
}


void testOmp(){

  omp_set_num_threads(4);
  #pragma omp parallel
  {
    cout << "asd" << endl;
  }

}

int benchmark(){
	randomize();
	multiplication();
	//gauss();
  //testOmp();
  multiplicatioOMP();

  return 0;
}
