#include <gtest/gtest.h>
#include "Renderer.h"

TEST(WindowTest, Clear) {
    const Window surface(480, 320);
    surface.clear(Color4{0.5, 0.5, 0.5, 1});
    const Color4 pixelColor = surface.getPixelColor(0, 0);
    constexpr float tolerance = 0.01f;

    EXPECT_NEAR(pixelColor.r, 0.5, tolerance);
    EXPECT_NEAR(pixelColor.g, 0.5, tolerance);
    EXPECT_NEAR(pixelColor.b, 0.5, tolerance);
    EXPECT_NEAR(pixelColor.a, 1.0, tolerance);
}

TEST(WindowTest, SetPixel) {
    const Window surface(480, 320);
    surface.clear(Color4{0.5, 0.5, 0.5, 1});

    surface.setPixel(40, 160, Color4{1, 1, 0, 1});
    const Color4 pixelColor = surface.getPixelColor(40, 160);

    constexpr float tolerance = 0.01f;

    EXPECT_NEAR(pixelColor.r, 1, tolerance);
    EXPECT_NEAR(pixelColor.g, 1, tolerance);
    EXPECT_NEAR(pixelColor.b, 0, tolerance);
    EXPECT_NEAR(pixelColor.a, 1, tolerance);
}

TEST(WindowTest, drawLine) {
    renderer.drawLine({100, 100}, {500, 200}, Color4{1, 0, 0, 1});
    constexpr float tolerance = 0.01f;
    const Color4 pixelColor1 = renderer.getPixelColor(100, 100);
    EXPECT_NEAR(pixelColor1.r, 1, tolerance);
    EXPECT_NEAR(pixelColor1.g, 0, tolerance);
    EXPECT_NEAR(pixelColor1.b, 0, tolerance);
    EXPECT_NEAR(pixelColor1.a, 1, tolerance);
    renderer.drawLine({500, 500}, {100, 200}, Color4{1, 1, 0, 1});
    const Color4 pixelColor2 = renderer.getPixelColor(500, 500);
    EXPECT_NEAR(pixelColor2.r, 1, tolerance);
    EXPECT_NEAR(pixelColor2.g, 1, tolerance);
    EXPECT_NEAR(pixelColor2.b, 0, tolerance);
    EXPECT_NEAR(pixelColor2.a, 1, tolerance);
    renderer.drawLine({500, 500}, {500, 200}, Color4{0, 1, 0, 1});
    const Color4 pixelColor3 = renderer.getPixelColor(500, 300);
    EXPECT_NEAR(pixelColor3.r, 0, tolerance);
    EXPECT_NEAR(pixelColor3.g, 1, tolerance);
    EXPECT_NEAR(pixelColor3.b, 0, tolerance);
    EXPECT_NEAR(pixelColor3.a, 1, tolerance);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
