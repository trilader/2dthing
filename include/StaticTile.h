#ifndef STATICTILE_H
#define STATICTILE_H

class StaticTile : public Tile
{
public:
    StaticTile(Bitmap *bitmap, Palette* palette);
    virtual ~StaticTile();
    Bitmap* getBitmap() const;
    bool drawOn(Bitmap* bitmap, int x, int y);
private:
    Bitmap *pbitmap;
    void renderBitmap();
};

#endif // STATICTILE_H
