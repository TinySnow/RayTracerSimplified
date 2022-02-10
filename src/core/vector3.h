//
// Created by Snow on 2022.2.3.
//

#ifndef RAYTRACERSIMPLIFIED_VECTOR3_H
#define RAYTRACERSIMPLIFIED_VECTOR3_H

#include <iostream>
#include <cmath>
#include "../util/utils.h"

using std::sqrt;

class vector3 {

public:
    /**
     * 坐标值
     */
    double e[3];

public:
    /**
     * 空构造函数
     */
    vector3();

    /**
     * 特定参数构造函数
     * @param e0 横坐标（x 轴）
     * @param e1 纵坐标（y 轴）
     * @param e2 竖坐标（z 轴）
     */
    vector3(double e0, double e1, double e2);

    /**
     * 常函数，返回横坐标（x 轴）
     * @return 横坐标（x 轴）
     */
    double x() const;

    /**
     * 常函数，返回纵坐标（y 轴）
     * @return 纵坐标（y 轴）
     */
    double y() const;

    /**
     * 常函数，返回竖坐标（z 轴）
     * @return 竖坐标（z 轴）
     */
    double z() const;

    /**
     * 计算向量长度
     * @return 向量长度
     */
    double length() const;

    /**
     * 计算向量长度平方，如果返回向量长度，则需要开方
     * @return 向量长度的平方
     */
    double length_squared() const;

    /**
     * 写入该点的颜色值
     * @param out 重定向输出流，以免手动操作
     * @param samples_per_pixel
     */
    void write_color(std::ostream &out, int samples_per_pixel);

    /**
     * 生成任意随机数，用该随机数生成坐标点
     * @return 坐标点
     */
    inline static vector3 random() {
        return {random_double(), random_double(), random_double()};
    }

    /**
     * 生成受限于区间内的随机数，用该随机数生成坐标点
     * @param min 区间下限
     * @param max 区间上限
     * @return 区间内坐标点
     */
    inline static vector3 random(double min, double max) {
        return {random_double(min, max), random_double(min, max), random_double(min, max)};
    }

    /**
     * 如果向量在各个维度上都非常接近于零，返回 true
     * @return 见上
     */
    bool near_zero() const {
        const auto s = 1e-8;
        return (fabs(e[0]) < s) && (fabs(e[1]) < s) && (fabs(e[2]) < s);
    }

    /* 以下运算符重载暂不说明 */

    vector3 operator-() const;

    double operator[](int i) const;

    double &operator[](int i);

    vector3 &operator+=(const vector3 &v);

    vector3 &operator*=(double t);

    vector3 &operator/=(double t);

};

// point3 专门用来表示三维点位置坐标
using point3 = vector3;

// color 专门用来表示颜色 RGB 值
using color = vector3;

/* 以下均为后续方便使用进行的运算符重载 */

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

/**
 * 此函数用于从相切的单位圆内选出一点，作为漫反射的目的点
 * @return 返回该目标点
 */
inline vector3 random_in_unit_sphere() {
    while (true) {
        // 受限于区间内的坐标点
        auto p = vector3::random(-1, 1);
        // 如果长度大于 1，说明不在单位球内，重新生成
        if (p.length_squared() >= 1) continue;
        return p;
    }
}

/**
 * 生成随机单位向量
 * @return 随机单位向量
 */
inline vector3 random_unit_vector() {
    return unit_vector(random_in_unit_sphere());
}

/**
 * 根据反射模型得出反射公式
 * @param v
 * @param n
 * @return
 */
inline vector3 reflect(const vector3 &v, const vector3 &n) {
    return v - 2 * dot(v, n) * n;
}


#endif //RAYTRACERSIMPLIFIED_VECTOR3_H
