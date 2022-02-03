#include <iostream>
#include "core/vector3.h"

int main() {
    // ����ͼ�񳤺Ϳ�
    const int image_width = 256;
    const int image_height = 256;
    // �ض������λ��
    freopen("../src/image.ppm", "w", stdout);
    // ��Ⱦ
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j) {
        std::cerr << "\r���½��ȣ�" << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            vector3 color(double(i) / image_width, double(j) / image_height, 0.2);
            color.write_color(std::cout);
        }
    }
    std::cerr << "\n��Ⱦ��ɡ�\n";
}