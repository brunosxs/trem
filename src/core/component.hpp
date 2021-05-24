#ifndef COMPONENT_H
#define COMPONENT_H

class Entity;

class Component
{
public:
    Entity *owner;
    virtual void init(){};
    virtual void update(float delta){};
    virtual void render(){};
};

#endif
