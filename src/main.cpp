#include <iostream>
#include "core/vector3.h"

int main() {
    // 定义图像长和宽
    const int image_width = 256;
    const int image_height = 256;
    // 重定义输出位置
    freopen("../src/image.ppm", "w", stdout);
    // 渲染
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j) {
        std::cerr << "\r余下进度：" << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            vector3 color(double(i) / image_width, double(j) / image_height, 0.2);
            color.write_color(std::cout);
        }
    }
    std::cerr << "\n渲染完成。\n";
}