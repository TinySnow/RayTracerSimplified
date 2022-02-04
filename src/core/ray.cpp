//
// Created by Snow on 2022.2.4.
//

#include "ray.h"


ray::ray() = default;


ray::ray(const vector3 &origin, const vector3 &direction) : origin(origin), direction(direction) {}


vector3 ray::get_origin() const {
    return origin;
}


vector3 ray::get_direction() const {
    return direction;
}


vector3 ray::at(double t) const {
    return origin + t * direction;
}

