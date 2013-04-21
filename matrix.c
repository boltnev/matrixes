#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
/*
 * TODO: refactoring
 * How to reduce the copypaste?
 * */

long long ** initIntegerMatrix(long sizeX, long sizeY){
    long long **p_matrix; 
    long j;
    
    p_matrix = malloc(sizeX * sizeof(long long *));
        
    for(j = 0; j < sizeX; j++){
        p_matrix[j] = malloc(sizeY * sizeof(long long));
    }
    
    return p_matrix;
}

double ** initFloatMatrix(long sizeX, long sizeY){

    double **p_matrix; 
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

void freeFloatMatrix(double ** p_matrix, long sizeX){
    long j;
        
    for(j = 0; j < sizeX; j++){
        free(p_matrix[j]);
    }
    
    free (p_matrix);
}


long long ** zeroIntegerMatrix(long sizeX, long sizeY){
    long i, j;
    long long ** matrix = initIntegerMatrix(sizeX, sizeY);
    
    for(i = 0; i < sizeX; i++)
        for(j = 0; j < sizeY; j++)
            matrix[i][j] = 0;

    return matrix;
}

double ** zeroFloatMatrix(long sizeX, long sizeY){
    long i, j;
    double ** matrix = initFloatMatrix(sizeX, sizeY);
    
    for(i = 0; i < sizeX; i++)
        for(j = 0; j < sizeY; j++)
            matrix[i][j] = 0;

    return matrix;
}

long long **idIntegerMatrix(long sizeX, long sizeY){
    long i;
    long long ** matrix = zeroIntegerMatrix(sizeX, sizeY);
    
    for(i = 0; i < sizeX; i++)
        matrix[i][i] = 1;

    return matrix;
}

double ** idFloatMatrix(long sizeX, long sizeY){
    long i;
    double ** matrix = zeroFloatMatrix(sizeX, sizeY);
    
    for(i = 0; i < sizeX; i++)
        matrix[i][i] = 1;

    return matrix;
}

long long ** randomIntegerMatrix(long sizeX, long sizeY){
    long i, j;
    long long ** matrix = initIntegerMatrix(sizeX, sizeY);
    
    srand(time(NULL));
    
    for(i = 0; i < sizeX; i++)
        for(j = 0; j < sizeY; j++)
            matrix[i][j] = rand();

    return matrix;
}

double ** randomFloatMatrix(long sizeX, long sizeY){
    long i, j;
    double ** matrix = initFloatMatrix(sizeX, sizeY);
    
    srand(time(NULL));
    for(i = 0; i < sizeX; i++)
        for(j = 0; j < sizeY; j++)
            matrix[i][j] = LONG_MIN / 2 + (double) rand()/ ((double)RAND_MAX/(LONG_MAX / 2 - LONG_MIN / 2)) ;

    return matrix;
}

void showIntegerMatrix(long long ** matrix, long sizeX, long sizeY ){
    long i, j;
    for(i = 0; i < sizeX; i++){
        for(j = 0; j < sizeY; j++)
            printf("%3lld  ", matrix[i][j]);
        printf("\n");
        }
}


void showFloatMatrix(double ** matrix, long sizeX, long sizeY ){
    long i, j;
    for(i = 0; i < sizeX; i++){
        for(j = 0; j < sizeY; j++)
            printf("%5.3lf  ", matrix[i][j]);
        printf("\n");
        }
    
}

