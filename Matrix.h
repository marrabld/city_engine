//
// Created by marrabld on 8/11/16.
//

#ifndef GAME_ENGINE_MATRIX_H
#define GAME_ENGINE_MATRIX_H

#include <glob.h>
#include <vector>

class Matrix{

public:
    int rows;
    int cols;

    //float data[2][2];
    std::vector<std::vector<float>> data;
    //data.resize(rows, std::vector<float>(cols, 0.f));

    Matrix();
    Matrix(int _rows, int cols);
    void set(size_t _row, size_t _col, float value);
    float get(int _row, int _col);

    // Methodds
    void Pprint(void);
    std::vector<int> Shape(void);

    Matrix T(void);
    ~Matrix();

};

#endif //GAME_ENGINE_MATRIX_H
