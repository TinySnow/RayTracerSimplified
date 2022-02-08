cmake_minimum_required(VERSION 3.17)
project(RayTracerSimplified)

set(CMAKE_CXX_STANDARD 14)

add_executable(RayTracerSimplified src/main.cpp src/core/vector3.cpp src/core/vector3.h src/core/ray.cpp src/core/ray.h src/core/renderable.cpp src/core/renderable.h src/geometry/sphere.cpp src/geometry/sphere.h src/core/renderable_list.cpp src/core/renderable_list.h src/util/utils.cpp src/util/utils.h src/core/camera.cpp src/core/camera.h)