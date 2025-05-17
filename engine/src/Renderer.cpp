#include "Renderer.h"

#include <random>

Vec2 Renderer::getSize() const {
    return surface->getSize();
}

Color4 Renderer::getPixelColor(const int x, const int y) const {
    return surface->getPixelColor(x, y);
}

void Renderer::drawLine(const Vec2& p1, const Vec2& p2, const Color4& color) const {
    Vec2 v1 = p1;
    Vec2 v2 = p2;
    const Vec2 min = {0.0f, 0.0f};
    Vec2 max = {0.0f, 0.0f};
    max.x = getSize().x - 1;
    max.y = getSize().y - 1;
    if(cohenSutherLand(v1, v2, min, max)) {
        drawLineWithoutClip(v1, v2, color);
    } else {
        Log("Line is outside of the surface\n");
    }
}

void Renderer::drawLineWithoutClip(const Vec2& p1, const Vec2& p2, const Color4& color) const {
    int x = static_cast<int>(p1.x);
    int y = static_cast<int>(p1.y);
    int dx = std::abs(static_cast<int>(p2.x - p1.x));
    int dy = std::abs(static_cast<int>(p2.y - p1.y));
    int sx = static_cast<int>(p1.x < p2.x ? 1 : -1);
    int sy = static_cast<int>(p1.y < p2.y ? 1 : -1);

    const int steep = dx < dy ? 1 : -1;
    const int final_x = static_cast<int>(dx < dy ? p2.y : p2.x);
    if(dx < dy) {
        std::swap(dx, dy);
        std::swap(x, y);
        std::swap(sx, sy);
    }
    int e = -dx;
    const int step = 2 * dy;
    const int desc = -2 * dx;

    while(x != final_x) {
        if(steep > 0) {
            surface->setPixel(y, x, color);
        } else {
            surface->setPixel(x, y, color);
        }

        e += step;
        if(e >= 0) {
            y += sy;
            e += desc;
        }
        x += sx;
    }
}

void Renderer::clear(const Color4& color) const {
    surface->clear(color);
}

void Renderer::saveImage(const std::string& filename) const {
    surface->save(filename.c_str());
}

constexpr uint8_t INSIDE = 0;
constexpr uint8_t LEFT = 1;
constexpr uint8_t RIGHT = 2;
constexpr uint8_t BOTTOM = 4;
constexpr uint8_t TOP = 8;

uint8_t Renderer::computeOutcode(const Vec2& p, const Vec2& min, const Vec2& max) {
    uint8_t code = 0;
    if(p.x < min.x) {
        code = code | LEFT;
    } else if(p.x > max.x) {
        code = code | RIGHT;
    }
    if(p.y < min.y) {
        code = code | BOTTOM;
    } else if(p.y > max.y) {
        code = code | TOP;
    }
    return code;
}

bool Renderer::cohenSutherLand(Vec2& p1, Vec2& p2, const Vec2& min, const Vec2& max) {
    uint8_t outcode1 = computeOutcode(p1, min, max);
    uint8_t outcode2 = computeOutcode(p2, min, max);
    bool accept = false;
    while(true) {
        if(!(outcode1 | outcode2)) {
            accept = true;
            break;
        } else if(outcode1 & outcode2) {
            break;
        } else {
            Vec2 p{0.0f, 0.0f};
            const uint8_t code = outcode1 > outcode2 ? outcode1 : outcode2;
            if(code & TOP) {
                p.x = p1.x + (p2.x - p1.x) * (max.y - p1.y) / (p2.y - p1.y);
                p.y = max.y;
            } else if(code & BOTTOM) {
                p.x = p1.x + (p2.x - p1.x) * (min.y - p1.y) / (p2.y - p1.y);
                p.y = min.y;
            } else if(code & RIGHT) {
                p.y = p1.y + (p2.y - p1.y) * (max.x - p1.x) / (p2.x - p1.x);
                p.x = max.x;
            } else if(code & LEFT) {
                p.y = p1.y + (p2.y - p1.y) * (min.x - p1.x) / (p2.x - p1.x);
                p.x = min.x;
            }
            if(outcode1 == code) {
                p1.x = p.x;
                p1.y = p.y;
                outcode1 = computeOutcode(p1, min, max);
            } else {
                p2.x = p.x;
                p2.y = p.y;
                outcode2 = computeOutcode(p2, min, max);
            }
        }
    }
    return accept;
}

Renderer::Renderer() {
    surface = std::make_unique<Window>(800, 800);
}
