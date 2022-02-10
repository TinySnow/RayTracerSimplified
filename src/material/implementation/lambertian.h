//
// Created by Snow on 2022.2.10.
//

#ifndef RAYTRACERSIMPLIFIED_LAMBERTIAN_H
#define RAYTRACERSIMPLIFIED_LAMBERTIAN_H


#include "../../core/ray.h"
#include "../material.h"
#include "../../renderable/renderable.h"

class lambertian : public material {
public:
    /**
     * 漫反射后的颜色。
     */
    color albedo;
public:
    /**
     * 满参构造函数。
     * @param a 漫反射反射率
     */
    lambertian(const color &a);
    /**
     * 漫反射材质的具体散射实现，参数与虚函数相同。
     * @param r_in
     * @param rec
     * @param attenuation
     * @param scattered
     * @return
     */
    bool scatter(const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered) const override;
};

#endif //RAYTRACERSIMPLIFIED_LAMBERTIAN_H
