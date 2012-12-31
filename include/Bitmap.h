#ifndef BITMAP_H
#define BITMAP_H

#include <SDL/SDL.h>

class Bitmap
{
public:
    Bitmap(int w, int h);
    Bitmap(SDL_Surface *s, bool manage=true);
    ~Bitmap();
    int getW() const;
    int getH() const;
    bool getManaged();
    bool copyTo(Bitmap *b, int tx, int ty);
    void setPixel(int x, int y, Uint32 color);
    void setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b);
    Uint32 getPixel(int x, int y);
    Bitmap scale(int x, int y);
    SDL_Surface *getSurface();
private:
    int w,h;
    bool managed;
    SDL_Surface *surface;

};

#endif // BITMAP_H
