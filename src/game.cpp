#include <iostream>
#include "game.h"
#include "constants.h"
#include <glm.hpp>
#include <jansson.h>


Game::Game()
{
    run = false;
    thicksLastFrame = 0;
    json_t *root;
    json_error_t error;
    root = json_load_file("assets/config.json", JSON_REJECT_DUPLICATES, &error);

    if (!root) {
        printf(error.text);
    }
    json_auto_t* result = json_object_get(root, "result");
    if (!json_is_string(result)) {
        printf("The value in the key 'result' should be a string, ignoring it");
    } else {
        printf(json_string_value(result));
    }
    
    json_decref(root);
    
}

void Game::ProcessInput()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
    {
        set_run(false);
        break;
    }
    case SDL_KEYDOWN:
    {
        if (event.key.keysym.sym == SDLK_ESCAPE)
        {
            set_run(false);
            break;
        }
    }
    default:
    {
        break;
    }
    }
}

void Game::initialize(int width, int height)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "Problem initializing SDL" << std::endl;
        ;
        return;
    }
    window = SDL_CreateWindow(
        "Game",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width, height,
        SDL_WINDOW_BORDERLESS);
    if (!window)
    {
        std::cerr << "Window couldn't be created" << std::endl;
        return;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer)
    {
        std::cerr << "Renderer couldn't be created" << std::endl;
        return;
    }
    load_level(0);
    set_run(true);
    return;
}

void Game::set_run(bool r)
{
    run = r;
}

void Game::update()
{
    // Wait until Target frame time has passed if the frame takes less to render than the FRAME_TARGET_TIME
    unsigned int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - thicksLastFrame);
    if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME)
    {
        SDL_Delay(time_to_wait);
    }
    float delta = ((SDL_GetTicks() - thicksLastFrame) / 1000.0f);
    // Clamp delta time
    delta = (delta > MAX_DELTA_TIME) ? 0.05f : delta;
    thicksLastFrame = SDL_GetTicks();
    // TODO: Here we call update on entity manager
}

void Game::render()
{
    // TODO: CALL render() of entityManager

    SDL_RenderPresent(renderer);
}

bool Game::is_running() const
{
    return run;
}

void Game::destroy()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    return;
}

void Game::load_level(int level_number)
{

}

Game::~Game()
{

}
