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
#include <exception>

using namespace std;

typedef long sizeType;

template <typename T>
class Matrix {
protected:
	  sizeType xSize, ySize;
  	  void freeDblPtr();
      Matrix<T>* simpleMultiplication(Matrix<T>* A, Matrix<T>* B);

public:
	  T** matrix;

	  T** initDblPtr(sizeType x, sizeType y);

      Matrix<T> operator*(Matrix<T>& right);

	  void randomize();

	  void show();

	  void toZero();

	  void toId();

	  Matrix(){
		  xSize = 0;
		  ySize = 0;
	  }

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

	  T** getMatrixPtr(){
		    return matrix;
	  }
	  void operator=(Matrix<T>& right){
		    xSize = right.getXSize();
    	    ySize = right.getYSize();
    	    matrix = right.getMatrixPtr();
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

template <typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T>& right )
{
    return *simpleMultiplication(this, &right);
}

template <typename T>
Matrix<T>* Matrix<T>::simpleMultiplication(Matrix<T>* A, Matrix<T>* B){

    if(A->ySize != B->xSize)
      throw;

    Matrix<T>* C = new Matrix<T>(A->xSize, B->ySize);
                    
    sizeType i, j, k;
    T element;

    for( i = 0; i < A->xSize; i++ )
        for(j = 0; j < B->ySize; j++){
            
            C->matrix[i][j] = 0;
            for(k = 0; k < A->ySize; k++){
                C->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j]; 
            }   
    
    }     
    return C;
}

#endif /* MATRIX_H_ */
