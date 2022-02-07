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
    return false;
}
