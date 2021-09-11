#include "entity_manager.h"
#include "component.h"
#include "entity.h"

Entity::Entity(EntityManager &p_manager) : manager(p_manager)
{
    this->active = true;
}

Entity::Entity(EntityManager& p_manager, std::string& p_name) : manager(p_manager), name(p_name)
{
    this->active = true;
}

void Entity::update(float delta)
{
    for (auto &current_component : components)
    {
        current_component->update(delta);
    }
}
void Entity::render()
{
    for (auto &current_component : components)
    {
        current_component->render();
    }
}

void Entity::destroy()
{
    this->active = false;
}

bool Entity::is_active() const
{
    return this->active;
}
