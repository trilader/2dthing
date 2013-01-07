#ifndef TILE_H
#define TILE_H

const int TILE_SIZE = 16;

class Palette;
class Bitmap;

class Tile
{
public:
    Tile(Bitmap *bitmap, Palette *palette);
    virtual ~Tile();
    Palette *getPalette() const;
    virtual Bitmap *getBitmap();
    virtual bool drawOn(Bitmap* bitmap, int x, int y) = 0;
private:
    Palette *palette;
    Bitmap *bitmap;
};

#endif // TILE_H
