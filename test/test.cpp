#include <gtest/gtest.h>
#include "Window.h"

TEST(SampleTest, Addition) {
    EXPECT_EQ(1 + 1, 2);
}

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

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
