#ifndef COLOR_H
#define COLOR_H

#include <SDL/SDL.h>

class Color
{
public:
    Color();
    Color(Uint8 r, Uint8 g, Uint8 b);
    Color(Uint32 pix, SDL_PixelFormat *fmt);
    Uint32 toPixel(SDL_PixelFormat *fmt) const;
    void fromPixel(Uint32 pix, SDL_PixelFormat *fmt);
    Uint8 getR() const;
    Uint8 getG() const;
    Uint8 getB() const;
    bool operator==(Color other);
    static Color White;
    static Color Black;
    static Color Transparent;
    static Color Red;
    static Color Green;
    static Color Yellow;
    static Color Blue;
private:
    Uint8 r,g,b;
};

#endif // COLOR_H
