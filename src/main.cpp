#include <iostream>
#include "core/vector3.h"
#include "core/ray.h"

/**
 * 根据直线与球在直角坐标系中的方程，联立求解得到的式子：<p>
 * t^2 * (b·b) + 2t * b·(A-C) + (A-C)·(A-C) - r^2 = 0<p>
 * 之所以会得到这个式子，是因为我们把三个维的坐标值与直线的解析方程 用 直线到球心的距离与半径的大小 进行了替换。<p>
 * 不这样做会非常麻烦，然后根据求根公式判断有没有根，判断光线能不能击中球体。<p>
 * 注意：传参时传入球心，因为每个球的球心不一定在坐标系的原点。
 * @param center 球心坐标
 * @param radius 半径大小
 * @param r 光线向量方程
 * @return 根的大小
 */
double hit_sphere(const point3 &center, double radius, const ray &r) {
    // 球心到坐标原点的向量，即 A-C，C 为球心坐标
    vector3 oc = r.get_origin() - center;
//    // 光线方向向量的点乘，即 b·b
//    auto a = dot(r.get_direction(), r.get_direction());
//    // 计算 b·(A-C)
//    auto b = 2.0 * dot(oc, r.get_direction());
//    // 计算 (A-C)·(A-C) - r^2
//    auto c = dot(oc, oc) - radius * radius;
//    auto discriminant = b * b - 4 * a * c;
//    return discriminant < 0 ? -1.0 : (-b - sqrt(discriminant)) / (2.0 * a);
    // 以下代码是根据代数方法简化判别式
    // 假设 b 有一个系数 2，则：b = 2h，那么，
    /**          /`````````````````                  /`````````````````
     *  - b ±   /   b^2  - 4 * a * c        - h  ±  /  h^2 - a * c
     *        \/                                  \/
     *  ---------------------------   =    -----------------------------
     *            2a                                    a
     */
    auto a = r.get_direction().length_squared();
    auto half_b = dot(oc, r.get_direction());
    auto c = oc.length_squared() - radius * radius;
    auto discriminant = half_b * half_b - a * c;
    return discriminant < 0 ? -1.0 : (-half_b - sqrt(discriminant)) / a;
}

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
    // 返回根的大小，这个根是上述直线与球体相交得出来的解，它的值是用来确定光线 origin + t * direction 的具体位置的
    // 当然这个前提是有解，如果无解，直接跳过着色这一步就好
    auto t = hit_sphere(point3(0, 0, -1), 0.5, r);
    if (t > 0.0) {
        // 求出具体光线，到球心的距离，然后根据这个结果求得面法向量
        vector3 N = unit_vector(r.at(t) - vector3(0, 0, -1));
        // 根据法向量的大小位置偏差，对其上色
        // 法线向量越长，说明光线离球体我们的视线越平行，越接近视平面
        // 法线向量越短，说明光线越偏离我们的视平面
        return 0.5 * color(N.x() + 1, N.y() + 1, N.z() + 1);
    }
    // 获取方向向量的方向上的单位向量
    vector3 unit_direction = unit_vector(r.get_direction());
    t = 0.5 * (unit_direction.y() + 1.0);
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