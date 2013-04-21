/*
 *
 * This is matrix generator
 *
 * */

long long ** initIntegerMatrix(long sizeX, long sizeY);

double ** initFloatMatrix(long sizeX, long sizeY);

void freeIntegerMatrix(long long ** M, long sizeX);

void freeFloatMatrix(double ** M, long sizeX);


long long ** zeroIntegerMatrix(long sizeX, long sizeY);

double ** zeroFloatMatrix(long sizeX, long sizeY);

long long **idIntegerMatrix(long sizeX, long sizeY);

double ** idFloatMatrix(long sizeX, long sizeY);

long long ** randomIntegerMatrix(long sizeX, long sizeY);

double ** randomFloatMatrix(long sizeX, long sizeY);

void showIntegerMatrix(long long **, long sizeX, long sizeY);

void showFloatMatrix(double **, long sizeX, long sizeY);
