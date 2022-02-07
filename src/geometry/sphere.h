//
// Created by Snow on 2022.2.7.
//

#ifndef RAYTRACERSIMPLIFIED_SPHERE_H
#define RAYTRACERSIMPLIFIED_SPHERE_H

#include "../core/renderable.h"
#include "../core/vector3.h"

class sphere: public renderable {
public:
    vector3 center;
    double radius;

public:
    sphere();
    sphere(vector3 cen, double r);

    bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override;
};


#endif //RAYTRACERSIMPLIFIED_SPHERE_H
