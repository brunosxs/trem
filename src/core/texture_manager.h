#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class TextureManager
{
private:

public:
    TextureManager(/* args */);
    ~TextureManager();
    static SDL_Texture* LoadTexture(const char* filename);
    static void DrawToTarget( SDL_Texture* texture, SDL_Rect sourceRectangle, SDL_Rect destinationRectangle, SDL_RendererFlip flip);

};

#endif