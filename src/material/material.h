//
// Created by Snow on 2022.2.10.
//

#ifndef RAYTRACERSIMPLIFIED_MATERIAL_H
#define RAYTRACERSIMPLIFIED_MATERIAL_H

#include "../core/ray.h"

struct hit_record;

class material {
public:
    /**
     * 此虚函数定义散射方式，根据材质的不同，会有不同的散射方式，需要交由具体的材质去实现。
     * @param r_in 入射光线方程
     * @param rec 光线与物体交点的有关信息
     * @param attenuation 光线衰减率
     * @param scattered 散射光线
     * @return 是否击中物体
     */
    virtual bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const = 0;
};


#endif //RAYTRACERSIMPLIFIED_MATERIAL_H
