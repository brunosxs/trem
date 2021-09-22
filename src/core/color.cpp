//
// Created by brunosxs on 20/09/2021.
//

#include "color.h"
#include "SDL2/SDL.h"

const SDL_PixelFormat* Color::pixelFormat = nullptr;

void Color::InitColorFormat(const SDL_PixelFormat *pPixelFormat) {
    Color::pixelFormat = pPixelFormat;
};

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    SetRGBA(r,g,b,a);
};

Color::Color(uint8_t r, uint8_t g, uint8_t b) {
    SetRGBA(r, g, b, 255);
};

void Color::SetRGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    // helper method that makes sdl take care of the RGBA encoding between different systems
    color = SDL_MapRGBA(pixelFormat, r, g, b, a);
}

void Color::SetRed(uint8_t red) {
    uint8_t r, g, b, a;
    SDL_GetRGBA(color, pixelFormat, &r, &g, &b, &a);
    SetRGBA(red, g, b, a);
};

void Color::SetGreen(uint8_t green) {
    uint8_t r, g, b, a;
    SDL_GetRGBA(color, pixelFormat, &r, &g, &b, &a);
    SetRGBA(r, green, b, a);
};

void Color::SetBlue(uint8_t blue) {
    uint8_t r, g, b, a;
    SDL_GetRGBA(color, pixelFormat, &r, &g, &b, &a);
    SetRGBA(r, g, blue, a);
};

void Color::SetAlpha(uint8_t alpha) {
    uint8_t r, g, b, a;
    SDL_GetRGBA(color, pixelFormat, &r, &g, &b, &a);
    SetRGBA(r, g, b, alpha);
};

uint8_t Color::GetRed() {
    uint8_t r, g, b, a;
    SDL_GetRGBA(color, pixelFormat, &r, &g, &b, &a);
    return r;
};

uint8_t Color::GetGreen() {
    uint8_t r, g, b, a;
    SDL_GetRGBA(color, pixelFormat, &r, &g, &b, &a);
    return g;
};

uint8_t Color::GetBlue() {
    uint8_t r, g, b, a;
    SDL_GetRGBA(color, pixelFormat, &r, &g, &b, &a);
    return b;
};

uint8_t Color::GetAlpha() {
    uint8_t r, g, b, a;
    SDL_GetRGBA(color, pixelFormat, &r, &g, &b, &a);
    return a;
}

Color Color::Black() { return Color(0, 0, 0); }

Color Color::White() { return Color(255, 255, 255); }

Color Color::Red() { return Color(255, 0, 0); }

Color Color::Green() { return Color(0, 255, 0); }

Color Color::Blue() { return Color(0, 0, 255); }

Color Color::Yellow() { return Color(255, 255, 0); }

Color Color::Magenta() { return Color(255, 0, 255); }

Color Color::Cyan() { return Color(37, 240, 217); }

Color Color::Pink() { return Color(252, 197, 224); }

Color Color::Orange() { return Color(245, 190, 100); };
