//
// Created by brunosxs on 21/09/2021.
//

#ifndef TREM_SCREENBUFFER_H
#define TREM_SCREENBUFFER_H

#include "color.h"
#include <cstddef>

class Color;
struct SDL_Surface;

class ScreenBuffer {
public:
    ScreenBuffer();
    ScreenBuffer(const ScreenBuffer& screenBuffer);
    ~ScreenBuffer();
    size_t GetIndex(int r, int c);
    ScreenBuffer& operator=(const ScreenBuffer& screenBuffer);
    void Init(uint32_t format, uint32_t width, uint32_t height);
    void Clear(const Color& c = Color::Black());
    void SetPixel(int x, int y, const Color &color);
    void GetPixel();
    inline SDL_Surface* GetSurface() { return surface;};
private:
    SDL_Surface* surface;
};


#endif //TREM_SCREENBUFFER_H
