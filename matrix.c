#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
/*
 * TODO: refactoring
 * How to reduce the copypaste?
 * */


#include "matrix.h"
 

IntegerMatrix initIntegerMatrix(long sizeX, long sizeY){
    IntegerMatrix p_matrix; 
    long j;
    
    p_matrix = malloc(sizeX * sizeof(long long *));
        
    for(j = 0; j < sizeX; j++){
        p_matrix[j] = malloc(sizeY * sizeof(long long));
    }
    
    return p_matrix;
}

FloatMatrix initFloatMatrix(long sizeX, long sizeY){

    FloatMatrix p_matrix; 
    long j;
    
    p_matrix = malloc(sizeX * sizeof(double *));
        
    for(j = 0; j < sizeX; j++){
        p_matrix[j] = malloc(sizeY * sizeof(double));
    }
    
    return p_matrix;
}

void freeIntegerMatrix(long long  ** p_matrix, long sizeX){
     
    long j;
        
    for(j = 0; j < sizeX; j++){
        free(p_matrix[j]);
    }

    free(p_matrix);
}

void freeFloatMatrix(FloatMatrix p_matrix, long sizeX){
    long j;
        
    for(j = 0; j < sizeX; j++){
        free(p_matrix[j]);
    }
    
    free (p_matrix);
}


IntegerMatrix zeroIntegerMatrix(long sizeX, long sizeY){
    long i, j;
    IntegerMatrix matrix = initIntegerMatrix(sizeX, sizeY);
    
    for(i = 0; i < sizeX; i++)
        for(j = 0; j < sizeY; j++)
            matrix[i][j] = 0;

    return matrix;
}

FloatMatrix zeroFloatMatrix(long sizeX, long sizeY){
    long i, j;
    FloatMatrix matrix = initFloatMatrix(sizeX, sizeY);
    
    for(i = 0; i < sizeX; i++)
        for(j = 0; j < sizeY; j++)
            matrix[i][j] = 0;

    return matrix;
}

IntegerMatrix idIntegerMatrix(long sizeX, long sizeY){
    long i;
    IntegerMatrix matrix = zeroIntegerMatrix(sizeX, sizeY);
    
    for(i = 0; i < sizeX; i++)
        matrix[i][i] = 1;

    return matrix;
}

FloatMatrix idFloatMatrix(long sizeX, long sizeY){
    long i;
    FloatMatrix matrix = zeroFloatMatrix(sizeX, sizeY);
    
    for(i = 0; i < sizeX; i++)
        matrix[i][i] = 1;

    return matrix;
}

IntegerMatrix randomIntegerMatrix(long sizeX, long sizeY){
    long i, j;
    IntegerMatrix matrix = initIntegerMatrix(sizeX, sizeY);
    
    srand(time(NULL));
    
    for(i = 0; i < sizeX; i++)
        for(j = 0; j < sizeY; j++)
            matrix[i][j] = rand();

    return matrix;
}

FloatMatrix randomFloatMatrix(long sizeX, long sizeY){
    long i, j;
    FloatMatrix matrix = initFloatMatrix(sizeX, sizeY);
    
    srand(time(NULL));
    for(i = 0; i < sizeX; i++)
        for(j = 0; j < sizeY; j++)
            matrix[i][j] = LONG_MIN / 2 + (double) rand()/ ((double)RAND_MAX/(LONG_MAX / 2 - LONG_MIN / 2)) ;

    return matrix;
}

void showIntegerMatrix(IntegerMatrix matrix, long sizeX, long sizeY ){
    long i, j;
    for(i = 0; i < sizeX; i++){
        for(j = 0; j < sizeY; j++)
            printf("%3lld  ", matrix[i][j]);
        printf("\n");
        }
}


void showFloatMatrix(FloatMatrix matrix, long sizeX, long sizeY ){
    long i, j;
    for(i = 0; i < sizeX; i++){
        for(j = 0; j < sizeY; j++)
            printf("%5.3lf  ", matrix[i][j]);
        printf("\n");
        }
    
}


IntegerMatrix 
integerMulS(IntegerMatrix a, long sizeXA, long sizeYA, 
            IntegerMatrix b, long sizeXB, long sizeYB)
{
    //assert(sizeXA == sizeYB);

    IntegerMatrix c = initIntegerMatrix(sizeYA, sizeXB);
    
    long i, j, k;
    long long element;

    for( i = 0; i < sizeYA; i++ )
        for(j = 0; j < sizeXB; j++){
            
            element = 0;
            for(k = 0; k < sizeXA; k++){
                element += a[k][i] * b[j][k]; 
            }

            c[j][i] = element;
        }

    return c;
}
