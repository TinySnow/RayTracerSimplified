//
// Created by Snow on 2022.2.3.
//

#ifndef RAYTRACERSIMPLIFIED_VECTOR3_H
#define RAYTRACERSIMPLIFIED_VECTOR3_H

#include <iostream>
#include <cmath>

using std::sqrt;

class vector3 {

public:
    // 坐标值
    double e[3];

public:
    /* 以下构造函数和方法均在 .cpp 文件内有详细注释 */

    vector3();

    vector3(double e0, double e1, double e2);

    double x() const;

    double y() const;

    double z() const;

    double length() const;

    double length_squared() const;

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

// 计算点乘
inline double dot(const vector3 &u, const vector3 &v);

// 计算叉乘
inline vector3 cross(const vector3 &u, const vector3 &v);

// 计算单位向量
inline vector3 unit_vector(vector3 v);

/* 以下均为后续方便使用进行的运算符重载 */

inline std::ostream &operator<<(std::ostream &out, const vector3 &v);

inline vector3 operator+(const vector3 &u, const vector3 &v);

inline vector3 operator-(const vector3 &u, const vector3 &v);

inline vector3 operator*(const vector3 &u, const vector3 &v);

inline vector3 operator*(double t, const vector3 &v);

inline vector3 operator*(const vector3 &v, double t);

inline vector3 operator/(vector3 v, double t);

#endif //RAYTRACERSIMPLIFIED_VECTOR3_H
