#include <iostream>
#include "core/vector3.h"
#include "core/ray.h"
#include "renderable/implementation/renderable_list.h"
#include "core/camera.h"
#include "material/material.h"
#include "purpose/scene.h"

/**
 * ����ù���λ�õ���ɫ������ y ֵ�����������Բ�ֵ�Ļ�ϡ�<p>
 * ����������λ��, �Ա�֤ y ��ȡֵ��Χ -1.0 < y < 1.0������ y �ķ�Χ�� -1.0 �� y �� 1.0 ӳ�䵽 0 �� y �� 1.0��
 * ���� t = 1.0 ʱ������ɫ, �� t = 0.0 ʱ���ǰ�ɫ��<p>
 * ������֮�����ɻ��Ч��(blend)���������Ի��(linear blend)����˵���Բ�ֵ(liner interpolation)<p>
 * һ��������ʽ���£�<p>
 * <code><b> blendedValue = (1 - t ) * startValue + t * endValue </b></code>
 * @param r ���ߵ���������
 * @param world ��Ҫ��Ⱦ�ļ����弯�ϣ�Ҳ������
 * @param depth ����ݹ��������
 * @return ������ɫ
 */
color ray_color(const ray &r, const renderable &world, int depth) {
    hit_record rec;
    // ���������ȼ��ޣ���˵�������Ѿ����ܷ��䣬ֻ�ܱ����գ������յĹ��߿������Ǻ�ɫ�ģ����Է��غ�ɫ
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
    // �ض������λ��
    freopen("../src/image.ppm", "w", stdout);

    /**
     * ע�⣺
     * ���趨����ʱ������Ϊ�����᷽��
     *         ^ y��
     *         |
     *         |________>   x��
     *        /
     *       /
     *      <  z��
     * x ��������Ϊ������ҷ�
     * y ��������Ϊ��ֱ����
     * z ��������Ϊ��ֱֽ������
     */
    auto world = random_scene();

    // ����ͼ��ֱ��ʣ���ѡȡ����������Ϊ���쳤�Ϳ�
    const auto aspect_ratio = 16.0 / 9.0;
    // ����ͼ��߶�
    const int image_height = 540;
    // ����ͼ����
    const int image_width = static_cast<int>(image_height * aspect_ratio);

    const int samples_per_pixel = 10;
    // �޶��ݹ�������
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


    // ��Ⱦ
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j) {
        std::cerr << "\r���½��ȣ�" << j << ' ' << std::flush;
        // ����ÿһ����ķ�������������ɫ
        for (int i = 0; i < image_width; ++i) {
//            auto u = double(i) / (image_width - 1);
//            auto v = double(j) / (image_height - 1);
//            // ���� �˵�Ϊ����ԭ�㣬
//            // ��������Ϊ �����½ǵ����� �� Ŀǰѭ������ͼ���ϵĵ� ���߼���õ��ĵ�λ�� ��ȥԭ��õ�������
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
    std::cerr << "\n��Ⱦ��ɡ�\n";
}