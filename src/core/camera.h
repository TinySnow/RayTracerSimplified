//
// Created by Snow on 2022.2.8.
//

#ifndef RAYTRACERSIMPLIFIED_CAMERA_H
#define RAYTRACERSIMPLIFIED_CAMERA_H

#include "vector3.h"
#include "ray.h"

class camera {
private:
    /**
     * 坐标原点
     */
    point3 origin;
    /**
     * 视野左下角点的坐标值
     */
    point3 lower_left_corner;
    /**
     * 水平向量
     */
    vector3 horizontal;
    /**
     * 垂直向量
     */
    vector3 vertical;
    /**
     * 确定摄像机视野平面的三个向量
     */
    vector3 u, v, w;
    /*
     * 透镜半径，用于散焦模糊（景深）
     */
    double lens_radius;
public:
    /**
     * 无参构造函数。
     */
    camera();
    /**
     * 特定参数构造函数，返回相机。<p>
     * <b>注意：</b>
     * 第一个参数垂直视野高度不能超过 180 度，因为摄像机的视锥，上下母线之夹角不会超过 180 度，
     * 这个角度就是此时的第一个参数，第一个参数是以角度的形式传入的。<p>
     * @param vertical_fov vertical_field_of_view，垂直视野高度，用角度表示
     * @param aspect_ratio 分辨率，即长宽比，由上面的高度确定水平视野宽度
     */
//    camera(double vertical_fov,double aspect_ratio);

    /**
     * 特定参数构造函数，返回相机。<p>
     * <b>注意：</b>
     * 第一个参数垂直视野高度不能超过 180 度，因为摄像机的视锥，上下母线之夹角不会超过 180 度，
     * 这个角度就是此时的第一个参数，第一个参数是以角度的形式传入的。<p>
     * @param look_from 摄像机所在的点
     * @param look_at 摄像机看向的点，与上面这个变量联立，确定摄像机所在视线的向量方程
     * @param up_vector 用于指定摄像机正上方向的向量方程
     * @param vertical_fov vertical_field_of_view，垂直视野高度，用角度表示
     * @param aspect_ratio 分辨率，即长宽比，由上面的高度确定水平视野宽度
     */
//    camera(point3 look_from, point3 look_at, vector3 up_vector, double vertical_fov, double aspect_ratio);

    /**
     * 特定参数构造函数，返回相机。<p>
     * <b>注意：</b>
     * 第一个参数垂直视野高度不能超过 180 度，因为摄像机的视锥，上下母线之夹角不会超过 180 度，
     * 这个角度就是此时的第一个参数，第一个参数是以角度的形式传入的。<p>
     * @param look_from 摄像机所在的点
     * @param look_at 摄像机看向的点，与上面这个变量联立，确定摄像机所在视线的向量方程
     * @param up_vector 用于指定摄像机正上方向的向量方程
     * @param vertical_fov vertical_field_of_view，垂直视野高度，用角度表示
     * @param aspect_ratio 分辨率，即长宽比，由上面的高度确定水平视野宽度
     * @param aperture 光圈大小，用于散焦模糊（景深）
     * @param focus_distance 焦距，即透镜所在位置和成像平面的距离
     */
    camera(point3 look_from, point3 look_at, vector3 up_vector, double vertical_fov, double aspect_ratio, double aperture, double focus_distance);

    ray get_ray(double s, double t) const;
};


#endif //RAYTRACERSIMPLIFIED_CAMERA_H
