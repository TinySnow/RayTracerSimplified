//
// Created by Snow on 2022.2.20.
//

#include "scene.h"

renderable_list random_scene() {
    renderable_list world;

    auto ground_material = make_shared<lambertian>(color(0.4, 0.7, 0.7));
    world.add(make_shared<sphere>(point3(0, -1000, 0), 1000, ground_material));

    for (int a = -13; a < 9; a++) {
        for (int b = -13; b < 9; b++) {
            auto choose_mat = random_double();
            point3 center(a + 0.99 * random_double(), 0.2, b + 0.99 * random_double());

            if ((center - point3(4, 0.2, 0)).length() > 0.9) {
                shared_ptr<material> sphere_material;

                if (choose_mat < 0.5) {
                    auto albedo = color::random() * color::random();
                    sphere_material = make_shared<lambertian>(albedo);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                } else if (choose_mat >= 0.3 && choose_mat < 0.75) {
                    auto albedo = color::random(0.5, 1);
                    auto fuzz = random_double(0, 0.5);
                    sphere_material = make_shared<metal>(albedo, fuzz);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                } else {
                    sphere_material = make_shared<dielectric>(1.5);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                }
            }
        }
    }
//    for (int i = 0; i < 20; ++i) {
//        auto random_choose = random_double(0, 3);
//        double radius = 0.3;
//        point3 center(random_double(-9, 9), radius, random_double(-4, 6));
//        shared_ptr<material> material;
//        if (random_choose >= 0 && random_choose < 1.5) {
//            auto albedo = color::random();
//            material = make_shared<lambertian>(albedo);
//            world.add(make_shared<sphere>(center, radius, material));
//        } else if (random_choose >= 1.5 && random_choose < 2.25) {
//            auto albedo = color::random(0.5, 1);
//            auto fuzz = random_double(0, 0.5);
//            material = make_shared<metal>(albedo, fuzz);
//            world.add(make_shared<sphere>(center, radius, material));
//        } else {
//            material = make_shared<dielectric>(1.5);
//            world.add(make_shared<sphere>(center, radius, material));
//        }
//    }

    auto material1 = make_shared<dielectric>(1.5);
    world.add(make_shared<sphere>(point3(0, 1, 0), 1.0, material1));

    auto material2 = make_shared<lambertian>(color(0.4, 0.2, 0.1));
    world.add(make_shared<sphere>(point3(-4, 1, 0), 1.0, material2));

    auto material3 = make_shared<metal>(color(0.7, 0.6, 0.5), 0.0);
    world.add(make_shared<sphere>(point3(4, 1, 0), 1.0, material3));

    auto material4 = make_shared<metal>(color(0.9, 0.9, 0.8), 0.0);
    world.add(make_shared<sphere>(point3(-2, 2, -4), 2.0, material3));

//    auto material4 = make_shared<lambertian>(color(0.1, 0.2, 0.3));
//    world.add(make_shared<sphere>(point3(-3, 0.5, 3), 0.5, material4));
//    auto material5 = make_shared<lambertian>(color(0.8, 0.1, 0.5));
//    world.add(make_shared<sphere>(point3(3, 0.5, 3), 0.5, material5));
//    auto material6 = make_shared<lambertian>(color(0.5, 0.4, 0.2));
//    world.add(make_shared<sphere>(point3(0, 0.5, 3), 0.5, material6));

    return world;
}
