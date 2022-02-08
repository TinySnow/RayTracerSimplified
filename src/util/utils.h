//
// Created by Snow on 2022.2.8.
//

#ifndef RAYTRACERSIMPLIFIED_UTILS_H
#define RAYTRACERSIMPLIFIED_UTILS_H

#include <cmath>
#include <limits>
#include <memory>
#include <random>

using std::shared_ptr;
using std::make_shared;
using std::sqrt;
using std::random_device;

/**
 * 无穷
 */
const double infinity = std::numeric_limits<double>::infinity();
/**
 * π
 */
const double pi = 3.1415926535897932385;

/**
 * 将 角度 切换成 弧度
 * @param degrees 角度值
 * @return 弧度值
 */
inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

/**
 * 生成随机数
 * @return 随机数
 */
inline double random_double() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}
/**
 * 生成在区间范围内的随机数
 * @param min 区间下限
 * @param max 区间上限
 * @return 随机数
 */
inline double random_double(double min, double max) {
    static std::uniform_real_distribution<double> distribution(min, max);
    static std::mt19937 generator;
    return distribution(generator);
}

/**
 * 将 x 的值限制在区间范围内
 * @param x 需要限制的值
 * @param min 区间下限
 * @param max 区间上限
 * @return 区间范围内的有效值
 */
inline double clamp(double x, double min, double max) {
    if (x < min) return min;
    if (x > max) return max;
    return x;
}

#endif //RAYTRACERSIMPLIFIED_UTILS_H
