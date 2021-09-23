//
// Created by brunosxs on 22/09/2021.
//

#include "screen.h"
#include "SDL2/SDL.h"
#include "utils/vector2d.h"
#include <iostream>
#include <cassert>

Screen::Screen(): width(0), height(0), surface(nullptr), window(nullptr) {

}

Screen::~Screen() {
    if (window) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    SDL_Quit();

}

SDL_Window *Screen::Init(uint32_t w, uint32_t h, uint32_t mag) {
    if (SDL_Init(SDL_INIT_VIDEO)) {
        std::cout << SDL_GetError() << std::endl;
        return nullptr;
    }
    window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w,
                                           h, 0);
    assert(window);
    if (window) {
        surface = SDL_GetWindowSurface(window);
        SDL_PixelFormat* pixelFormat = surface->format;
        Color::InitColorFormat(pixelFormat);
        clearColor = Color::Black();
        backBuffer.Init(pixelFormat->format, width, height);
        backBuffer.Clear(clearColor);
        return window;
    }

    if (surface == nullptr) {
        std::cout << "Could not get the surface" <<std::endl;
    }


}

void Screen::Draw(int x, int y, const Color &color) {
    if (window) {
        backBuffer.SetPixel(x, y, color);
    }
}

void Screen::Draw(Vector2d &point, const Color &color) {
    Draw(point.GetX(), point.GetY(), color);
}

void Screen::SwapBuffer() {
    assert(window);
    if (window) {
        ClearScreen();
        SDL_BlitSurface(backBuffer.GetSurface(), nullptr, surface, nullptr);
        SDL_UpdateWindowSurface(window);
        backBuffer.Clear(clearColor);
    }

}

void Screen::ClearScreen() {
    assert(window);
    if (window) {
        SDL_FillRect(surface, nullptr, clearColor.GetPixelColor());
    }
}
