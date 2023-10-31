#include "mat_utility.h"
#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
//获得矩阵，进行预处理
int main(int argc, char** argv)
{
    std::cout << "This is U50 SPMV Host application" << std::endl;
    int     row_size, col_size, nnzA;
    int* rows = NULL, * cols = NULL, * row_length = NULL;
    DATA_TYPE *values;
    if (argc < 4)
    {
        std::cout << "args !!!!" << std::endl;
        return -1;
    }
    char inputFile[1000] = "";
	strcpy(inputFile, argv[1]);
	std::cout <<"inputFile = "<<inputFile << std::endl;
    readMtx(inputFile, row_size, col_size, nnzA, rows, row_length, cols, values);
    

    std::cout <<"data_size = "<<nnzA<<std::endl;
    std::cout <<"row_size = "<<row_size<<std::endl;
    std::cout <<"col_size = "<<col_size<<std::endl;

    int nownzrows = 0;
    for (int nowrows = 0; nowrows < row_size;)
    {
        ++nownzrows;
        nowrows = rows[nownzrows];
        // std::cout <<"nzrows = "<<nowrows<<std::endl;
    }
    std::cout <<"nzrows = "<<nownzrows<<std::endl;
    
    std::ofstream ofs;
    ofs.open(std::string(argv[2])+'/'+std::string(argv[3]) + ".NNZnum", std::ios::out | std::ios::binary);
    ofs.write((const char *)row_length, sizeof(int) * nownzrows);
    ofs.close();


    ofs.open(std::string(argv[2])+'/'+std::string(argv[3]) + ".ColIndex", std::ios::out | std::ios::binary);
    ofs.write((const char *)row_length, sizeof(int) * nnzA);
    ofs.close();

    ofs.open(std::string(argv[2])+'/'+std::string(argv[3]) + ".Val", std::ios::out | std::ios::binary);
    ofs.write((const char *)row_length, sizeof(DATA_TYPE) * nnzA);
    ofs.close();

    ofs.open(std::string(argv[2])+'/'+std::string(argv[3]) + ".cfg", std::ios::out | std::ios::binary);
    ofs << "soBNNZ " << sizeof(int) * nownzrows << std::endl;
    ofs << "soBColIndex " << sizeof(int) * nnzA << std::endl;
    ofs << "soBVal " << sizeof(DATA_TYPE) * nnzA<<std::endl;

    ofs.close();

    
    free(rows);
    free(row_length);
    free(cols);
    free(values);
    return 0;
}