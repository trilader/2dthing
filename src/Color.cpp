#include "Color.h"

Color Color::White(255,255,255);
Color Color::Black(0,0,0);
Color Color::Transparent(255,0,255);
Color Color::Red(255,0,0);
Color Color::Green(0,255,0);
Color Color::Yellow(255,255,0);
Color Color::Blue(0,0,255);

Color::Color()
{
    this->r=0;
    this->g=0;
    this->b=0;
}

Color::Color(Uint8 r, Uint8 g, Uint8 b)
{
    this->r=r;
    this->g=g;
    this->b=b;
}

Color::Color(Uint32 pix, SDL_PixelFormat *fmt)
{
    fromPixel(pix, fmt);
}

Uint32 Color::toPixel(SDL_PixelFormat *fmt) const
{
    return SDL_MapRGB(fmt, r, g, b);
}

void Color::fromPixel(Uint32 pix, SDL_PixelFormat *fmt)
{
    SDL_GetRGB(pix, fmt, &r, &g, &b);
}

Uint8 Color::getR() const
{
    return r;
}

Uint8 Color::getG() const
{
    return g;
}

Uint8 Color::getB() const
{
    return b;
}

bool Color::operator==(Color other)
{
    return r==other.getR()&&g==other.getG()&&b==other.getB();
}
