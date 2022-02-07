//
// Created by Snow on 2022.2.7.
//

#ifndef RAYTRACERSIMPLIFIED_RENDERABLE_H
#define RAYTRACERSIMPLIFIED_RENDERABLE_H
#include "ray.h"
#include "vector3.h"
/**
 * 此结构体用于记录光线与球体相互作用产生的信息。
 */
struct hit_record {
    /**
     * 光线方程。
     */
    vector3 p;
    /**
     * 如果直线与球体相交，则会在交点处产生一个面法线向量。<p>
     * 该字段记录法线向量的信息。
     */
    vector3 normal;
    /**
     * 光线与球体是否相交求得的参数解。<p>
     * 它确定了光线的具体位置。
     */
    double t;
};

class renderable {
public:
    /**
     * 接受四个参数。<p>
     * 根据光线的方程，求出该光线与几何体是否相交。<p>
     * @param r 光线的向量方程
     * @param t_min 确定求得解 t 是否有效的区间下限
     * @param t_max 确定求得解 t 是否有效的区间上限
     * @param rec 记录信息的结构体，初期可以只用填写球心位置，各成员以后再赋值
     * @return 返回光线与几何体是否相交
     */
    virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};


#endif //RAYTRACERSIMPLIFIED_RENDERABLE_H
