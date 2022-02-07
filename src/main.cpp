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
 * @return
 */
bool hit_sphere(const point3 &center, double radius, const ray &r) {
    // ���ĵ�����ԭ����������� A-C��C Ϊ��������
    vector3 oc = r.get_origin() - center;
    // ���߷��������ĵ�ˣ��� b��b
    auto a = dot(r.get_direction(), r.get_direction());
    // ���� b��(A-C)
    auto b = 2.0 * dot(oc, r.get_direction());
    // ���� (A-C)��(A-C) - r^2
    auto c = dot(oc, oc) - radius * radius;
    // �����б�ʽ����ʵ�����Ժ� return �ϲ������������߼�������
    auto discriminant = b * b - 4 * a * c;
    return (discriminant > 0);
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
    if (hit_sphere(point3(0, 0, -1), 0.5, r)) {
        // ��������ˣ����غ�ɫ�����ɫֵ������ʾ
        return {1, 0, 0};
    }
    // ��ȡ���������ķ����ϵĵ�λ����
    vector3 unit_direction = unit_vector(r.get_direction());
    auto t = 0.5 * (unit_direction.y() + 1.0);
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