/*
 * test_Matrix.cpp
 *
 *  Created on: 11.05.2013
 *      Author: ilya
 */

#include "test.h"
#include "Matrix.h"

int test_MatrixInit(){

    Matrix<int> *matrixA = new Matrix<int>(100, 100);

    matrixA->matrix[0][0] = 5;
    matrixA->matrix[99][99] = 5;
    assert(matrixA->matrix[0][0] == matrixA->matrix[99][99]);

    delete matrixA;

    Matrix<double> *matrixB = new Matrix<double>(100, 100);

    matrixB->matrix[0][0] = 5;
    matrixB->matrix[99][99] = 5;
    assert(matrixB->matrix[0][0] == matrixB->matrix[99][99]);

    delete matrixB;

    PASSED;
	return 0;
}

int test_Randomize(){
    Matrix<int> *matrixA = new Matrix<int>(100, 100);

    matrixA->randomize();
    PASSED;
	return 0;
}

int test_Show(){
    Matrix<int> *matrixA = new Matrix<int>(10, 10);

    matrixA->randomize();

    matrixA->show();
    delete matrixA;
    PASSED;
	return 0;
}


int test_toZero(){
	sizeType i, j;
	Matrix<int> *matrixA = new Matrix<int>(100, 100);

	matrixA->toZero();

	for(i = 0; i < 100; i++)
		for(j = 0; j < 100; j++){
			   assert(matrixA->matrix[i][j] == 0);
		}

    delete matrixA;
	PASSED;
	return 0;
}

int test_toId(){
	sizeType i, j;
	Matrix<double> *matrixA = new Matrix<double>(100, 100);

	matrixA->toId();

	for(i = 0; i < 100; i++)
		for(j = 0; j < 100; j++){
			if(i == j)
				assert(matrixA->matrix[i][j] == 1);
			else
		    assert(matrixA->matrix[i][j] == 0);
		}

    delete matrixA;
	PASSED;
	return 0;
}

int test_MulS(){
    sizeType i, j;
    //Matrix<double>* a, b, c;

    Matrix<double> a(10, 10); //= new Matrix<double>(10, 10);
    Matrix<double> c(10, 10);

    a.randomize();
    c.toId();

    PASSED;

    Matrix<double> d = a * c;

    for(i = 0; i < 10; i++)
        for(j = 0; j < 10; j++)
            assert(d.matrix[i][j] == a.matrix[i][j]);

    PASSED;
 

    Matrix<double> f(2, 3);
    Matrix<double> g(3, 2);


    double aa[2][3] = {
                         {1, 2, 3},
                         {5, 4, 6}
                     };

    double bb[3][2] = {
                         {1, 2},
                         {2, 3},
                         {4, 5}
                       };

    for(i = 0; i < 2; i++)
        for(j = 0; j < 3; j++)
        {
            f.matrix[i][j] = aa[i][j];
        }

    for(i = 0; i < 3; i++)
            for(j = 0; j < 2; j++)
            {
                g.matrix[i][j] = bb[i][j];
            }

    Matrix<double> h = f * g; 
   
    assert( h.matrix[0][0] == 17);
    assert( h.matrix[0][1] == 23);
    assert( h.matrix[1][0] == 37);
    assert( h.matrix[1][1] == 52);

    PASSED;
    return 0;
}

int test_transitions(){

    Matrix<double> a(10, 10); //= new Matrix<double>(10, 10);

    a.randomize();

    double s[10];

    for(sizeType i = 0; i < 10; i++)
    	s[i] = a.matrix[1][i] + a.matrix[2][i];

    a.rowAdd(1, 2, 1);

    for(sizeType i = 0; i < 10; i++)
    	assert(a.matrix[1][i] == s[i]);

    a.rowAdd(8, 8, -1);

    for(sizeType i = 0; i < 10; i++)
    	assert(a.matrix[8][i] == 0);

    a.rowAddDiv(1, 0, -a.matrix[1][0], a.matrix[0][0] );

    assert(a.matrix[1][0] == 0);

	PASSED;
	return 0;
}

int test_triangulize(){
    Matrix<float> a(10, 10); //= new Matrix<double>(10, 10);

    a.randomize();

    a.triangulize();

    for(sizeType i = 0; i < a.getYSize(); i++)
    	for(sizeType j = 0; j < a.getXSize(); j++)
    		if(j > i)
    			assert(a.matrix[j][i] == 0);
    PASSED;
	
	a.triangulizeUp();
		
	return 0;
}

int test_gauss(){
	sizeType i, j;
	
	Matrix<float> a(3, 4);
	
		
    double aa[3][4] = {
                         {2, 1, -1, 8},
                         {-3, -1, 2, -11},
						 {-2, 1, 2, -3}
                      };
		
    for(i = 0; i < 3; i++)
    	for(j = 0; j < 4; j++)
        {
          a.matrix[i][j] = aa[i][j];
        }				 
    

	float* sol = a.gauss();
	
	assert(sol[0] == 2);
	assert(sol[1] == 3);
	assert(sol[2] == -1); 
	
	free( sol );
	PASSED;
	return 0;
}

int test_MulOMP(){
    sizeType i, j;
    //Matrix<double>* a, b, c;

    Matrix<double> a(10, 10); //= new Matrix<double>(10, 10);
    Matrix<double> c(10, 10);

    a.randomize();
    c.toId();

    PASSED;

    Matrix<double> d = a * c;

    for(i = 0; i < 10; i++)
        for(j = 0; j < 10; j++)
            assert(d.matrix[i][j] == a.matrix[i][j]);

    PASSED;
 

    Matrix<double> f(2, 3);
    Matrix<double> g(3, 2);


    double aa[2][3] = {
                         {1, 2, 3},
                         {5, 4, 6}
                     };

    double bb[3][2] = {
                         {1, 2},
                         {2, 3},
                         {4, 5}
                       };

    for(i = 0; i < 2; i++)
        for(j = 0; j < 3; j++)
        {
            f.matrix[i][j] = aa[i][j];
        }

    for(i = 0; i < 3; i++)
            for(j = 0; j < 2; j++)
            {
                g.matrix[i][j] = bb[i][j];
            }

    Matrix<double> h = f * g; 
   
    assert( h.matrix[0][0] == 17);
    assert( h.matrix[0][1] == 23);
    assert( h.matrix[1][0] == 37);
    assert( h.matrix[1][1] == 52);

    PASSED;
    return 0;
}

int test_Matrix(){
	test_MatrixInit();
	test_Randomize();
	test_toZero();
	test_toId();
	test_MulS();
	test_transitions();
	test_triangulize();
	test_gauss();

  //test_Show();

  printf("\n");
	return 0;
}
