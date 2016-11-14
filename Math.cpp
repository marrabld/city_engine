//
// Created by marrabld on 7/11/16.
//

#include <complex>
#include "Math.h"

namespace Math{
    Vector3D add(Vector3D a, Vector3D b){
        return Vector3D(a.x + b.x, a.y + b.y, a.z + b.z);
    }
    Vector3D add(float a, Vector3D b){
        Vector3D z = Vector3D(b.x + a, b.y + a, b.z + a);
        return z;
    }
    Matrix add(Matrix a, Matrix b) {

        Matrix z = Matrix(a.rows, a.cols);

        for (int i = 0; i < a.rows; i++) {
            for (int j = 0; j < a.cols; j++) {
                z.set(i, j, a.get(i, j) + b.get(i, j));
            }
        }
        return z;
    }
    Matrix add(float a, Matrix b){
        Matrix v = Matrix(b.rows, b.cols);
        for (int i=0; i < b.rows; i++){
            for (int j=0; j < b.cols; j++){
                v.data[i][j] = b.data[i][j] + a;
            }
        }
        return v;
    }

    Vector3D multiply(Vector3D a, Vector3D b){
    return Vector3D(a.x * b.x, a.y * b.y, a.z * b.z);

    }
    Vector3D multiply(float a, Vector3D b){
        Vector3D z = Vector3D(b.x * a, b.y * a, b.z * a);
        return z;
    }
    Vector3D multiply(Matrix a, Vector3D b){
        Vector3D z = Vector3D();
        //for (int i=0; i < a.rows; i++){
            //for (int j=0; j < a.cols; j++){
        z.x = a.data[0][0] * b.y +a.data[0][1] * b.x + a.data[0][2] * b.z;
        z.y = a.data[1][0] * b.y +a.data[1][1] * b.x + a.data[1][2] * b.z;
        z.x = a.data[2][0] * b.y +a.data[2][1] * b.x + a.data[2][2] * b.z;

        return z;
            //}

        //}


    }
    Matrix multiply(Matrix a, Matrix b){

        Matrix z = Matrix(a.rows, b.cols);

        for (int i=0; i < a.rows; i++){
            for(int j=0; j < b.cols; j++){
                for (int k=0; k < a.cols; k++){
                    z.data[i][j] += (a.data[i][k] * b.data[k][j]);
                }
            }
        }
        return z;
    }
    Matrix multiply(float a, Matrix b){
        Matrix v = Matrix(b.rows, b.cols);
        for (int i=0; i < b.rows; i++){
            for (int j=0; j < b.cols; j++){
                v.data[i][j] = b.data[i][j] * a;
            }
        }
        return v;
    }

    Vector3D subtract(Vector3D a, Vector3D b){
        return Vector3D(a.x - b.x, a.y - b.y, a.z - b.z);
    }
    Vector3D subtract(float a, Vector3D b){
        Vector3D z = Vector3D(b.x - a, b.y - a, b.z - a);
        return z;
    }
    Matrix subtract(Matrix a, Matrix b){
        Matrix z = Matrix(a.rows, a.cols);

        for (int i = 0; i < a.rows; i++) {
            for (int j = 0; j < a.cols; j++) {
                z.set(i, j, a.get(i, j) - b.get(i, j));
            }
        }
        return z;
    }
    Matrix subtract(float a, Matrix b){
        Matrix v = Matrix(b.rows, b.cols);
        for (int i=0; i < b.rows; i++){
            for (int j=0; j < b.cols; j++){
                v.data[i][j] = b.data[i][j] - a;
            }
        }
        return v;
    }

    Vector3D cross(Vector3D a, Vector3D b){
        Vector3D _cross = Vector3D();
        _cross.x = (a.y * b.z) - (a.z * b.y);
        _cross.y = (a.z * b.x) - (a.x * b.z);
        _cross.z = (a.x * b.y) - (a.y * b.x);

        return _cross;
    }

    float dot(Vector3D a, Vector3D b){
        return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
    }
    float magnitude(Vector3D a){
        return sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z));
    }
}
