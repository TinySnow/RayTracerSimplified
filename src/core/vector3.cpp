//
// Created by Snow on 2022.2.3.
//

#include "vector3.h"

vector3::vector3() : e{0, 0, 0} {}

vector3::vector3(double e0, double e1, double e2) : e{e0, e1, e2} {}

double vector3::x() const { return e[0]; }

double vector3::y() const { return e[1]; }

double vector3::z() const { return e[2]; }

double vector3::length() const {
    return sqrt(length_squared());
}

double vector3::length_squared() const {
    return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

vector3 vector3::operator-() const { return {-e[0], -e[1], -e[2]}; }

double vector3::operator[](int i) const { return e[i]; }

double &vector3::operator[](int i) { return e[i]; }

vector3 &vector3::operator+=(const vector3 &v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}

vector3 &vector3::operator*=(const double t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

vector3 &vector3::operator/=(const double t) {
    return *this *= 1 / t;
}

void vector3::write_color(std::ostream &out) {
    // 写入每个值映射在 [0, 255] 区间范围内的颜色组件
    out << static_cast<int>(255.999 * e[0]) << ' '
        << static_cast<int>(255.999 * e[1]) << ' '
        << static_cast<int>(255.999 * e[2]) << '\n';

}


