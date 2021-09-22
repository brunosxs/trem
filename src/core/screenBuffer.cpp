//
// Created by brunosxs on 21/09/2021.
//

#include <cassert>
#include "SDL2/SDL.h"
#include "screenBuffer.h"

void ScreenBuffer::SetPixel(const Color &color, int x, int y) {
    assert(surface);
    if (surface && (y < surface->h && y >= 0 && x >= 0 && x < surface->w)) {
        SDL_LockSurface(surface);
        uint32_t *pixels = (uint32_t *) surface->pixels;
        size_t index = GetIndex(y, x);
        pixels[index] = color.GetPixelColor();
        SDL_UnlockSurface(surface);
    }
}

/**
 * Pixels are stored in a one-dimensional array, this helper method translates from a 2d array to how data is trully laid.
 * @param r Row (y axis)
 * @param c Column (x axis)
 * @return the index of the current pixel or -1 if error
 */
size_t ScreenBuffer::GetIndex(int r, int c) {
    assert(surface);
    if (surface) {
        return r * surface->w + c;
    }
    return -1;
}

ScreenBuffer::ScreenBuffer() : surface(nullptr) {
}

ScreenBuffer::ScreenBuffer(const ScreenBuffer &screenBuffer) {
    surface = SDL_CreateRGBSurfaceWithFormat(0, screenBuffer.surface->w, screenBuffer.surface->h, 0,
                                             screenBuffer.surface->format->format);
    // copy the pixels
    SDL_BlitSurface(screenBuffer.surface, nullptr, surface, nullptr);

}

ScreenBuffer::~ScreenBuffer() {
    if (surface) {
        SDL_FreeSurface(surface);
    }
}

ScreenBuffer &ScreenBuffer::operator=(const ScreenBuffer &screenBuffer) {
    if (this == &screenBuffer) {
        return *this;
    }
    if (surface != nullptr) {
        SDL_FreeSurface(surface);
        surface = nullptr;
    }
    if (screenBuffer.surface != nullptr) {
        surface = SDL_CreateRGBSurfaceWithFormat(0, screenBuffer.surface->w, screenBuffer.surface->h, 0,
                                                 screenBuffer.surface->format->format);
        SDL_BlitSurface(screenBuffer.surface, nullptr, surface, nullptr);
    }

    return *this;
}

void ScreenBuffer::Init(uint32_t format, uint32_t width, uint32_t height) {
    surface = SDL_CreateRGBSurfaceWithFormat(0, width, height, 0, format);
    Clear();
}

void ScreenBuffer::Clear(const Color &c) {

    assert(surface);
    if (surface) {
        SDL_FillRect(surface, nullptr, c.GetPixelColor());
    }
}
