#include <iostream>
#include "game.h"
#include "constants.h"
#include "../libs/glm/glm.hpp"
#include "components/transform.hpp"
#include "core/entity.hpp"
#include "core/entity_manager.hpp"
#include <jansson.h>
EntityManager *manager;
SDL_Renderer *Game::renderer;

Game::Game()
{
    run = false;
    ticks_last_frame = 0;
    manager = new EntityManager();
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

void Game::process_input()
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
    unsigned int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - ticks_last_frame);
    if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME)
    {
        SDL_Delay(time_to_wait);
    }
    float delta = ((SDL_GetTicks() - ticks_last_frame) / 1000.0f);
    // Clamp delta time
    delta = (delta > MAX_DELTA_TIME) ? 0.05f : delta;
    ticks_last_frame = SDL_GetTicks();
    // TODO: Here we call update on entity manager
    manager->update(delta);
}

void Game::render()
{
    // TODO: CALL render() of entityManager
    if (manager->is_empty())
    {
        return;
    }
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
    Entity &new_entity(manager->add_entity("projectile"));
    new_entity.add_component<TransformComponent>(glm::vec2(0.0, 0.0), glm::vec2(8.0, 8.0), 1.0);
}

Game::~Game()
{
    manager->destroy();
    delete manager;
}
