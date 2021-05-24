#ifndef ENTITY_H
#define ENTITY_H
#include <vector>
#include <string>

class Component;
class EntityManager;

class Entity
{
private:
    std::vector<Component *> components;
    bool active;
    EntityManager &manager;

public:
    std::string name;
    Entity(EntityManager& p_manager);
    Entity(EntityManager& p_manager, std::string& p_name);
    void update(float delta);
    void render();
    void destroy();
    bool is_active() const;

    template <typename T, typename... TArgs>
    T &add_component(TArgs &&...args)
    {
        T *new_component(new T(std::forward<TArgs>(args)...));
        new_component->owner = this;
        components.emplace_back(new_component);
        new_component->init();
        return *new_component;
    }
};

#endif
