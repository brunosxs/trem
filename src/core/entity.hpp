#ifndef ENTITY_H
#define ENTITY_H
#include <vector>
#include <string>
#include <map>
#include <typeinfo>

class Component;
class EntityManager;

class Entity
{
private:
    std::vector<Component *> components;
    bool active;
    EntityManager &manager;
    std::map<const std::type_info*, Component*> componentTypeMap;

public:
    std::string name;
    Entity(EntityManager& p_manager);
    Entity(EntityManager& p_manager, std::string& p_name);
    void update(float delta);
    void render();
    void destroy();
    bool is_active() const;

    template <class T, class ...TArgs>
    T &add_component(TArgs &&...args)
    {
        T *new_component(new T(std::forward<TArgs>(args)...));
        new_component->owner = this;
        components.emplace_back(new_component);
        componentTypeMap[&typeid(*new_component)] = new_component;
        new_component->init();
        return *new_component;
    }

    template<class Component>
        Component* GetComponent() {
            return static_cast<Component*>(componentTypeMap[&typeid(Component)]);
        }
};

#endif
