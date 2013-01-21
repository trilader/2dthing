#include <map>
#include <SDL/SDL.h>
#include "Color.h"
#include "Palette.h"

Color Palette::PALETTE_COLOR_1(0x00, 0x00, 0x00);
Color Palette::PALETTE_COLOR_2(0x3d, 0x3d, 0x3d);
Color Palette::PALETTE_COLOR_3(0x5b, 0x5b, 0x5b);
Color Palette::PALETTE_COLOR_4(0x7a, 0x7a, 0x7a);
Color Palette::PALETTE_COLOR_5(0x99, 0x99, 0x99);
Color Palette::PALETTE_COLOR_6(0xb7, 0xb7, 0xb7);
Color Palette::PALETTE_COLOR_7(0xd6, 0xd6, 0xd6);
Color Palette::PALETTE_COLOR_8(0xff, 0xff, 0xff);

Palette::Palette(Color colors[])
{
    this->colors = colors;
}

Color Palette::getReplacementColor(Color color) const
{
    if (color == PALETTE_COLOR_1)
        return colors[0];
    if (color == PALETTE_COLOR_2)
        return colors[1];
    if (color == PALETTE_COLOR_3)
        return colors[2];
    if (color == PALETTE_COLOR_4)
        return colors[3];
    if (color == PALETTE_COLOR_5)
        return colors[4];
    if (color == PALETTE_COLOR_6)
        return colors[5];
    if (color == PALETTE_COLOR_7)
        return colors[6];
    if (color == PALETTE_COLOR_8)
        return colors[7];
    else
        return Color::Transparent;
}
