//
// Created by Snow on 2022.2.8.
//

#ifndef RAYTRACERSIMPLIFIED_MATERIAL_H
#define RAYTRACERSIMPLIFIED_MATERIAL_H

#include "vector3.h"
#include "ray.h"
#include "renderable.h"

class material {
    virtual bool scatter(const ray &r_in, const hit_record &rec, vector3 &attenuation, ray &scattered) const = 0;
};


#endif //RAYTRACERSIMPLIFIED_MATERIAL_H
