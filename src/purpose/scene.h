//
// Created by Snow on 2022.2.20.
//

#ifndef RAYTRACERSIMPLIFIED_SCENE_H
#define RAYTRACERSIMPLIFIED_SCENE_H

#include "../renderable/implementation/renderable_list.h"
#include "../renderable/implementation/sphere.h"
#include "../material/implementation/dielectric.h"
#include "../material/implementation/lambertian.h"
#include "../material/implementation/metal.h"

renderable_list random_scene();

#endif //RAYTRACERSIMPLIFIED_SCENE_H
