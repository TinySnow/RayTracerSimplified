//
// Created by Snow on 2022.2.7.
//

#include "sphere.h"

sphere::sphere() {
    this->radius = 0.0;
}
sphere::sphere(vector3 cen, double r,shared_ptr<material> m) : center(cen), radius(r),material_ptr(m) {}

bool sphere::hit(const ray &r, double t_min, double t_max, hit_record &rec) const {
    // 进行计算
    vector3 oc = r.get_origin() - center;
    auto a = r.get_direction().length_squared();
    auto half_b = dot(oc, r.get_direction());
    auto c = oc.length_squared() - radius * radius;
    // 计算判别式
    auto discriminant = half_b * half_b - a * c;
    if (discriminant < 0) {
        return false;
    }
    auto sqrtd = sqrt(discriminant);
    // 找到有效解，也就是求得的参数值在给定区间的解
    auto root = (-half_b - sqrtd) / a;
    if (root < t_min || t_max < root) {
        root = (-half_b + sqrtd) / a;
        if (root < t_min || t_max < root) {
            return false;
        }
    }
    // 记录该解，存入结构体
    rec.t = root;
    // 计算该光线，存入结构体
    rec.p = r.at(rec.t);
    // 计算面法相向量，存入结构体
//    rec.normal = (rec.p - center) / radius;
    vector3 outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);
    rec.material_ptr = material_ptr;

    return true;
}
