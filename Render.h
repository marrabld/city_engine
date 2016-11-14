//
// Created by marrabld on 13/11/16.
//

#ifndef CITY_ENGINE_RENDER_H
#define CITY_ENGINE_RENDER_H

#include <GL/freeglut.h>
#include "Vector3D.h"

class Render{

public:
    void init(void);
    void display(void);

    //CAMERA
    Vector3D centerPosition = Vector3D(1.f, 1.f, 1.f);
    Vector3D eyePosition = Vector3D(0.f, 0.f, 0.f);
    Vector3D upVector = Vector3D(0.f, 0.f, 1.f);

    float zoom = 1;



};


#endif //CITY_ENGINE_RENDER_H
