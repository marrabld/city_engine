//
// Created by marrabld on 13/11/16.
//

#include "Render.h"

void Render::init() {

    glClearColor(1.f, 1.f, 1.f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}

void Render::display() {
    //  Clear screen and Z-buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();

    gluLookAt(eyePosition.x, eyePosition.y, eyePosition.z, centerPosition.x, centerPosition.y, centerPosition.z, upVector.x, upVector.y, upVector.z);

    glScalef(zoom, zoom, zoom);

    //drawDotProduct(Vector3D(.5, .5, 0), Vector3D(1, 0, 0));

    //drawCrossProduct(Vector3D(-1, -4, 2), Vector3D(4, 9, 2));

    //drawCube(cubePosition);

    glFlush();
    glutSwapBuffers();
}