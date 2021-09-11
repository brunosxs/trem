//
// Created by brunosxs on 15/06/2021.
//

#ifndef RETRODL8_ENGINE_H
#define RETRODL8_ENGINE_H


#include "asset_manager.h"
#include "../constants.h"

class Engine {
    static EntityManager* manager;
    static SDL_Window* window =  SDL_CreateWindow(
            "Game",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            WINDOW_WIDTH, WINDOW_HEIGTH,
            SDL_WINDOW_BORDERLESS)
    static SDL_Renderer* renderer = SDL_CreateRenderer();
    static AssetManager* AssetManager = new AssetManager();

};


#endif //RETRODL8_ENGINE_H
