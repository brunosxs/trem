#include "../game.h"
#include "transform.hpp"

void TransformComponent::update(float delta)
{
    position.x += velocity.x * delta;
    position.y += velocity.y * delta;
}

void TransformComponent::init()
{
}

void TransformComponent::render()
{
    SDL_Rect transform_rectangle = {
        (int)position.x,
        (int)position.y,
        (int)size.x,
        (int)size.y};
    SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(Game::renderer, &transform_rectangle);
}
