//
// Created by brunosxs on 08/06/2021.
//

#include "asset_manager.h"
#include "texture_manager.h"

AssetManager::AssetManager(EntityManager *manager): manager(manager) {

}

void AssetManager::ClearData() {
    textures.clear();
}

void AssetManager::AddTexture(std::string textureId, const char *filePath) {
    textures.emplace(textureId, TextureManager::LoadTexture(filePath));
}

SDL_Texture* AssetManager::GetTexture(std::string textureId) {
    return textures[textureId];
}