#ifndef PALETTE_H
#define PALETTE_H

#include <SDL/SDL.h>
#include <map>
#include "Color.h"

const unsigned int MAX_PALETTE_COLORS = 8;

class Palette
{
public:
    Palette(Color colors[MAX_PALETTE_COLORS]);
    Color getReplacementColor(Color color) const;
    static Color PALETTE_COLOR_1;
    static Color PALETTE_COLOR_2;
    static Color PALETTE_COLOR_3;
    static Color PALETTE_COLOR_4;
    static Color PALETTE_COLOR_5;
    static Color PALETTE_COLOR_6;
    static Color PALETTE_COLOR_7;
    static Color PALETTE_COLOR_8;
private:
    Color *colors;
};

#endif // PALETTE_H
