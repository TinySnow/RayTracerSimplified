# RayTracerSimplified

## Description/概述

##### English:
Try to implement a simple ray tracer. Source code has detailed comments and all the evolutions with git tag.

##### Chinese:
尝试实现简单光线追踪器，源码带有注释，并且演进过程打上标签。

## Evolutions/演进

##### English:

Details in commit message and tag message.

##### Chinese:

详情请看 commit message 和 tag message。

## Summary/总结

##### English:

This source code only implemented:

- Basics

  - Vector
  
  - Camera
  
  - Ray

- Material

  - Lambertian
  
  - Dielectric
  
  - Metal

- Geometry

  - Sphere

- Depth of field(Defocus Blur)

This source code **DIDN'T** implement:

- Volumetric fog

- Geometry

  - Rectangle
  
  - Triangle
  
- GPU acceleration

- Light

  - Directional Light
  
  - Sky Light
  
  - Point Light
  
  - Spot Light
  
  - Rect Light

- File input(e.g. Blender file)

- etc

##### Chinese:

此仓库源码只实现了：

- 基础

  - 向量
  
  - 光线
  
  - 摄像机

- 材质

  - 漫反射
  
  - 玻璃
  
  - 金属

- 几何体

  - 球体

- 景深（散焦模糊）

此仓库代码**没有**实现：

- 体积光

- 几何体

  - 矩形体
  
  - 三角体

- GPU 加速

- 光线

  - 定向光源
  
  - 天空光照
  
  - 点光源
  
  - 聚光源
  
  - 矩形光源

- 文件输入（例：Blender 文件）

- 等等

## Results/成果

### Final Scene/最终场景

![image_final_scene_show_A](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_show_A.40rtbh4y296o.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_show_A</p>

![image_final_scene_show_B](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_show_B.42h5o3mk89mo.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_show_B</p>

![image_final_scene_show_C](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_show_C.1sxjuyfiwvuo.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_show_C</p>

![image_final_scene_show_D](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_show_D.30qcr2tmn4g0.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_show_D</p>

![image_final_scene_show_E](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_show_E.49afiznb37wg.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_show_E</p>

![image_final_scene_show_F](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_show_F.2t4q0p2f6h4w.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_show_F</p>

### Control Variables/控制变量

### Main Variables/主要变量

##### English:

In the file name, value of variables are commented. Ray numbers per pixel and max scattering numbers per ray.

Note: Scattering includes reflection and refraction。

##### Chinese:

在文件名中，变量值已标注。Ray 为每像素发出的光线数量，Scatter 为每光线的最大散射次数。

注意：散射包括反射和折射。

#### Pictures/图片

![image_final_scene_1_rays_1_scatters](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_1_rays_1_scatters.l9o7av9ka4g.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_1_rays_1_scatters</p>

![image_final_scene_1_rays_2_scatters](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_1_rays_2_scatters.67mq88m09aps.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_1_rays_2_scatters</p>

![image_final_scene_1_rays_3_scatters](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_1_rays_3_scatters.1fz11uwy98hs.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_1_rays_3_scatters</p>

![image_final_scene_1_rays_4_scatters](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_1_rays_4_scatters.i1ojhks5exc.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_1_rays_4_scatters</p>

![image_final_scene_1_rays_5_scatters](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_1_rays_5_scatters.2jix0nsqp9s0.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_1_rays_5_scatters</p>

![image_final_scene_1_rays_10_scatters](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_1_rays_10_scatters.3xb5q1fdkjk0.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_1_rays_10_scatters</p>

![image_final_scene_1_rays_25_scatters](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_1_rays_25_scatters.1vaixtp6wu3k.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_1_rays_25_scatters</p>

![image_final_scene_1_rays_50_scatters](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_1_rays_50_scatters.54su2azh181s.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_1_rays_50_scatters</p>

![image_final_scene_5_rays_1_scatters](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_5_rays_1_scatters.ndaja5tu85c.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_5_rays_1_scatters</p>

![image_final_scene_5_rays_2_scatters](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_5_rays_2_scatters.3pvmrfqm6l1c.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_5_rays_2_scatters</p>

![image_final_scene_5_rays_5_scatters](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_5_rays_5_scatters.6516rcuyzqm8.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_5_rays_5_scatters</p>

![image_final_scene_10_rays_5_scatters](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_10_rays_5_scatters.5tf7ho2tif0g.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_10_rays_5_scatters</p>

![image_final_scene_test_100_rays](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_test_100_rays.1wsacj2lwbxc.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_test_100_rays</p>

![image_final_scene_test_500_rays](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_test_500_rays.3akennxopow.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_test_500_rays</p>

### Other Variables/其他变量

##### English:

Includes aperture, fov(field of view, based on height calculating), distance to focus.

##### Chinese:

包括 aperture(光圈大小)，fov(field of view，视野大小，基于高度计算)，distance to focus(焦距)。

#### Pictures/图片

![image_final_scene_another_5_rays_5_scatters](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_another_5_rays_5_scatters.307qswt4zrcw.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_another_5_rays_5_scatters</p>

![image_final_scene_another_50_rays_10_scatters](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_another_50_rays_10_scatters.1srqq0689gcg.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_another_50_rays_10_scatters</p>

![image_final_scene_another_10_rays_10_scatters](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_another_10_rays_10_scatters.3n01qeggj8sg.webp)

<p style="text-align: center; font-style: italic;">Following picture based: image_final_scene_another_10_rays_10_scatters</p>

![image_final_scene_another_10_rays_10_scatters_no_aperture](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_another_10_rays_10_scatters_no_aperture.60uxjhn0imm8.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_another_10_rays_10_scatters_no_aperture</p>

![image_final_scene_another_10_rays_10_scatters_normal](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_another_10_rays_10_scatters_normal%280.436k7b9ilny8.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_another_10_rays_10_scatters_normal(0.1)_aperture</p>

![image_final_scene_another_10_rays_10_scatters_big(0)](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_another_10_rays_10_scatters_big%280.31r6gz3qp6v4.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_another_10_rays_10_scatters_big(0.5)_aperture</p>

![image_final_scene_another_10_rays_10_scatters_huge(1)](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_another_10_rays_10_scatters_huge%281.4wk9ey08e1ds.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_another_10_rays_10_scatters_huge(1.0)_aperture</p>

![image_final_scene_another_10_rays_10_scatters_short(4)_focus](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_another_10_rays_10_scatters_short(4)_focus.51vobipugscg.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_another_10_rays_10_scatters_short(4)_focus</p>

![image_final_scene_another_10_rays_10_scatters_long(50)_focus](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_another_10_rays_10_scatters_long(50)_focus.7174hb1gyyyo.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_another_10_rays_10_scatters_long(50)_focus</p>

![image_final_scene_another_10_rays_10_scatters_no_fov](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_another_10_rays_10_scatters_no_fov.31pdtdezt9g.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_another_10_rays_10_scatters_no_fov</p>

![image_final_scene_another_10_rays_10_scatters_tiny(5)_fov](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_another_10_rays_10_scatters_tiny(5)_fov.3kwtkuwrhq2o.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_another_10_rays_10_scatters_tiny(5)_fov</p>

![image_final_scene_another_10_rays_10_scatters_little(10)_fov](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_another_10_rays_10_scatters_little(10)_fov.3kdpwn7oszr4.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_another_10_rays_10_scatters_little(10)_fov</p>

![image_final_scene_another_10_rays_10_scatters_normal(30)_fov](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_another_10_rays_10_scatters_normal(30)_fov.41i7as52ifcw.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_another_10_rays_10_scatters_normal(30)_fov</p>

![image_final_scene_another_10_rays_10_scatters_huge(90)_fov](https://cdn.jsdelivr.net/gh/TinySnow/GithubImageHosting@main/RayTracer/image_final_scene_another_10_rays_10_scatters_huge(90)_fov.3a4vg0s9cbuo.webp)

<p style="text-align: center; font-style: italic;">image_final_scene_another_10_rays_10_scatters_huge(90)_fov</p>

## Reference/参考

[Ray Tracing in One Weekend](https://github.com/RayTracing/raytracing.github.io/)

[Ray Tracing in One Weekend](https://matrix4f.com/Graphic/ray-tracing-in-one-weekend/) (Chinese version translated by [Oxine](https://matrix4f.com/))

[Unreal Engine Docs -> RayTracing](https://docs.unrealengine.com/4.27/zh-CN/RenderingAndGraphics/RayTracing/) (in Chinese)

[Physically Based Rendering: From Theory to Implementation](https://www.pbrt.org)

## License/许可证

MIT License.