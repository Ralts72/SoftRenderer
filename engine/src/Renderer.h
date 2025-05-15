#pragma once
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

    void drawLine(const Vec2& p1, const Vec2& p2, const Color4& color) const;

    void clear(const Color4& color) const;

    void saveImage(const std::string& filename) const;

private:
    Renderer();

    std::unique_ptr<Window> surface;
};

static Renderer& renderer = Renderer::getInstance();

