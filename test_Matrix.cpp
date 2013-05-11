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


int test_Matrix(){
	test_MatrixInit();
	test_Randomize();
	test_toZero();
	test_toId();
	//test_Show();


	return 0;
}
