#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
/*
 * TODO: refactoring
 * How to reduce the copypaste?
 * rewrite all in C++
 * */


#include "old_matrix.h"
 

IntegerMatrix initIntegerMatrix(long sizeX, long sizeY){
    IntegerMatrix p_matrix; 
    long j;
    
    p_matrix = (IntegerMatrix) malloc(sizeX * sizeof(Integer *));
        
    for(j = 0; j < sizeX; j++){
        p_matrix[j] = (Integer *) malloc(sizeY * sizeof(Integer));
    }
    
    return p_matrix;
}

FloatMatrix initFloatMatrix(long sizeX, long sizeY){

    FloatMatrix p_matrix; 
    long j;
    
    p_matrix = (FloatMatrix)  malloc(sizeX * sizeof(Float *));
        
    for(j = 0; j < sizeX; j++){
        p_matrix[j] = (Float * ) malloc(sizeY * sizeof(Float));
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
    printf("\n");
    for(i = 0; i < sizeX; i++){
        for(j = 0; j < sizeY; j++)
            printf("%3lld  ", matrix[i][j]);
        printf("\n");
        }
    printf("\n");
}


void showFloatMatrix(FloatMatrix matrix, long sizeX, long sizeY ){
    long i, j;
    printf("\n");
    for(i = 0; i < sizeX; i++){
        for(j = 0; j < sizeY; j++)
            printf("%5.3lf  ", matrix[i][j]);
        printf("\n");
        }
    printf("\n");
}


IntegerMatrix 
integerMulS(IntegerMatrix a, long sizeXA, long sizeYA, 
            IntegerMatrix b, long sizeXB, long sizeYB)
{
    if(sizeYA != sizeXB)
        return NULL;

    IntegerMatrix c = initIntegerMatrix(sizeYA, sizeXB);
    
    long i, j, k;
    Integer element;

    for( i = 0; i < sizeXA; i++ )
        for(j = 0; j < sizeYB; j++){
            
            element = 0;
            for(k = 0; k < sizeYA; k++){
                element += a[i][k] * b[k][j]; 
            }

            c[i][j] = element;
        }

    return c;
}


FloatMatrix 
floatMulS(FloatMatrix a, long sizeXA, long sizeYA, 
          FloatMatrix b, long sizeXB, long sizeYB)
{
    if(sizeYA != sizeXB)
        return NULL;

    FloatMatrix c = initFloatMatrix(sizeYA, sizeXB);
    
    long i, j, k;
    Float element;

    for( i = 0; i < sizeXA; i++ )
        for(j = 0; j < sizeYB; j++){
            
            element = 0;
            for(k = 0; k < sizeYA; k++){
                element += a[i][k] * b[k][j]; 
            }

            c[i][j] = element;
        }

    return c;
}


