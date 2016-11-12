//
// Created by marrabld on 7/11/16.
//

#include <complex>
#include "Math.h"

namespace Math{
    Vector3D add(Vector3D a, Vector3D b){
        return Vector3D(a.x + b.x, a.y + b.y, a.z + b.z);
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
    Vector3D multiply(Vector3D a, Vector3D b){
    return Vector3D(a.x * b.x, a.y * b.y, a.z * b.z);

    }

    Vector3D subtract(Vector3D a, Vector3D b){
        return Vector3D(a.x - b.x, a.y - b.y, a.z - b.z);
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
