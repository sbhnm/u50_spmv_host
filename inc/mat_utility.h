#include "config.h"

int readMtx(char* filename, int& m, int& n, int& nnzA, int*& csrRowPtrA, int*& csrRowLength, int*& csrColIdxA, DATA_TYPE*& csrValA);