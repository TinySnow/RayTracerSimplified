//
// Created by Snow on 2022.2.8.
//

#ifndef RAYTRACERSIMPLIFIED_CAMERA_H
#define RAYTRACERSIMPLIFIED_CAMERA_H
#include "vector3.h"
#include "ray.h"

class camera {
private:
    point3 origin;
    point3 lower_left_corner;
    vector3 horizontal;
    vector3 vertical;
public:
    camera();
    ray get_ray(double u, double v) const;
};


#endif //RAYTRACERSIMPLIFIED_CAMERA_H
