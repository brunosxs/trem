//
// Created by brunosxs on 20/09/2021.
//

#ifndef TREM_COLOR_H
#define TREM_COLOR_H

#include <cstdint>

struct SDL_PixelFormat;

class Color {
    uint32_t color;
public:
    static const SDL_PixelFormat *pixelFormat;

    static void InitColorFormat(const SDL_PixelFormat *pPixelFormat);

    static Color Black();;

    static Color White();;

    static Color Red();;

    static Color Green();;

    static Color Blue();;

    static Color Yellow();;

    static Color Magenta();;

    static Color Cyan();;

    static Color Pink();;

    static Color Orange();;

    Color() : color(0) {};

    Color(uint32_t pColor) : color(pColor) {};

    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

    Color(uint8_t r, uint8_t g, uint8_t b);

    inline bool operator==(const Color &otherColor) const { return color == otherColor.color; };

    inline bool operator!=(const Color &otherColor) const { return !(*this == otherColor); };

    inline uint32_t GetPixelColor() const { return color; };

    void SetRGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

    void SetRed(uint8_t red);

    void SetGreen(uint8_t green);

    void SetBlue(uint8_t blue);

    void SetAlpha(uint8_t alpha);

    uint8_t GetRed();

    uint8_t GetGreen();

    uint8_t GetBlue();

    uint8_t GetAlpha();


};


#endif //TREM_COLOR_H
