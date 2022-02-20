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
     * @param vertical_fov vertical_filed_of_view，垂直视野高度，用角度表示
     * @param aspect_ratio 分辨率，即长宽比，由上面的高度确定水平视野宽度
     */
    camera(double vertical_fov,double aspect_ratio);
    ray get_ray(double u, double v) const;
};


#endif //RAYTRACERSIMPLIFIED_CAMERA_H
