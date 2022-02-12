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
    /**
     * 金属表面的模糊度。<p>
     * 越模糊，其数值越大，最大为 1。<p>
     * 越模糊，也代表其金属球半径越大。<p>
     * 我们将在漫反射的逻辑内，也即单位圆内随机选取一点时使用这个值，所以最大为 1。
     */
    double fuzz;
public:

    metal(const color& a,double f);
    /**
     * 散射的具体实现。针对于金属材质。
     * @param r_in
     * @param rec
     * @param attenuation
     * @param scattered
     * @return
     */
    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override;
};
#endif //RAYTRACERSIMPLIFIED_METAL_H
