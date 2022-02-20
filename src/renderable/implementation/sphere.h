//
// Created by Snow on 2022.2.7.
//

#ifndef RAYTRACERSIMPLIFIED_SPHERE_H
#define RAYTRACERSIMPLIFIED_SPHERE_H

#include "../renderable.h"
#include "../../core/vector3.h"

class sphere : public renderable {
public:
    /**
     * 球体球心坐标点。
     */
    vector3 center;
    /**
     * 球体半径值。
     */
    double radius;
    /**
     * 材质有关的指针。<p>
     * 所有同一个材质的物体，共享一个指针。
     */
    shared_ptr<material> material_ptr;

public:
    /**
     * 无参构造函数。
     */
    sphere();

    /**
     * 满参构造函数。
     * @param cen 球体球心坐标点
     * @param r 球体半径值
     * @param m 表面材质，决定如何散射
     */
    sphere(vector3 cen, double r, shared_ptr<material> m);

    /**
     * 继承自 renderable 的虚函数，用于计算光线和 renderable 对象是否击中。
     * @param r 光线的向量方程
     * @param t_min 确定求得解 t 是否有效的区间下限
     * @param t_max 确定求得解 t 是否有效的区间上限
     * @param rec 记录信息的结构体，初期没有值，各成员在此函数内部赋值
     * @return 返回光线与几何体是否相交
     */
    bool hit(const ray &r, double t_min, double t_max, hit_record &rec) const override;
};


#endif //RAYTRACERSIMPLIFIED_SPHERE_H
