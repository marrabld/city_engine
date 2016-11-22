//
// Created by marrabld on 20/11/16.
//

#ifndef CITY_ENGINE_LOADSHADERS_H
#define CITY_ENGINE_LOADSHADERS_H

//Graphics
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <string>

class LoadShaders {
public:
    LoadShaders();
    GLuint loadShaders(const char * vertex_file_path, const char * fragment_file_path);

};


#endif //CITY_ENGINE_LOADSHADERS_H
