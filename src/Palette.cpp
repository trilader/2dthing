#include <map>
#include <SDL/SDL.h>
#include "Color.h"
#include "Palette.h"

const Color PALETTE_COLOR_1(0, 0, 0);
const Color PALETTE_COLOR_2(32, 32, 32);
const Color PALETTE_COLOR_3(64, 64, 64);
const Color PALETTE_COLOR_4(96, 96, 96);
const Color PALETTE_COLOR_5(128, 128, 128);
const Color PALETTE_COLOR_6(160, 160, 160);
const Color PALETTE_COLOR_7(192, 192, 192);
const Color PALETTE_COLOR_8(224, 224, 224);

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
}
