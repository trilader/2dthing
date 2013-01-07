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
private:
    Color *colors;
};

#endif // PALETTE_H
