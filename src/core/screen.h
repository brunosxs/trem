//
// Created by brunosxs on 22/09/2021.
//

#ifndef TREM_SCREEN_H
#define TREM_SCREEN_H


#include <cstdint>
#include "screenBuffer.h"
#include "color.h"
struct SDL_Window;
struct SDL_Surface;

class Vector2;

class Screen {
public:
    Screen();
    ~Screen();
    SDL_Window* Init(uint32_t w, uint32_t h, uint32_t scale);
    void SwapBuffer();
    inline void SetClearColor(const Color& color) {clearColor = color;}
    inline uint32_t GetWidth() {return width;}
    inline uint32_t GetHeight() {return height;}

    void Draw(int x, int y, const Color& color);
    void Draw(Vector2& point, const Color& color);
    void ClearScreen();

private:
    uint32_t  width;
    uint32_t height;
    SDL_Window* window;
    SDL_Surface* surface;
    ScreenBuffer backBuffer;
    Color clearColor;
    // we do not want to copy
    Screen(const Screen& screen);
    // nor assign it
    Screen& operator=(const Screen& screen);

};


#endif //TREM_SCREEN_H
