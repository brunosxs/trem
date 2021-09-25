//
// Created by brunosxs on 13/09/2021.
//

#include <iostream>
#include <SDL2/SDL.h>
#include "core/color.h"
#include "core/screen.h"
const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;


int main(int argc, const char *argv[]) {

    Screen screen;
    screen.Init(SCREEN_WIDTH, SCREEN_HEIGHT, 2);
    screen.Draw(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, Color::Yellow());
    screen.Draw(SCREEN_WIDTH / 2 + 1, SCREEN_HEIGHT / 2, Color::Yellow());
    screen.Draw(SCREEN_WIDTH / 2 + 2, SCREEN_HEIGHT / 2, Color::Yellow());
    screen.Draw(SCREEN_WIDTH / 2 + 3, SCREEN_HEIGHT / 2, Color::Yellow());
    screen.SwapBuffer();

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
    SDL_Quit();

    return 0;
}

size_t GetIndex(SDL_Surface* surface, int row, int column) {
    return row * surface->w + column;
}

