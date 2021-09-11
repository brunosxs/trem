//
// Created by brunosxs on 08/06/2021.
//

#ifndef RETRODL8_ASSET_MANAGER_H
#define RETRODL8_ASSET_MANAGER_H


#include <map>
#include "entity_manager.h"
#include <SDL2/SDL.h>



class AssetManager {
private:
    EntityManager* manager;
    std::map<std::string, SDL_Texture*> textures;
public:
    AssetManager(EntityManager* manager);
    ~AssetManager();
    void ClearData();
    void AddTexture(std::string textureId, const char* filePath);
    SDL_Texture* GetTexture(std::string textureId);

};


#endif //RETRODL8_ASSET_MANAGER_H
