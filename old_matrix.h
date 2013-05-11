/*
 *
 * This is matrix generator
 *
 * */

#ifndef matrix_lib
#define matrix_lib

typedef long long   Integer;
typedef double      Float;

typedef Integer **  IntegerMatrix;
typedef Float   **  FloatMatrix;

/* init */

IntegerMatrix initIntegerMatrix(long sizeX, long sizeY);

FloatMatrix initFloatMatrix(long sizeX, long sizeY);

void freeIntegerMatrix(IntegerMatrix M, long sizeX);

void freeFloatMatrix(FloatMatrix M, long sizeX);


IntegerMatrix zeroIntegerMatrix(long sizeX, long sizeY);

FloatMatrix zeroFloatMatrix(long sizeX, long sizeY);

IntegerMatrix idIntegerMatrix(long sizeX, long sizeY);

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

FloatMatrix 
floatMulS(FloatMatrix a, long sizeXA, long sizeYA, 
          FloatMatrix b, long sizeXB, long sizeYB);



/* templates */


#endif
