#ifndef BITMAP_H
#define BITMAP_H

#include <SDL/SDL.h>
class Palette;
class Color;

class Bitmap
{
public:
    Bitmap(int w, int h, bool transparent=true);
    Bitmap(SDL_Surface *s, bool manage=true);
    ~Bitmap();
    int getW() const;
    int getH() const;
    bool getManaged() const;
    bool copyTo(Bitmap *b, int tx, int ty, int sx=0, int sy=0, int w=-1, int h=-1, bool transparent=true) const;
    void setPixel(int x, int y, Uint32 color);
    void setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b);
    Uint32 getPixel(int x, int y) const;
    Bitmap flipH() const;
    Bitmap flipV() const;
    Bitmap clone() const;
    Bitmap scale(int x, int y) const;
    void fill(Color col);
    void applyPalette(Palette *p);
    SDL_Surface *getSurface() const;
private:
    int w,h;
    bool managed;
    bool transparent;
    SDL_Surface *surface;

};

#endif // BITMAP_H
