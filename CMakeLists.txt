cmake_minimum_required(VERSION 3.17)
project(RayTracerSimplified)

set(CMAKE_CXX_STANDARD 14)

add_executable(RayTracerSimplified src/main.cpp src/core/vector3.cpp src/core/vector3.h src/core/ray.cpp src/core/ray.h src/renderable/renderable.cpp src/renderable/renderable.h src/renderable/implementation/sphere.cpp src/renderable/implementation/sphere.h src/renderable/implementation/renderable_list.cpp src/renderable/implementation/renderable_list.h src/util/utils.cpp src/util/utils.h src/core/camera.cpp src/core/camera.h src/material/material.cpp src/material/material.h src/material/implementation/lambertian.cpp src/material/implementation/lambertian.h src/material/implementation/metal.cpp src/material/implementation/metal.h src/material/implementation/dielectric.cpp src/material/implementation/dielectric.h src/purpose/scene.cpp src/purpose/scene.h)

