//
// Created by Snow on 2022.2.4.
//

#ifndef RAYTRACERSIMPLIFIED_RAY_H
#define RAYTRACERSIMPLIFIED_RAY_H

#include "vector3.h"
class ray {
public:

    /**
     * 坐标原点
     */
    vector3 origin;

    /**
     * 方向向量
     */
    vector3 direction;

public:

    /**
     * 空构造函数
     */
    ray();

    /**
     * 满参构造函数
     * @param origin
     * @param direction
     */
    ray(const vector3 &origin, const vector3 &direction);

    /**
     * 获取元向量
     * @return
     */
    vector3 get_origin() const;

    /**
     * 获取方向向量
     * @return
     */
    vector3 get_direction() const;

    /**
     * 计算光线在参数 t 处位置的向量
     * @param t 参数 t 大小决定该向量有多长，正负决定该向量的方向
     * @return 光线向量
     */
    vector3 at(double t) const;

};

#endif //RAYTRACERSIMPLIFIED_RAY_H
