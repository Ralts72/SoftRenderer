#pragma once
#include "Math.h"
#include <SDL2/SDL.h>


class Window {
public:
    Window(const char* name) {
        m_surface = SDL_LoadBMP(name);
    }

    Window(int width, int height) {
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

    inline int getWidth() const {
        return m_surface->w;
    }

    inline int getHeight() const {
        return m_surface->h;
    }

    inline Vec2 getSize() const {
        return Vec2{ (float)m_surface->w, (float)m_surface->h };
    }

    void setPixel(int x, int y, const Color4& color) {
        *getPixel(x, y) = SDL_MapRGB(m_surface->format, color.r * 255, color.g * 255, color.b * 255);
    }

    Color4 getPixelColor(int x, int y) const {
        const Uint32* color = getPixel(x, y);
        Uint8 r, g, b, a;
        SDL_GetRGBA(*color, m_surface->format, &r, &g, &b, &a);
        return Color4{ r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f };
    }

    inline void clear(const Color4& color) {
        SDL_FillRect(m_surface, nullptr, SDL_MapRGBA(m_surface->format, color.r * 255, color.g * 255, color.b * 255, color.a * 255));
    }

    void save(const char* filename) {
        auto surface = SDL_ConvertSurfaceFormat(m_surface, SDL_PIXELFORMAT_RGB24, 0);
        if(surface) {
            SDL_SaveBMP(surface, filename);
            SDL_FreeSurface(surface);
        } else {
            std::cout << "Save failed: " << SDL_GetError() << std::endl;
        }
    }

private:
    SDL_Surface* m_surface;

    Uint32* getPixel(int x, int y) const {
        Uint8* ptr = (Uint8*)m_surface->pixels;
        return (Uint32*)(ptr + y * m_surface->pitch + x * m_surface->format->BytesPerPixel);
    }
};
