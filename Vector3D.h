//
// Created by marrabld on 7/11/16.
//

#ifndef GAME_ENGINE_VECTOR3D_H
#define GAME_ENGINE_VECTOR3D_H


class Vector3D {
public:
    Vector3D();
    Vector3D(float xCoord, float yCoord, float zCoord);
    Vector3D(const Vector3D& v);
    Vector3D Normalize();
    void Pprint();
    ~Vector3D();

    float x;
    float y;
    float z;
    Vector3D& operator=(const Vector3D& rhs);
    bool operator ==(const Vector3D& rhs);



};


#endif //GAME_ENGINE_VECTOR3D_H
