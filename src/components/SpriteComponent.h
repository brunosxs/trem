#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H
#include "../core/component.h"
#include "../core/texture_manager.h"
#include "../core/asset_manager.h"
#include <SDL2/SDL.h>
#include "../game.h"
#include "transform.h"


class SpriteComponent: public Component {
private:
    SDL_Texture *texture;
    SDL_Rect sourceRectangle;
    SDL_Rect destinationRectangle;
    TransformComponent *transform;

public:
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    ~SpriteComponent();
    void init() override;
    void update(float delta) override;
    void render() override;
    SpriteComponent(const char *filePath);

    void SetTexture(std::string assetTextureId) {
        texture = Game::AssetManager->GetTexture(assetTextureId);
    }


};
#endif // !SPRITE_COMPONENT_H
