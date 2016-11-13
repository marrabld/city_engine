//
// Created by marrabld on 7/11/16.
//

#ifndef GAME_ENGINE_MATH_H
#define GAME_ENGINE_MATH_H

#include "Vector3D.h"
#include "Matrix.h"

namespace Math{
    Vector3D add(Vector3D a, Vector3D b);
    Matrix add(Matrix a, Matrix b);

    Vector3D subtract(Vector3D a, Vector3D b);
    Matrix subtract(Matrix a, Matrix b);

    Vector3D multiply(Vector3D a, Vector3D b);
    Matrix multiply(Matrix a, Matrix b);

    Vector3D cross(Vector3D a, Vector3D b);

    float dot(Vector3D a, Vector3D b);
    float magnitude(Vector3D a);

}

#endif //GAME_ENGINE_MATH_H
