#include "entity.hpp"
#include "entity_manager.hpp"

EntityManager::EntityManager()
{
    entities = std::vector<Entity *>();
}

EntityManager::~EntityManager()
{
    delete &entities;
}

Entity &EntityManager::add_entity(std::string p_name)
{
    Entity *entity = new Entity(*this, p_name);
    entities.emplace_back(entity);
    return *entity;
}

void EntityManager::update(float delta)
{
    for (auto &entity : entities)
    {
        entity->update(delta);
    }
}

void EntityManager::render()
{
    for (auto &entity : entities)
    {
        entity->render();
    }
}

std::vector<Entity *> EntityManager::get_entities() const
{
    return entities;
}

void EntityManager::clear_data()
{
    for (auto &entity : entities)
    {
        entity->destroy();
    }
}

bool EntityManager::is_empty()
{
    return entities.size() == 0;
}

unsigned int EntityManager::count()
{
    return entities.size();
}

void EntityManager::destroy() {
    clear_data();
}