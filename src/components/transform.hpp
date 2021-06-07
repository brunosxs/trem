#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__
#include "../core/component.hpp"
#include <glm.hpp>
#include <SDL2/SDL.h>

class TransformComponent : public Component
{
public:
    glm::vec2 position;
    glm::vec2 size;
    glm::vec2 velocity;
    float scale;
    TransformComponent(glm::vec2 p_position, glm::vec2 p_size, float p_scale)
    {
        position = p_position;
        size = p_size;
        velocity = glm::vec2(0, 0);
        scale = p_scale;
    }
    ~TransformComponent();
    void init();
    void update(float delta);
    void render();
};
#endif // __TRANSFORM_H__
