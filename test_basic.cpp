#include "test.h"


int test_truth(){
    assert(true);
    PASSED;
    return 0;
}

int test_initIntegerMatrixInit(){
    IntegerMatrix matrixA = initIntegerMatrix(100, 100);

    matrixA[0][0] = 5;
    matrixA[99][99] = 5;
    assert(matrixA[0][0] == matrixA[99][99]);
    
    PASSED;
    freeIntegerMatrix(matrixA, 100);
    return 0;
}

int test_initFloatMatrixInit(){
    FloatMatrix matrixA = initFloatMatrix(100, 100);

    matrixA[0][0] = 5.5;
    matrixA[99][99] = 5.5;
    assert(matrixA[0][0] == matrixA[99][99]);
    
    PASSED;
    freeFloatMatrix(matrixA, 100);
    return 0;
}

int test_idIntegerMatrixInit(){
    long i, j;
    IntegerMatrix matrixA = idIntegerMatrix(100, 100);

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
    FloatMatrix matrixA = idFloatMatrix(100, 100);

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
    IntegerMatrix matrixA = randomIntegerMatrix(10, 10);
    
    showIntegerMatrix(matrixA, 10, 10);
    
    PASSED;
    freeIntegerMatrix(matrixA, 10);
    return 0;
}

int test_showFloatMatrixInit(){
    long i, j;
    FloatMatrix matrixA = randomFloatMatrix(10, 10);

    showFloatMatrix(matrixA, 10, 10);

    PASSED;
    freeFloatMatrix(matrixA, 10);
    return 0;
}

int test_IntegerMulS(){
    long i, j;
    IntegerMatrix a, b, c;

    a = idIntegerMatrix(10, 10);
    c = integerMulS(a, 10, 10, a, 10, 10);
  
    for(i = 0; i < 10; i++)
        for(j = 0; j < 10; j++){
           if(i == j)
               assert(c[i][j] == 1);
           else
               assert(c[i][j] == 0);
        }
    PASSED;
    freeIntegerMatrix(c, 10);
    freeIntegerMatrix(a, 10);
    
    
    a = randomIntegerMatrix(10, 10);
    b = idIntegerMatrix(10, 10);
    
    c = integerMulS(a, 10, 10, b, 10, 10);

    for(i = 0; i < 10; i++)
        for(j = 0; j < 10; j++)
            assert(c[i][j] == a[i][j]);

    PASSED;
    freeIntegerMatrix(a, 10);
    freeIntegerMatrix(b, 10);
    freeIntegerMatrix(c, 10);
   
    Integer aa[2][3] = {
                         {1, 2, 3},
                         {5, 4, 6}
                       };

    Integer bb[3][2] = {
                         {1, 2},
                         {2, 3},
                         {4, 5}
                       }; 
    
    a = initIntegerMatrix(2, 3);
    b = initIntegerMatrix(3, 2);

    for(i = 0; i < 2; i++)
        for(j = 0; j < 3; j++)
        {
            a[i][j] = aa[i][j];
        }

    for(i = 0; i < 3; i++)
        for(j = 0; j < 2; j++)
        {
            b[i][j] = bb[i][j];
        }


    c = integerMulS(a, 2, 3, 
                    b, 3, 2);

    assert( c[0][0] == 17);
    assert( c[0][1] == 23);
    assert( c[1][0] == 37);
    assert( c[1][1] == 52);

    PASSED;
    freeIntegerMatrix(a, 2);
    freeIntegerMatrix(b, 3);
    freeIntegerMatrix(c, 2);
    return 0;
}

int test_FloatMulS(){
    long i, j;
    FloatMatrix a, b, c;

    a = idFloatMatrix(10, 10);
    c = floatMulS(a, 10, 10, a, 10, 10);
  
    for(i = 0; i < 10; i++)
        for(j = 0; j < 10; j++){
           if(i == j)
               assert(c[i][j] == 1.0);
           else
               assert(c[i][j] == 0.0);
        }
    PASSED;
    freeFloatMatrix(c, 10);
    freeFloatMatrix(a, 10);
    
    
    a = randomFloatMatrix(10, 10);
    b = idFloatMatrix(10, 10);
    
    c = floatMulS(a, 10, 10, b, 10, 10);

    for(i = 0; i < 10; i++)
        for(j = 0; j < 10; j++)
            assert(c[i][j] == a[i][j]);

    PASSED;
    freeFloatMatrix(a, 10);
    freeFloatMatrix(b, 10);
    freeFloatMatrix(c, 10);
   
    Float aa[2][3] = {
                         {1, 2, 3},
                         {5, 4, 6}
                       };

    Float bb[3][2] = {
                         {1, 2},
                         {2, 3},
                         {4, 5}
                       }; 
    
    a = initFloatMatrix(2, 3);
    b = initFloatMatrix(3, 2);

    for(i = 0; i < 2; i++)
        for(j = 0; j < 3; j++)
        {
            a[i][j] = aa[i][j];
        }

    for(i = 0; i < 3; i++)
        for(j = 0; j < 2; j++)
        {
            b[i][j] = bb[i][j];
        }


    c = floatMulS(a, 2, 3, 
                    b, 3, 2);

    assert( c[0][0] == 17);
    assert( c[0][1] == 23);
    assert( c[1][0] == 37);
    assert( c[1][1] == 52);

    PASSED;
    freeFloatMatrix(a, 2);
    freeFloatMatrix(b, 3);
    freeFloatMatrix(c, 2);
    return 0;
}

int test_show(){

    printf("\n");
    test_showIntegerMatrixInit();
    
    printf("\n");
    test_showFloatMatrixInit();
    printf("\n");
	return 0;
}

int test_basic(){
    
    test_truth();
    test_initIntegerMatrixInit();
    test_initFloatMatrixInit();
    test_idIntegerMatrixInit();
    test_idFloatMatrixInit();
    test_IntegerMulS();
    test_FloatMulS();
    
    //test_show();

    printf("\n");
    return 0;  
}
