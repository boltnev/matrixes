#include <assert.h>
#include <stdio.h>
#include "matrix.h"
#define TRUE 1
#define FAKSE 0
#define PASSED printf(".")

int test_truth(){
    assert(TRUE);
    PASSED;
    return 0;
}

int test_initIntegerMatrixInit(){
    long long ** matrixA = initIntegerMatrix(100, 100);

    matrixA[0][0] = 5;
    matrixA[99][99] = 5;
    assert(matrixA[0][0] == matrixA[99][99]);
    
    PASSED;
    freeIntegerMatrix(matrixA, 100);
    return 0;
}

int test_initFloatMatrixInit(){
    double ** matrixA = initFloatMatrix(100, 100);

    matrixA[0][0] = 5.5;
    matrixA[99][99] = 5.5;
    assert(matrixA[0][0] == matrixA[99][99]);
    
    PASSED;
    freeFloatMatrix(matrixA, 100);
    return 0;
}

int test_idIntegerMatrixInit(){
    long i, j;
    long long ** matrixA = idIntegerMatrix(100, 100);

    for(i = 0; i < 100; i++)
        for(j = 0; j < 100; j++){
           if(i == j)
               assert(matrixA[i][j] == 1);
           else
               assert(matrixA[i][j] == 0);
        }
    
    
    PASSED;
    freeIntegerMatrix(matrixA, 100);
    return 0;
}

int test_idFloatMatrixInit(){
    long i, j;
    double ** matrixA = idFloatMatrix(100, 100);

    for(i = 0; i < 100; i++)
        for(j = 0; j < 100; j++){
           if(i == j)
               assert(matrixA[i][j] == 1);
           else
               assert(matrixA[i][j] == 0);
        }
    
    
    PASSED;
    freeFloatMatrix(matrixA, 100);
    return 0;
}

int test_showIntegerMatrixInit(){
    long i, j;
    long long ** matrixA = randomIntegerMatrix(10, 10);
    
    showIntegerMatrix(matrixA, 10, 10);
    
    PASSED;
    freeIntegerMatrix(matrixA, 10);
    return 0;
}

int test_showFloatMatrixInit(){
    long i, j;
    double ** matrixA = randomFloatMatrix(10, 10);

    showFloatMatrix(matrixA, 10, 10);

    PASSED;
    freeFloatMatrix(matrixA, 10);
    return 0;
}

int main(){
    
    test_truth();
    test_initIntegerMatrixInit();
    test_initFloatMatrixInit();
    test_idIntegerMatrixInit();
    test_idFloatMatrixInit();


    printf("\n");
    test_showIntegerMatrixInit();
    
    printf("\n");
    test_showFloatMatrixInit();
    printf("\n");

    printf("\n");
    return 0;  
}
