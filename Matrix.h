/*
 * Matrix.h
 *
 *  Created on: 11.05.2013
 *      Author: ilya
 */

#ifndef MATRIX_H_
#define MATRIX_H_
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <iostream>

using namespace std;

typedef long sizeType;

template <typename T>
class Matrix {
protected:
	sizeType xSize, ySize;
	void freeDblPtr();
public:
	T** matrix;

	T** initDblPtr(sizeType x, sizeType y);

	void randomize();

	void show();

	void toZero();

	void toId();

	Matrix(sizeType x, sizeType y){
		xSize = x;
		ySize = y;
		matrix = initDblPtr(x, y);
	}

	~Matrix(){
		freeDblPtr();
	}

	sizeType getXSize(){
		return xSize;
	}

	sizeType getYSize(){
		return ySize;
	}

};

template <typename T>
T** Matrix<T>::initDblPtr(sizeType x, sizeType y){
	T** p_matrix;
	sizeType j;

	p_matrix = (T**) malloc(x * sizeof(T *));

	for(j = 0; j < x; j++){
		p_matrix[j] = (T *) malloc(y * sizeof(T));
	}

	return p_matrix;
}


template <typename T>
void Matrix<T>::freeDblPtr(){

    sizeType j;

    for(j = 0; j < xSize; j++){
        free(matrix[j]);
    }

    free(matrix);
}

template <typename T>
void Matrix<T>::randomize(){
	sizeType i, j;
    srand(time(NULL));
    for(i = 0; i < xSize; i++)
        for(j = 0; j < ySize; j++)
            matrix[i][j] = LONG_MIN / 2 + (T) rand()/ ((T)RAND_MAX/(LONG_MAX / 2 - LONG_MIN / 2)) ;

}

template <typename T>
void Matrix<T>::show(){
	sizeType i, j;
    cout << endl;
    for(i = 0; i < xSize; i++){
        for(j = 0; j < ySize; j++){
        	cout << matrix[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl;
}

template <typename T>
void Matrix<T>::toZero(){
	sizeType i, j;

    for(i = 0; i < xSize; i++)
        for(j = 0; j < ySize; j++)
            matrix[i][j] = 0;
}

template <typename T>
void Matrix<T>::toId(){
	sizeType i, j;

    for(i = 0; i < xSize; i++)
        for(j = 0; j < ySize; j++){
        	if(i == j)
        		matrix[i][j] = 1;
        	else
        		matrix[i][j] = 0;
        }
}


#endif /* MATRIX_H_ */
