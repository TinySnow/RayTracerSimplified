//
// Created by Snow on 2022.2.10.
//

#include "lambertian.h"

lambertian::lambertian(const color &a) : albedo(a) {

}

bool lambertian::scatter(const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered) const {
    // 漫反射光线的方向向量
    auto scatter_direction = rec.normal + random_unit_vector();

    // 判断漫反射向量
    // 如果生成的随机单位向量刚好和法线向量相反，则两者之和就几乎为零，即会导致零散射方向向量
    // 有时会致使无穷大和 NaN
    if (scatter_direction.near_zero()) {
        scatter_direction = rec.normal;
    }
    // 漫反射光线
    scattered = ray(rec.p, scatter_direction);
    // 漫反射后的颜色
    attenuation = albedo;
    return true;
}
