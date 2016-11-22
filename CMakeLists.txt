cmake_minimum_required(VERSION 3.6)
project(city_engine)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Vector3D.h Vector3D.cpp Math.cpp Math.h Matrix.cpp Matrix.h tests/tests.cpp tests/tests.h Render.cpp Render.h Shapes.cpp Shapes.h Cube.cpp Cube.h common/LoadShaders.cpp common/LoadShaders.h)
add_executable(city_engine ${SOURCE_FILES})

target_link_libraries(
        ${PROJECT_NAME}
        ${OPENGL_gl_LIBRARY}
        ${GLUT_LIBRARIES}
        ${OPENGL_LIBRARIES}
        ${GLUT_LIBRARY} glfw GL GLU GLEW)