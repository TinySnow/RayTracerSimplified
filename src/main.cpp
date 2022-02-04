#include <iostream>
#include "core/vector3.h"
#include "core/ray.h"

/**
 * 计算该光线位置的颜色，根据 y 值将蓝白做线性差值的混合。<p>
 * 把射线做单位化, 以保证 y 的取值范围 -1.0 < y < 1.0，并将 y 的范围从 -1.0 ≤ y ≤ 1.0 映射到 0 ≤ y ≤ 1.0。
 * 这样 t = 1.0 时就是蓝色, 而 t = 0.0 时就是白色。<p>
 * 在蓝白之间生成混合效果(blend)，采用线性混合(linear blend)或者说线性插值(liner interpolation)<p>
 * 一般来讲公式如下：<p>
 * <code><b> blendedValue = (1 - t ) * startValue + t * endValue </b></code>
 * @param r 需要计算颜色的光线向量
 * @return 颜色值
 */
color ray_color(const ray &r) {
    // 获取方向向量的方向上的单位向量
    vector3 unit_direction = unit_vector(r.get_direction());
    auto t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

int main() {
    // 重定义输出位置
    freopen("../src/image.ppm", "w", stdout);

    // 定义图像分辨率，不选取正方形是因为会搞混长和宽
    const auto aspect_ratio = 16.0 / 9.0;
    // 定义图像宽度
    const int image_width = 400;
    // 定义图像高度
    const int image_height = static_cast<int>(image_width / aspect_ratio);
    // 镜框高度
    auto viewport_height = 2.0;
    // 镜框宽度
    auto viewport_width = aspect_ratio * viewport_height;
    // 焦距
    auto focal_length = 1.0;
    // 坐标原点
    auto origin = point3(0, 0, 0);
    // 水平向量
    auto horizontal = vector3(viewport_width, 0, 0);
    // 垂直向量
    auto vertical = vector3(0, viewport_height, 0);
    // 镜头矩形左下角的点坐标
    auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - vector3(0, 0, focal_length);

    // 渲染
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j) {
        std::cerr << "\r余下进度：" << j << ' ' << std::flush;
        // 计算每一个点的方向向量，并着色
        for (int i = 0; i < image_width; ++i) {
            auto u = double(i) / (image_width - 1);
            auto v = double(j) / (image_height - 1);
            // 构造 端点为坐标原点，
            // 方向向量为 从左下角点坐标 和 目前循环到的图像上的点 两者计算得到的点位置 减去原点得到的向量
            ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);
            color pixel_color = ray_color(r);
            pixel_color.write_color(std::cout);
        }
    }
    std::cerr << "\n渲染完成。\n";
}