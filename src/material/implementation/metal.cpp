//
// Created by Snow on 2022.2.10.
//

#include "metal.h"

metal::metal(const color &a) : albedo(a) {

}

bool metal::scatter(const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered) const {
    // 获取反射光线的方向向量
    vector3 reflected = reflect(unit_vector(r_in.get_direction()), rec.normal);
    // 求得反射光线
    scattered = ray(rec.p, reflected);
    // 显示镜面反射的颜色
    attenuation = albedo;
    // 看反射光线和法线向量是否在同一个方向
    return (dot(scattered.get_direction(), rec.normal) > 0);
}

