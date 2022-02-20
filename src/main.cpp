#include <iostream>
#include "core/vector3.h"
#include "core/ray.h"
#include "renderable/implementation/renderable_list.h"
#include "renderable/implementation/sphere.h"
#include "core/camera.h"
#include "material/material.h"
#include "material/implementation/lambertian.h"
#include "material/implementation/metal.h"
#include "material/implementation/dielectric.h"

/**
 * ����ֱ��������ֱ������ϵ�еķ��̣��������õ���ʽ�ӣ�<p>
 * t^2 * (b��b) + 2t * b��(A-C) + (A-C)��(A-C) - r^2 = 0<p>
 * ֮���Ի�õ����ʽ�ӣ�����Ϊ���ǰ�����ά������ֵ��ֱ�ߵĽ������� �� ֱ�ߵ����ĵľ�����뾶�Ĵ�С �������滻��<p>
 * ����������ǳ��鷳��Ȼ����������ʽ�ж���û�и����жϹ����ܲ��ܻ������塣<p>
 * ע�⣺����ʱ�������ģ���Ϊÿ��������Ĳ�һ��������ϵ��ԭ�㡣
 * @param center ��������
 * @param radius �뾶��С
 * @param r ������������
 * @return ���Ĵ�С
 */
double hit_sphere(const point3 &center, double radius, const ray &r) {
    // ���ĵ�����ԭ����������� A-C��C Ϊ��������
    vector3 oc = r.get_origin() - center;
//    // ���߷��������ĵ�ˣ��� b��b
//    auto a = dot(r.get_direction(), r.get_direction());
//    // ���� b��(A-C)
//    auto b = 2.0 * dot(oc, r.get_direction());
//    // ���� (A-C)��(A-C) - r^2
//    auto c = dot(oc, oc) - radius * radius;
//    auto discriminant = b * b - 4 * a * c;
//    return discriminant < 0 ? -1.0 : (-b - sqrt(discriminant)) / (2.0 * a);
    // ���´����Ǹ��ݴ����������б�ʽ
    // ���� b ��һ��ϵ�� 2����b = 2h����ô��
    /**          /`````````````````                  /`````````````````
     *  - b ��   /   b^2  - 4 * a * c        - h  ��  /  h^2 - a * c
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

///**
// * ����ù���λ�õ���ɫ������ y ֵ�����������Բ�ֵ�Ļ�ϡ�<p>
// * ����������λ��, �Ա�֤ y ��ȡֵ��Χ -1.0 < y < 1.0������ y �ķ�Χ�� -1.0 �� y �� 1.0 ӳ�䵽 0 �� y �� 1.0��
// * ���� t = 1.0 ʱ������ɫ, �� t = 0.0 ʱ���ǰ�ɫ��<p>
// * ������֮�����ɻ��Ч��(blend)���������Ի��(linear blend)����˵���Բ�ֵ(liner interpolation)<p>
// * һ��������ʽ���£�<p>
// * <code><b> blendedValue = (1 - t ) * startValue + t * endValue </b></code>
// * @param r ��Ҫ������ɫ�Ĺ�������
// * @return ��ɫֵ
// */
//color ray_color(const ray &r) {
//    // ���ظ��Ĵ�С�������������ֱ���������ཻ�ó����Ľ⣬����ֵ������ȷ������ origin + t * direction �ľ���λ�õ�
//    // ��Ȼ���ǰ�����н⣬����޽⣬ֱ��������ɫ��һ���ͺ�
//    auto t = hit_sphere(point3(0, 0, -1), 0.5, r);
//    if (t > 0.0) {
//        // ���������ߣ������ĵľ��룬Ȼ���������������淨����
//        vector3 N = unit_vector(r.at(t) - vector3(0, 0, -1));
//        // ���ݷ������Ĵ�Сλ��ƫ�������ɫ
//        // ��������Խ����˵���������������ǵ�����Խƽ�У�Խ�ӽ���ƽ��
//        // ��������Խ�̣�˵������Խƫ�����ǵ���ƽ��
//        return 0.5 * color(N.x() + 1, N.y() + 1, N.z() + 1);
//    }
//    // ��ȡ���������ķ����ϵĵ�λ����
//    vector3 unit_direction = unit_vector(r.get_direction());
//    t = 0.5 * (unit_direction.y() + 1.0);
//    return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
//}

/**
 * ����һ�㼸��һ�£�����һ������ world���ò����ǳ�������Ҫ��Ⱦ�ļ����弯��
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
////        return 0.5 * (rec.normal + color(1, 1, 1));
//        point3 target = rec.p + rec.normal + random_unit_vector();
//        // ��ע�⣬�˴���ʼ�ݹ����
//        return 0.5 * ray_color(ray(rec.p, target - rec.p), world, depth - 1);
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

    // Ϊ���������Ҫ��Ⱦ�ļ�����
    renderable_list world;
//    auto material_ground = make_shared<lambertian>(color(0.8, 0.8, 0.0));
//    auto material_center = make_shared<lambertian>(color(0.1, 0.2, 0.5));
//    auto material_left = make_shared<dielectric>(1.5);
//    auto material_right = make_shared<metal>(color(0.8, 0.6, 0.2), 0.0);
    auto R = cos(pi/4);
    auto material_left = make_shared<lambertian>(color(0,0,1));
    auto material_right = make_shared<lambertian>(color(1,0,0));
    world.add(make_shared<sphere>(point3(-R, 0, -1), R, material_left));
    world.add(make_shared<sphere>(point3( R, 0, -1), R, material_right));
//    world.add(make_shared<sphere>(point3(0.0, -100.5, -1.0), 100.0, material_ground));
//    world.add(make_shared<sphere>(point3(0.0, 0.0, -1.0), 0.5, material_center));
//    world.add(make_shared<sphere>(point3(-1.0, 0.0, -1.0), 0.5, material_left));
//    world.add(make_shared<sphere>(point3(-1.0, 0.0, -1.0), -0.4, material_left));
//    world.add(make_shared<sphere>(point3(1.0, 0.0, -1.0), 0.5, material_right));


    // ����ͼ��ֱ��ʣ���ѡȡ����������Ϊ���쳤�Ϳ�
    const auto aspect_ratio = 16.0 / 9.0;
    // ����ͼ��߶�
    const int image_height = 450;
    // ����ͼ����
    const int image_width = static_cast<int>(image_height * aspect_ratio);

    const int samples_per_pixel = 100;
    // �޶��ݹ�������
    const int max_depth = 50;

//    camera camera;
    camera camera(90.0, aspect_ratio);
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