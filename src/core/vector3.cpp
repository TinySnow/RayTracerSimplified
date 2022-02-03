//
// Created by Snow on 2022.2.3.
//

#include "vector3.h"

/**
 * 空构造函数
 */
vector3::vector3() : e{0, 0, 0} {}

/**
 * 特定参数构造函数
 * @param e0 横坐标（x 轴）
 * @param e1 纵坐标（y 轴）
 * @param e2 竖坐标（z 轴）
 */
vector3::vector3(double e0, double e1, double e2) : e{e0, e1, e2} {}

/**
 * 常函数，返回横坐标（x 轴）
 * @return 横坐标（x 轴）
 */
double vector3::x() const { return e[0]; }

/**
 * 常函数，返回纵坐标（y 轴）
 * @return 纵坐标（y 轴）
 */
double vector3::y() const { return e[1]; }

/**
 * 常函数，返回竖坐标（z 轴）
 * @return 竖坐标（z 轴）
 */
double vector3::z() const { return e[2]; }

/**
 * 计算向量长度
 * @return 向量长度
 */
double vector3::length() const {
    return sqrt(length_squared());
}

/**
 * 计算向量长度平方，如果返回向量长度，则需要开方
 * @return 向量长度的平方
 */
double vector3::length_squared() const {
    return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

/**
 * 计算两向量点乘积
 * [a, b, c] · [x, y, z] = ax + by + cz
 * @param u 待点乘向量
 * @param v 待点乘向量
 * @return 点乘结果
 */
inline double dot(const vector3 &u, const vector3 &v) {
    return u.e[0] * v.e[0]
           + u.e[1] * v.e[1]
           + u.e[2] * v.e[2];
}

/**
 * 计算向量叉乘结果
 * @param u 待叉乘向量
 * @param v 待叉乘向量
 * @return 叉乘结果
 */
inline vector3 cross(const vector3 &u, const vector3 &v) {
    return {u.e[1] * v.e[2] - u.e[2] * v.e[1],
            u.e[2] * v.e[0] - u.e[0] * v.e[2],
            u.e[0] * v.e[1] - u.e[1] * v.e[0]};
}

/**
 * 计算单位向量
 * @param v 待计算向量
 * @return 单位向量
 */
inline vector3 unit_vector(vector3 v) {
    return v / v.length();
}

inline std::ostream &operator<<(std::ostream &out, const vector3 &v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vector3 operator+(const vector3 &u, const vector3 &v) {
    return {u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]};
}

inline vector3 operator-(const vector3 &u, const vector3 &v) {
    return {u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]};
}

inline vector3 operator*(const vector3 &u, const vector3 &v) {
    return {u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]};
}

inline vector3 operator*(double t, const vector3 &v) {
    return {t * v.e[0], t * v.e[1], t * v.e[2]};
}

inline vector3 operator*(const vector3 &v, double t) {
    return t * v;
}

inline vector3 operator/(vector3 v, double t) {
    return (1 / t) * v;
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


