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

//camera::camera(double vertical_fov, double aspect_ratio) {
//    // 确定角度值，将度转换为弧度，以弧度为单位
//    auto theta = degrees_to_radians(vertical_fov);
//    // 确定高度，角度值除以 2 是因为视锥上下母线关于 z 轴对称，所以其角度值只有一半
//    auto h = tan(theta / 2);
//    // 画面高度（也即视野高度）为两倍 h，加上堆成的那部分
//    auto viewport_height = 2.0 * h;
//    // 由分辨率确定视野宽度
//    auto viewport_width = aspect_ratio * viewport_height;
//    // 焦距
//    auto focal_length = 1.0;
//    // 坐标原点
//    origin = point3(0, 0, 0);
//    // 水平向量
//    horizontal = vector3(viewport_width, 0.0, 0.0);
//    // 垂直向量
//    vertical = vector3(0.0, viewport_height, 0.0);
//    // 视野左下角点的坐标值
//    lower_left_corner = origin - horizontal / 2 - vertical / 2 - vector3(0, 0, focal_length);
//}

//camera::camera(point3 look_from, point3 look_at, vector3 up_vector, double vertical_fov, double aspect_ratio) {
//    // 确定角度值，将度转换为弧度，以弧度为单位
//    auto theta = degrees_to_radians(vertical_fov);
//    // 确定高度，角度值除以 2 是因为视锥上下母线关于 z 轴对称，所以其角度值只有一半
//    auto h = tan(theta / 2);
//    // 画面高度（也即视野高度）为两倍 h，加上堆成的那部分
//    auto viewport_height = 2.0 * h;
//    // 由分辨率确定视野宽度
//    auto viewport_width = aspect_ratio * viewport_height;
//    // 焦距
//    auto focal_length = 1.0;
//    // 确定摄像机视线方向的**反方向**的单位向量
//    auto w = unit_vector(look_from - look_at);
//    // 确定视野（也即画面）所在平面的横向向量
//    auto u = unit_vector(cross(up_vector, w));
//    // 确定视野（也即画面）所在平面的竖直向量
//    auto v = cross(w, u);
//    // 此处的原点将定为摄像机所在的点，以前都是坐标原点定为摄像机所在的点
//    // 此处摄像机将自由移动，所以，这个点是不固定的
//    origin = look_from;
//    // 确定视野所在平面的横向向量，长度为画面长
//    horizontal = viewport_width * u;
//    // 确定视野所在平面的竖直向量，长度为画面宽
//    vertical = viewport_height * v;
//    // 确定视野左下角点的坐标
//    lower_left_corner = origin - horizontal / 2 - vertical / 2 - w;
//}

camera::camera(point3 look_from, point3 look_at, vector3 up_vector,
               double vertical_fov, double aspect_ratio, double aperture, double focus_distance) {
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
    // 确定摄像机视线方向的**反方向**的单位向量
    w = unit_vector(look_from - look_at);
    // 确定视野（也即画面）所在平面的横向向量
    u = unit_vector(cross(up_vector, w));
    // 确定视野（也即画面）所在平面的竖直向量
    v = cross(w, u);
    // 此处的原点将定为摄像机所在的点，以前都是坐标原点定为摄像机所在的点
    // 此处摄像机将自由移动，所以，这个点是不固定的
    origin = look_from;
    // 确定视野所在平面的横向向量，长度为画面长
    horizontal = focus_distance * viewport_width * u;
    // 确定视野所在平面的竖直向量，长度为画面宽
    vertical = focus_distance * viewport_height * v;
    // 确定视野左下角点的坐标
    lower_left_corner = origin - horizontal / 2 - vertical / 2 - focus_distance * w;
    // 透镜半径为光圈大小除以 2
    lens_radius = aperture / 2;
}

//ray camera::get_ray(double u, double v) const {
//    return {origin, lower_left_corner + u * horizontal + v * vertical - origin};
//}

ray camera::get_ray(double s, double t) const {
    // 将单位圆盘内生成的点扩大到透镜大小范围内
    vector3 rd = lens_radius * random_in_unit_disk();
    // 生成偏移点的坐标，在摄像机视野平面上，x 轴对应向量 u，y 轴对应向量 v，z 轴对应向量 -w
    vector3 offset = u * rd.x() + v * rd.y();
    // 此时景深位置的其实点，即摄像机光线的发出点，是一个范围，起点坐标 = 原点（中心点）+ 偏移坐标
    // 注意最后方向向量还要减去其偏移坐标
    return {origin + offset,
            lower_left_corner + s * horizontal + t * vertical - origin - offset};
}