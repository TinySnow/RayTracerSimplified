//
// Created by Snow on 2022.2.10.
//

#ifndef RAYTRACERSIMPLIFIED_METAL_H
#define RAYTRACERSIMPLIFIED_METAL_H

#include "../../renderable/renderable.h"
#include "../material.h"

class metal : public material {
public:
    color albedo;
public:

    metal(const color& a);

    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override;
};
#endif //RAYTRACERSIMPLIFIED_METAL_H
