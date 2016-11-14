//
// Created by marrabld on 13/11/16.
//

#include <GL/gl.h>
#include "Cube.h"

Cube::Cube() {
    Vector3D verts[24] = { Vector3D(0.5, -0.5, -0.5), Vector3D(0.5, 0.5, -0.5), Vector3D(-0.5, 0.5, -0.5), Vector3D(-0.5, -0.5, -0.5),
                               Vector3D(0.5, -0.5, 0.5), Vector3D(0.5, 0.5, 0.5), Vector3D(-0.5, 0.5, 0.5), Vector3D(-0.5, -0.5, 0.5),
                               Vector3D(0.5, -0.5, -0.5), Vector3D(0.5, 0.5, -0.5), Vector3D(0.5, 0.5, 0.5), Vector3D(0.5, -0.5, 0.5),
                               Vector3D(-0.5, -0.5, 0.5), Vector3D(-0.5, 0.5, 0.5), Vector3D(-0.5, 0.5, -0.5), Vector3D(-0.5, -0.5, -0.5),
                               Vector3D(0.5, 0.5, 0.5), Vector3D(0.5, 0.5, -0.5), Vector3D(-0.5, 0.5, -0.5), Vector3D(-0.5, 0.5, 0.5),
                               Vector3D(0.5, -0.5, -0.5), Vector3D(0.5, -0.5, 0.5), Vector3D(-0.5, -0.5, 0.5), Vector3D(-0.5, -0.5, -0.5)};

    Vector3D colours[6] = { Vector3D(1.0, 0.0, 0.0), Vector3D(0.0, 1.0, 0.0), Vector3D(0.0, 0.0, 1.0),
                               Vector3D(1.0, 1.0, 0.0), Vector3D(1.0, 0.0, 1.0), Vector3D(0.0, 1.0, 1.0)};

}


void Cube::draw() {
    for (int i = 0; i < 6; i++){
        glBegin(GL_POLYGON);
        glColor3f(colours[i].x, colours[i].y, colours[i].z);
        for (int j = 0; j < 4; j++){
            glVertex3f(verts[i*4 + j].x, verts[i*4 + j].y, verts[i*4 + j].z);
        }
        glEnd();
    }
}

//Vector3D Cube::getVerts() {
//    return verts;
//}