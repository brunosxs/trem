#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "core/asset_manager.h"


class Game{
    private:
        bool test = false;
        bool run = false;
        SDL_Window *window;
        float thicksLastFrame;
        
    public:
        static SDL_Renderer *renderer;
        Game();
        ~Game();
        void initialize(int width, int height);
        void ProcessInput();
        void update();
        void render();
        void destroy();
        void load_level(int level_number);
        bool is_running() const;
        void set_run(bool run);
};

#endif
