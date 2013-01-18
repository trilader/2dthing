#include "Palette.h"
#include "Bitmap.h"
#include "Tile.h"
#include "StaticTile.h"
#include "Color.h"

StaticTile::StaticTile(Bitmap* bitmap, Palette* palette) : Tile(bitmap, palette)
{
    pbitmap = new Bitmap(bitmap->getW(), bitmap->getH());
    renderBitmap();
}

StaticTile::~StaticTile()
{
    delete pbitmap;
}

Bitmap* StaticTile::getBitmap() const
{
    return pbitmap;
}

bool StaticTile::drawOn(Bitmap* bitmap, int x, int y)
{
    return pbitmap->copyTo(bitmap, x, y);
}

void StaticTile::renderBitmap()
{
    int bw = Tile::getBitmap()->getW();
    int bh = Tile::getBitmap()->getH();
    Color currentColor;
    Tile::getBitmap()->copyTo(pbitmap, 0, 0);
    for (int x = 0; x < bw; x++)
    {
        for (int y = 0; y < bh; y++)
        {
            currentColor.fromPixel(pbitmap->getPixel(x, y), pbitmap->getSurface()->format);
            pbitmap->setPixel(x, y,getPalette()->getReplacementColor(currentColor).toPixel(pbitmap->getSurface()->format));
        }
    }
}
