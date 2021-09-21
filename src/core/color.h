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

    static Color Black() { return Color(0, 0, 0); };

    static Color White() { return Color(255, 255, 255); };

    static Color Red() { return Color(255, 0, 0); };

    static Color Green() { return Color(0, 255, 0); };

    static Color Blue() { return Color(0, 0, 255); };

    static Color Yellow() { return Color(255, 255, 0); };

    static Color Magenta() { return Color(255, 0, 255); };

    static Color Cyan() { return Color(37, 240, 217); };

    static Color Pink() { return Color(252, 197, 224); };

    static Color Orange() { return Color(245, 190, 100); };

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
