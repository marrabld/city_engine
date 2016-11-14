//
// Created by marrabld on 13/11/16.
//

#ifndef CITY_ENGINE_SHAPES_H
#define CITY_ENGINE_SHAPES_H

#include "Vector3D.h"

class Shapes{

public:
    virtual void draw() = 0 ;
protected:
    Vector3D scale;
    Vector3D position;
    Vector3D forward;
    Vector3D verts[];
    Vector3D colours[];
};

#endif //CITY_ENGINE_SHAPES_H
