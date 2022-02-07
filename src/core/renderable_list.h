//
// Created by Snow on 2022.2.8.
//

#ifndef RAYTRACERSIMPLIFIED_RENDERABLE_LIST_H
#define RAYTRACERSIMPLIFIED_RENDERABLE_LIST_H

#include "renderable.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class renderable_list : public renderable {
public:
    std::vector<shared_ptr<renderable>> objects;
public:
    renderable_list();

    renderable_list(shared_ptr<renderable> object);

    void clear();

    void add(shared_ptr<renderable> object);

    bool hit(const ray &r, double t_min, double t_max, hit_record &rec) const override;
};


#endif //RAYTRACERSIMPLIFIED_RENDERABLE_LIST_H
