#include <iostream>
#include "core/vector3.h"
#include "core/ray.h"
#include "renderable/implementation/renderable_list.h"
#include "core/camera.h"
#include "material/material.h"
#include "purpose/scene.h"

/**
 * 计算该光线位置的颜色，根据 y 值将蓝白做线性差值的混合。<p>
 * 把射线做单位化, 以保证 y 的取值范围 -1.0 < y < 1.0，并将 y 的范围从 -1.0 ≤ y ≤ 1.0 映射到 0 ≤ y ≤ 1.0。
 * 这样 t = 1.0 时就是蓝色, 而 t = 0.0 时就是白色。<p>
 * 在蓝白之间生成混合效果(blend)，采用线性混合(linear blend)或者说线性插值(liner interpolation)<p>
 * 一般来讲公式如下：<p>
 * <code><b> blendedValue = (1 - t ) * startValue + t * endValue </b></code>
 * @param r 光线的向量方程
 * @param world 需要渲染的几何体集合，也即场景
 * @param depth 允许递归的最大深度
 * @return 返回颜色
 */
color ray_color(const ray &r, const renderable &world, int depth) {
    hit_record rec;
    // 如果到达深度极限，则说明光线已经不能反射，只能被吸收，被吸收的光线看起来是黑色的，所以返回黑色
    if (depth <= 0) {
        return {0, 0, 0};
    };

    if (world.hit(r, 0.001, infinity, rec)) {
        ray scattered;
        color attenuation;
        if (rec.material_ptr->scatter(r, rec, attenuation, scattered))
            return attenuation * ray_color(scattered, world, depth - 1);
        return {0, 0, 0};
    }
    vector3 unit_direction = unit_vector(r.get_direction());
    auto t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

int main() {
    // 重定义输出位置
    freopen("../src/image.ppm", "w", stdout);

    /**
     * 注意：
     * 在设定场景时，以下为正半轴方向
     *         ^ y轴
     *         |
     *         |________>   x轴
     *        /
     *       /
     *      <  z轴
     * x 轴正方向为摄像机右方
     * y 轴正方向为垂直向上
     * z 轴正方向为垂直纸面向外
     */
    auto world = random_scene();

    // 定义图像分辨率，不选取正方形是因为会搞混长和宽
    const auto aspect_ratio = 16.0 / 9.0;
    // 定义图像高度
    const int image_height = 540;
    // 定义图像宽度
    const int image_width = static_cast<int>(image_height * aspect_ratio);

    const int samples_per_pixel = 10;
    // 限定递归最大深度
    const int max_depth = 10;

//    camera camera;
//    camera camera(90.0, aspect_ratio);
//    camera camera(point3(-2,2,1), point3(0,0,-1), vector3(0,1,0), 20, aspect_ratio);

    point3 look_from(-11,2,-4);
    point3 look_at(0,0,0);
    vector3 up_vector(0,1,0);
    auto dist_to_focus = 10.0;
    auto aperture = 0;

    camera camera(look_from, look_at, up_vector, 20, aspect_ratio, aperture, dist_to_focus);


    // 渲染
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j) {
        std::cerr << "\r余下进度：" << j << ' ' << std::flush;
        // 计算每一个点的方向向量，并着色
        for (int i = 0; i < image_width; ++i) {
//            auto u = double(i) / (image_width - 1);
//            auto v = double(j) / (image_height - 1);
//            // 构造 端点为坐标原点，
//            // 方向向量为 从左下角点坐标 和 目前循环到的图像上的点 两者计算得到的点位置 减去原点得到的向量
//            ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);
//            color pixel_color = ray_color(r, world);
//            pixel_color.write_color(std::cout);
            color pixel_color(0, 0, 0);
            for (int s = 0; s < samples_per_pixel; ++s) {
                auto u = (i + random_double()) / (image_width - 1);
                auto v = (j + random_double()) / (image_height - 1);
                ray r = camera.get_ray(u, v);
                pixel_color += ray_color(r, world, max_depth);
            }
            pixel_color.write_color(std::cout, samples_per_pixel);
        }
    }
    std::cerr << "\n渲染完成。\n";
}