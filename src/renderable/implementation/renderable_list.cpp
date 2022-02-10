//
// Created by Snow on 2022.2.8.
//

#include "renderable_list.h"

renderable_list::renderable_list() = default;

renderable_list::renderable_list(shared_ptr<renderable> object) {
    add(object);
}

void renderable_list::clear() {
    objects.clear();
}

void renderable_list::add(shared_ptr<renderable> object) {
    objects.push_back(object);
}

bool renderable_list::hit(const ray &r, double t_min, double t_max, hit_record &rec) const {
    // 新的记录结构体
    // 之所以不用原来的那个，是因为光线可能没有击中物体
    // 所以原来的 rec 就没有任何用处
    hit_record temp_rec;
    // 默认不击中
    bool hit_anything = false;

    auto closest_so_far = t_max;
    // 遍历每一个物体，计算光线与该物体是否相交
    for (const auto &object : objects) {
        // 真正的计算部分
        if (object->hit(r, t_min, closest_so_far, temp_rec)) {
            // 击中置为 true
            hit_anything = true;
            // 记录参数解 t
            closest_so_far = temp_rec.t;
            // 记录信息
            rec = temp_rec;
        }
    }
    return hit_anything;
}
