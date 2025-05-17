#pragma once
#include <memory>
#include "Window.h"

class Renderer {
public:
    ~Renderer() = default;

    Renderer(const Renderer&) = delete;

    Renderer& operator=(const Renderer&) = delete;

    static Renderer& getInstance() {
        static Renderer instance;
        return instance;
    }

    [[nodiscard]] Vec2 getSize() const;

    [[nodiscard]] Color4 getPixelColor(int x, int y) const;

    void drawLine(const Vec2& p1, const Vec2& p2, const Color4& color) const;

    void clear(const Color4& color) const;

    void saveImage(const std::string& filename) const;

private:
    void drawLineWithoutClip(const Vec2& p1, const Vec2& p2, const Color4& color) const;

    static uint8_t computeOutcode(const Vec2& p, const Vec2& min, const Vec2& max);

    static bool cohenSutherLand(Vec2& p1, Vec2& p2, const Vec2& min, const Vec2& max);

    Renderer();

    std::unique_ptr<Window> surface;
};

static Renderer& renderer = Renderer::getInstance();

