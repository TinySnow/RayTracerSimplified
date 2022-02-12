//
// Created by Snow on 2022.2.12.
//

#include "dielectric.h"

dielectric::dielectric(double rix) : refractive_index_ratio(rix) {

}

bool dielectric::scatter(const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered) const {

    attenuation = color(1.0, 1.0, 1.0);
    // 如果是从外面折射进来，说明是空气比介质，也即小折射率比大折射率，而空气默认为 1，为分子，所以就是 1/rix
    double refraction_ratio = rec.front_face ? (1.0 / refractive_index_ratio) : refractive_index_ratio;
    // 获取入射光线方向向量的单位向量
    vector3 unit_direction = unit_vector(r_in.get_direction());
    // 计算入射光线与法线夹角的余弦值，这个公式要通过数学推导，比较复杂，不做说明
    double cos_theta = fmin(dot(-unit_direction, rec.normal), 1.0);
    // 计算正弦值，利用上述余弦值：sin^2 = 1 - cos^2
    double sin_theta = sqrt(1.0 - cos_theta * cos_theta);
    // 当发现折射率之比和正弦值之积（也就是折射角的正弦值）大于 1 的话（当然正弦值是不可能大于 1 的）
    // 我们就认为光线从高折射率射入低折射率时，发生了全反射
    bool cannot_refract = refraction_ratio * sin_theta > 1.0;
    vector3 direction;
    // 判断是折射还是全反射
    if (cannot_refract) {
        direction = reflect(unit_direction, rec.normal);
    } else {
        direction = refract(unit_direction, rec.normal, refraction_ratio);
    }
    // 生成散射光线的方程，此处是散射，因为不确定是发生了折射还是全反射
    scattered = ray(rec.p, direction);
    return true;
}
