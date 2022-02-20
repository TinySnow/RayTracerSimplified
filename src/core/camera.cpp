//
// Created by Snow on 2022.2.8.
//

#include "camera.h"

camera::camera() {
    auto aspect_ratio = 16.0 / 9.0;
    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    origin = point3(0, 0, 0);
    horizontal = vector3(viewport_width, 0.0, 0.0);
    vertical = vector3(0.0, viewport_height, 0.0);
    lower_left_corner = origin - horizontal / 2 - vertical / 2 - vector3(0, 0, focal_length);
}

camera::camera(double vertical_fov, double aspect_ratio) {
    // 确定角度值，将度转换为弧度，以弧度为单位
    auto theta = degrees_to_radians(vertical_fov);
    // 确定高度，角度值除以 2 是因为视锥上下母线关于 z 轴对称，所以其角度值只有一半
    auto h = tan(theta / 2);
    // 画面高度（也即视野高度）为两倍 h，加上堆成的那部分
    auto viewport_height = 2.0 * h;
    // 由分辨率确定视野宽度
    auto viewport_width = aspect_ratio * viewport_height;
    // 焦距
    auto focal_length = 1.0;
    // 坐标原点
    origin = point3(0, 0, 0);
    // 水平向量
    horizontal = vector3(viewport_width, 0.0, 0.0);
    // 垂直向量
    vertical = vector3(0.0, viewport_height, 0.0);
    // 视野左下角点的坐标值
    lower_left_corner = origin - horizontal / 2 - vertical / 2 - vector3(0, 0, focal_length);
}

ray camera::get_ray(double u, double v) const {
    return {origin, lower_left_corner + u * horizontal + v * vertical - origin};
}
