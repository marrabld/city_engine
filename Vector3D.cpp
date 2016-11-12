//
// Created by marrabld on 7/11/16.
//

#include <cmath>
#include <iostream>
#include "Vector3D.h"

Vector3D::Vector3D() {

    x = 0;
    y = 0;
    z = 0;

}

Vector3D::~Vector3D() {

}

Vector3D::Vector3D(float xCoord, float yCoord, float zCoord) {
    x = xCoord;
    y = yCoord;
    z = zCoord;
}

Vector3D::Vector3D(const Vector3D& v) {
    x = v.x;
    y = v.y;
    z = v.z;
}

Vector3D Vector3D::Normalize() {
    float mag;

    mag = sqrt((x*x + y*y + z*z));
    x = x / mag;
    y = y / mag;
    z = z / mag;
}

void Vector3D::Pprint(){
    std::cout << "[" <<
              std::to_string(x) <<
              ", " <<
              std::to_string(y) <<
              ", " <<
              std::to_string(z) <<
              "]" <<
              std::endl;
}


Vector3D& Vector3D::operator=(const Vector3D& rhs){
    if (this != &rhs){
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
    }

    return *this;
}

bool Vector3D::operator==(const Vector3D &rhs) {
    return this->x == rhs.x and this->y == rhs.y and this->z == rhs.z;
}
