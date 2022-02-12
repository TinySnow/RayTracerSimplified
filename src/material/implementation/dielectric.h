//
// Created by Snow on 2022.2.12.
//

#ifndef RAYTRACERSIMPLIFIED_DIELECTRIC_H
#define RAYTRACERSIMPLIFIED_DIELECTRIC_H

#include "../material.h"
#include "../../core/vector3.h"
#include "../../renderable/renderable.h"

class dielectric : public material {

public:
    /**
     * 材质折射率。
     */
    double refractive_index_ratio;

public:
    /**
     * 满参构造函数。
     * @param rix 折射率
     */
    dielectric(double rix);
    /**
     * 散射的具体实现。针对于电解质（能同时发生折射和反射的物质）的折射。
     * @param r_in 入射光线向量方程
     * @param rec 记录结构体
     * @param attenuation
     * @param scattered
     * @return 折射光线的方向向量
     */
    bool scatter(const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered) const override;
};


#endif //RAYTRACERSIMPLIFIED_DIELECTRIC_H
