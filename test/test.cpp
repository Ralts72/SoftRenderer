#include <gtest/gtest.h>
#include "Window.h"

TEST(SampleTest, Addition) {
    EXPECT_EQ(1 + 1, 2);
}

TEST(WindowTest, Clear) {
    const Window surface(480, 320);
    surface.clear(Color4{0.5, 0.5, 0.5, 1});
    const Color4 pixelColor = surface.getPixelColor(0, 0);
    EXPECT_EQ(pixelColor, (Color4{ 0.5, 0.5, 0.5, 1 }));
}

TEST(WindowTest, SetPixel) {
    const Window surface(480, 320);
    surface.clear(Color4{0.5, 0.5, 0.5, 1});

    surface.setPixel(40, 160, Color4{1, 1, 0, 1});
    const Color4 pixelColor = surface.getPixelColor(40, 160);
    EXPECT_EQ(pixelColor, (Color4{ 1, 1, 0, 1 }));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
