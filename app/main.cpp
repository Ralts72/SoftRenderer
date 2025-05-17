#include <iostream>
#include "Renderer.h"

int main() {
    // Vector<3> v1{1.0, 2.0, 3.0}, v2{3, 4, 5};
    // std::cout << v1 << std::endl
    //         << v2 << std::endl
    //         << Vec2{5.5, 6.8} << std::endl
    //         << Vec4{3.3, 2.2, 9, 8.5} << std::endl
    //         << Vec4{1.1, 2.8} << std::endl
    //         << Vec4{1.1, 2.8, 3.3, 5.5, 6.8, 2.9} << std::endl;
    // std::cout << "Vec<3>(v1)" << Vec3(v1) << std::endl;

    Matrix<2, 2> m1{
        1, 2,
        3, 4
    };
    Matrix<2, 2> m2{
        5, 6,
        7, 8
    };
    std::cout << "m1 = " << m1 << std::endl
            << "m2 = " << m2.transpose() << std::endl;
    std::cout << "m1 * m2 = " << m1 * m2 << std::endl;
    std::cout << "Transpose(m1): " << transpose(m1) << std::endl;

    m1 *= m2;
    std::cout << "m1 *= m2:" << m1 << std::endl;

    std::cout << "Matrix<3, 2>::Ones() = " << Matrix<3, 2>(1.0f) << std::endl
            << "Matrix<2, 3>::Zeros() = " << Matrix<2, 3>(0.0f) << std::endl;

    const Vec2 multi_v{1, 2};
    const Matrix<2, 3> multi_m{
        1, 2,
        3, 4,
        5, 6
    };
    std::cout << "multi_v = " << multi_v << std::endl
            << "multi_m = " << multi_m << std::endl
            << "multi_m * multi_v = " << multi_m * multi_v << std::endl;

    renderer.clear(Color4{0.2, 0.5, 0.5, 1});
    // const Vec3 v1{-1.0f, 0.0f, 2.0f};
    // const Vec3 v2{1.0f, 1.0f, -2.0f};
    // const Vec3 v3{0.0f, -1.0f, -2.0f};
    const Vec3 v1{1.0f, 0.0f, 2.0f};
    const Vec3 v2{0.0f, 1.0f, 2.0f};
    const Vec3 v3{-1.0f, 0.0f, 2.0f};
    const std::array<Vec3, 3> vertices{v1, v2, v3};
    Mat4 model(0.0f);
    model.identity();
    renderer.drawTriangle(model, vertices, Color4{1.0f, 0.0f, 0.0f, 1.0f});
    const auto output_path = "../../test_surface.bmp";
    renderer.saveImage(output_path);

    Log("Hello, World! %d", 123);
    return 0;
}
