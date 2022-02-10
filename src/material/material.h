//
// Created by Snow on 2022.2.10.
//

#ifndef RAYTRACERSIMPLIFIED_MATERIAL_H
#define RAYTRACERSIMPLIFIED_MATERIAL_H

#include "../core/ray.h"

struct hit_record;

class material {
public:
    virtual bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const = 0;
};


#endif //RAYTRACERSIMPLIFIED_MATERIAL_H
