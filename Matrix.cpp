//
// Created by marrabld on 8/11/16.
//

#include "Matrix.h"
#include <iostream>

Matrix::Matrix(){
    rows = 0;
    cols = 0;

    data[rows][cols] = {0.f};

    for (size_t i = 0; i < 2; ++i){
        for (size_t j = 0; j < 2; ++j){
            data[i][j] = 0.0f;
        }
    }

}

Matrix::Matrix(int _rows, int _cols){
    rows = _rows;
    cols = _cols;

    //float data[_rows][_cols];
    data.resize(rows, std::vector<float>(cols, 0.f));

    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            data[i][j] = 0.0;
        }
    }
    //data[rows][cols] = {0.f};
    float dummy;

}

void Matrix::set(size_t _row, size_t _col, float value) {
    data[_row][_col] = value;
    //std::cout << std::to_string(data[_row][_col]) << std::endl;

}

float Matrix::get(int _row, int _col){
    return data[_row][_col];

}

Matrix Matrix::T(void){
    // Transpose the matrix
    Matrix temp = Matrix(cols, rows);

    for (size_t i = 0; i < cols; ++i){
        for (size_t j = 0; j < rows; ++j){
            temp.set(i, j, data[j][i]);
        }
    }

    temp.rows = cols; //Swap them cos we transposed
    temp.cols = rows;

    return temp;
}

void Matrix::Pprint() {
    std::cout << "[" << std::ends;
    for (size_t i = 0; i < rows; ++i) {
        if (i > 0) {
            std::cout << " " << std::ends;
        }
        for (size_t j = 0; j < cols; ++j) {
            if (data[i][j] >= 0.0) {
                std::cout << " " << std::ends;
            }

            std::cout << std::to_string(data[i][j]) << std::ends;

            if (j < cols - 1) {
                std::cout << ", " << std::ends;
            } else {
                //std::cout << "|" << std::ends;

            }

            if ((j == cols - 1) && (i == rows - 1)) {
                std::cout << "]" << std::endl;
            }
        }
        std::cout << std::endl;
    }
}

std::vector<int> Matrix::Shape(void) {
    std::vector<int> shape = {0, 0};
    shape[0] = rows;
    shape[1] = cols;
    return shape;
}


Matrix::~Matrix() {

}