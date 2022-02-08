//
// Created by Snow on 2022.2.8.
//

// TODO 更新 README.md

#ifndef RAYTRACERSIMPLIFIED_RENDERABLE_LIST_H
#define RAYTRACERSIMPLIFIED_RENDERABLE_LIST_H

#include "renderable.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class renderable_list : public renderable {
public:
    /**
     * vector 是一个类似数组的结构类型, 可以存储任意指定的类型。<p>
     * 此处用来存储用智能指针包裹的 renderable 对象。<p>
     */
    std::vector<shared_ptr<renderable>> objects;
public:
    /**
     * 无参构造函数。
     */
    renderable_list();
    /**
     * 满参构造函数，传入 renderable 对象即可，此构造函数会自动将其推进 vector 队列。
     * @param object
     */
    renderable_list(shared_ptr<renderable> object);
    /**
     * 清除所有 renderable 对象。
     */
    void clear();
    /**
     * 此函数为满参构造函数实际执行的函数，调用的是 vector 自带的 push_back 函数，将其推入 vector 队列。
     * @param object
     */
    void add(shared_ptr<renderable> object);
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


#endif //RAYTRACERSIMPLIFIED_RENDERABLE_LIST_H
