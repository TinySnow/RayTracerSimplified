#include <iostream>
#include "core/vector3.h"
#include "core/ray.h"

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

/**
 * ����ù���λ�õ���ɫ������ y ֵ�����������Բ�ֵ�Ļ�ϡ�<p>
 * ����������λ��, �Ա�֤ y ��ȡֵ��Χ -1.0 < y < 1.0������ y �ķ�Χ�� -1.0 �� y �� 1.0 ӳ�䵽 0 �� y �� 1.0��
 * ���� t = 1.0 ʱ������ɫ, �� t = 0.0 ʱ���ǰ�ɫ��<p>
 * ������֮�����ɻ��Ч��(blend)���������Ի��(linear blend)����˵���Բ�ֵ(liner interpolation)<p>
 * һ��������ʽ���£�<p>
 * <code><b> blendedValue = (1 - t ) * startValue + t * endValue </b></code>
 * @param r ��Ҫ������ɫ�Ĺ�������
 * @return ��ɫֵ
 */
color ray_color(const ray &r) {
    // ���ظ��Ĵ�С�������������ֱ���������ཻ�ó����Ľ⣬����ֵ������ȷ������ origin + t * direction �ľ���λ�õ�
    // ��Ȼ���ǰ�����н⣬����޽⣬ֱ��������ɫ��һ���ͺ�
    auto t = hit_sphere(point3(0, 0, -1), 0.5, r);
    if (t > 0.0) {
        // ���������ߣ������ĵľ��룬Ȼ���������������淨����
        vector3 N = unit_vector(r.at(t) - vector3(0, 0, -1));
        // ���ݷ������Ĵ�Сλ��ƫ�������ɫ
        // ��������Խ����˵���������������ǵ�����Խƽ�У�Խ�ӽ���ƽ��
        // ��������Խ�̣�˵������Խƫ�����ǵ���ƽ��
        return 0.5 * color(N.x() + 1, N.y() + 1, N.z() + 1);
    }
    // ��ȡ���������ķ����ϵĵ�λ����
    vector3 unit_direction = unit_vector(r.get_direction());
    t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

int main() {
    // �ض������λ��
    freopen("../src/image.ppm", "w", stdout);

    // ����ͼ��ֱ��ʣ���ѡȡ����������Ϊ���쳤�Ϳ�
    const auto aspect_ratio = 16.0 / 9.0;
    // ����ͼ����
    const int image_width = 400;
    // ����ͼ��߶�
    const int image_height = static_cast<int>(image_width / aspect_ratio);
    // ����߶�
    auto viewport_height = 2.0;
    // ������
    auto viewport_width = aspect_ratio * viewport_height;
    // ����
    auto focal_length = 1.0;
    // ����ԭ��
    auto origin = point3(0, 0, 0);
    // ˮƽ����
    auto horizontal = vector3(viewport_width, 0, 0);
    // ��ֱ����
    auto vertical = vector3(0, viewport_height, 0);
    // ��ͷ�������½ǵĵ�����
    auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - vector3(0, 0, focal_length);

    // ��Ⱦ
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j) {
        std::cerr << "\r���½��ȣ�" << j << ' ' << std::flush;
        // ����ÿһ����ķ�������������ɫ
        for (int i = 0; i < image_width; ++i) {
            auto u = double(i) / (image_width - 1);
            auto v = double(j) / (image_height - 1);
            // ���� �˵�Ϊ����ԭ�㣬
            // ��������Ϊ �����½ǵ����� �� Ŀǰѭ������ͼ���ϵĵ� ���߼���õ��ĵ�λ�� ��ȥԭ��õ�������
            ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);
            color pixel_color = ray_color(r);
            pixel_color.write_color(std::cout);
        }
    }
    std::cerr << "\n��Ⱦ��ɡ�\n";
}