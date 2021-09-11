//
// Created by brunosxs on 14/06/2021.
//

#include "SpriteComponent.h"
#include "transform.h"
#include "../core/entity.h"


void SpriteComponent::render() {
    TextureManager::Draw(texture, sourceRectangle, destinationRectangle, flip);
}

void SpriteComponent::update(float delta) {
    Component::update(delta);
    destinationRectangle.x = (int) transform->position.x;
    destinationRectangle.y = (int) transform->position.y;
    destinationRectangle.w = (int) transform->size.x * transform->scale;
    destinationRectangle.h = (int) transform->size.y * transform->scale;
}

void SpriteComponent::init() {
    Component::init();
    transform = owner->GetComponent<TransformComponent>();
    sourceRectangle.x = 0;
    sourceRectangle.y = 0;
    sourceRectangle.w = transform->size.x;
    sourceRectangle.h = transform->size.y;
}
