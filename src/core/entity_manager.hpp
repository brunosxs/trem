#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H
#include <vector>
#include <string>

class Entity;

class EntityManager
{
private:
    std::vector<Entity *> entities;

public:
    EntityManager();
    ~EntityManager();
    void clear_data();
    bool is_empty();
    Entity &add_entity(std::string);
    void update(float delta);
    void render();
    std::vector<Entity *> get_entities() const;
    unsigned int count();
};
#endif
