#pragma once
#include <memory>
#include "Window.h"
#include "Camera.h"
#include <array>

constexpr double PI = 3.14159265358979323846;

struct Viewport {
    Viewport(const int x, const int y, const int width, const int height): x(x), y(y), width(width), height(height) {}
    int x, y, width, height;
};

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

    void drawTriangle(const Mat4& model, const std::array<Vec3, 3>& vertices, const Color4& color) const;

    void clear(const Color4& color) const;

    void saveImage(const std::string& filename) const;

private:
    void drawLineWithoutClip(const Vec2& p1, const Vec2& p2, const Color4& color) const;

    static uint8_t computeOutcode(const Vec2& p, const Vec2& min, const Vec2& max);

    static bool cohenSutherLand(Vec2& p1, Vec2& p2, const Vec2& min, const Vec2& max);

    Renderer();

    std::unique_ptr<Window> m_surface;
    std::unique_ptr<Camera> m_camera;
    Viewport m_viewport;
};

static Renderer& renderer = Renderer::getInstance();

