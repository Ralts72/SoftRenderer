#pragma once
#include "MyMath.h"
#include <SDL2/SDL.h>
#include <algorithm>
#include <iostream>

inline uint8_t FloatToUint8(const float value) {
    return static_cast<uint8_t>(std::clamp(value, 0.0f, 1.0f) * 255);
}

class Window {
public:
    explicit Window(const char* name) {
        m_surface = SDL_LoadBMP(name);
    }

    Window(const int width, const int height) {
        m_surface = SDL_CreateRGBSurfaceWithFormat(0, width, height, 32, SDL_PIXELFORMAT_RGBA32);
        if(!m_surface) {
            std::cout << "Create Surface failed: " << SDL_GetError() << std::endl;
        }
    }

    Window(const Window&) = delete;

    ~Window() {
        SDL_FreeSurface(m_surface);
    }

    Window& operator=(const Window&) = delete;

    [[nodiscard]] inline int getWidth() const {
        return m_surface->w;
    }

    [[nodiscard]] inline int getHeight() const {
        return m_surface->h;
    }

    [[nodiscard]] inline Vec2 getSize() const {
        return Vec2{static_cast<float>(m_surface->w), static_cast<float>(m_surface->h)};
    }

    void setPixel(const int x, const int y, const Color4& color) const {
        *getPixel(x, y) = SDL_MapRGB(m_surface->format, FloatToUint8(color.r), FloatToUint8(color.g), FloatToUint8(color.b));
    }

    [[nodiscard]] Color4 getPixelColor(const int x, const int y) const {
        const Uint32* color = getPixel(x, y);
        Uint8 r, g, b, a;
        SDL_GetRGBA(*color, m_surface->format, &r, &g, &b, &a);
        return Color4{
            static_cast<float>(r) / 255.0f, static_cast<float>(g) / 255.0f, static_cast<float>(b) / 255.0f, static_cast<float>(a) / 255.0f
        };
    }

    inline void clear(const Color4& color) const {
        SDL_FillRect(m_surface, nullptr, SDL_MapRGBA(m_surface->format, FloatToUint8(color.r), FloatToUint8(color.g), FloatToUint8(color.b), FloatToUint8(color.a)));
    }

    void save(const char* filename) const {
        if(const auto surface = SDL_ConvertSurfaceFormat(m_surface, SDL_PIXELFORMAT_RGB24, 0)) {
            SDL_SaveBMP(surface, filename);
            SDL_FreeSurface(surface);
        } else {
            std::cout << "Save failed: " << SDL_GetError() << std::endl;
        }
    }

private:
    SDL_Surface* m_surface;

    [[nodiscard]] Uint32* getPixel(const int x, const int y) const {
        auto* ptr = static_cast<Uint8*>(m_surface->pixels);
        return reinterpret_cast<Uint32*>(ptr + y * m_surface->pitch + x * m_surface->format->BytesPerPixel);
    }
};
