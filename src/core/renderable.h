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
    /**
     * 是否从外侧射入球体。<p>
     */
    bool front_face;

    /**
     * 此内联函数决定了面法相向量的方向。依据是是否从外侧射入球体。<p>
     * 如果是，则法线向量朝外，为正；如果不是，则法线向量朝内，为负。
     * @param r 光线的向量方程
     * @param outward_normal 面法相向量，此时没有确定符号，经过此函数作用会确定符号
     */
    inline void set_face_normal(const ray &r, const vector3 &outward_normal) {
        front_face = dot(r.get_direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class renderable {
public:
    /**
     * 接受四个参数。<p>
     * 根据光线的方程，求出该光线与几何体是否相交。<p>
     * @param r 光线的向量方程
     * @param t_min 确定求得解 t 是否有效的区间下限
     * @param t_max 确定求得解 t 是否有效的区间上限
     * @param rec 记录信息的结构体，初期没有值，各成员在此函数内部赋值
     * @return 返回光线与几何体是否相交
     */
    virtual bool hit(const ray &r, double t_min, double t_max, hit_record &rec) const = 0;
};


#endif //RAYTRACERSIMPLIFIED_RENDERABLE_H
