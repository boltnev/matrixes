/*
 *
 * This is matrix generator
 *
 * */

#ifndef matrix_lib
#define matrix_lib

typedef long long **  IntegerMatrix;
typedef double **     FloatMatrix;

/* init */

IntegerMatrix initIntegerMatrix(long sizeX, long sizeY);

FloatMatrix initFloatMatrix(long sizeX, long sizeY);

void freeIntegerMatrix(IntegerMatrix M, long sizeX);

void freeFloatMatrix(FloatMatrix M, long sizeX);


IntegerMatrix zeroIntegerMatrix(long sizeX, long sizeY);

FloatMatrix zeroFloatMatrix(long sizeX, long sizeY);

IntegerMatrixidIntegerMatrix(long sizeX, long sizeY);

FloatMatrix idFloatMatrix(long sizeX, long sizeY);

IntegerMatrix randomIntegerMatrix(long sizeX, long sizeY);

FloatMatrix randomFloatMatrix(long sizeX, long sizeY);

/* output */
void showIntegerMatrix(IntegerMatrix, long sizeX, long sizeY);

void showFloatMatrix(FloatMatrix, long sizeX, long sizeY);

/* action */

IntegerMatrix
integerMulS(IntegerMatrix A, long sizeXA, long sizeYA, 
            IntegerMatrix B, long sizeXB, long sizeYB);

#endif
