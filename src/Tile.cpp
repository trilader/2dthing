#include "Bitmap.h"
#include "Palette.h"
#include "Tile.h"

Tile::Tile(Bitmap *bitmap, Palette *palette)
{
    this->bitmap = bitmap;
    this->palette = palette;
}

Tile::~Tile()
{
    // delete bitmap;
}

Palette* Tile::getPalette() const
{
    return palette;
}

Bitmap* Tile::getBitmap()
{
    return bitmap;
}
