#include "Renderer.h"

Vec2 Renderer::getSize() const {
    return surface->getSize();
}

void Renderer::drawLine(const Vec2& p1, const Vec2& p2, const Color4& color) const {
    const int dx = static_cast<int>(p2.x - p1.x);
    const int dy = static_cast<int>(p2.y - p1.y);
    int e = -dx;
    const int step = 2 * dy;
    const int desc = -2 * dx;
    int x = static_cast<int>(p1.x);
    int y = static_cast<int>(p1.y);

    while(x != static_cast<int>(p2.x)) {
        surface->setPixel(x, y, color);
        e += step;
        if(e >= 0) {
            y += 1;
            e += desc;
        }
        x += 1;
    }
}

void Renderer::clear(const Color4& color) const {
    surface->clear(color);
}

void Renderer::saveImage(const std::string& filename) const {
    surface->save(filename.c_str());
}

Renderer::Renderer() {
    surface = std::make_unique<Window>(500, 500);
}
