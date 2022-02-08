//
// Created by Snow on 2022.2.8.
//

#include "camera.h"

camera::camera() {
    auto aspect_ratio = 16.0 / 9.0;
    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    origin = point3(0, 0, 0);
    horizontal = vector3(viewport_width, 0.0, 0.0);
    vertical = vector3(0.0, viewport_height, 0.0);
    lower_left_corner = origin - horizontal / 2 - vertical / 2 - vector3(0, 0, focal_length);
}

ray camera::get_ray(double u, double v) const {
    return {origin, lower_left_corner + u * horizontal + v * vertical - origin};
}
