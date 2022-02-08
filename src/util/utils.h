//
// Created by Snow on 2022.2.8.
//

#ifndef RAYTRACERSIMPLIFIED_UTILS_H
#define RAYTRACERSIMPLIFIED_UTILS_H

#include <cmath>
#include <limits>
#include <memory>

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

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

#endif //RAYTRACERSIMPLIFIED_UTILS_H
