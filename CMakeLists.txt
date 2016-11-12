cmake_minimum_required(VERSION 3.6)
project(city_engine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Vector3D.h Vector3D.cpp Math.cpp Math.h Matrix.cpp Matrix.h tests/tests.cpp tests/tests.h)
add_executable(city_engine ${SOURCE_FILES})