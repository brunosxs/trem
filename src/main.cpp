//
// Created by brunosxs on 13/09/2021.
//

#include <iostream>
#include <SDL2/SDL.h>
#include "core/color.h"
#include "core/screenBuffer.h"
const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;


int main(int argc, const char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO)) {
        std::cout << SDL_GetError() << std::endl;
        return 1;
    }
    SDL_Window *window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
                                          SCREEN_HEIGHT, 0);
    if (window == nullptr) {
        std::cout << "Could not create window for the game " << SDL_GetError() << std::endl;
        return 2;
    }
    // this is the array of pixels in the screen
    SDL_Surface* mainSurface = SDL_GetWindowSurface(window);
    if (mainSurface == nullptr) {
        std::cout << "Could not get the surface" <<std::endl;
    }

    SDL_PixelFormat* pixelFormat = mainSurface->format;
    Color::InitColorFormat(pixelFormat);
    ScreenBuffer screenBuffer;
    screenBuffer.Init(pixelFormat->format, mainSurface->w, mainSurface->h);

    screenBuffer. SetPixel(Color::Green(), SCREEN_WIDTH /2, SCREEN_HEIGHT / 2);
    SDL_BlitSurface(screenBuffer.GetSurface(), nullptr, mainSurface, nullptr);
    SDL_UpdateWindowSurface(window);

    SDL_Event sdlEvent;
    bool running = true;

    while (running) {
        while (SDL_PollEvent(&sdlEvent)) {
            switch (sdlEvent.type) {
                case SDL_QUIT:
                    running = false;
                    break;

            }
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

size_t GetIndex(SDL_Surface* surface, int row, int column) {
    return row * surface->w + column;
}

