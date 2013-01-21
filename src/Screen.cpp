#include <SDL/SDL.h>
#include "Bitmap.h"
#include "Screen.h"

Screen::Screen(int w, int h, int scale)
{
    this->w = w;
    this->h = h;
    this->scale = scale;
    if(SDL_Init(SDL_INIT_VIDEO)<0)
        exit(1);
    surface = SDL_SetVideoMode(w*scale, h*scale, 32, SDL_SWSURFACE);
    bmp = new Bitmap(surface);
}

Screen::~Screen()
{
    delete bmp;
    SDL_Quit();
}

int Screen::getH() const
{
    return h;
}

int Screen::getW() const
{
    return w;
}

bool Screen::draw(Bitmap *bitmap, int x, int y)
{
    if(x>w||y>h) return false;
    return bitmap->scale(bitmap->getW()*scale, bitmap->getH()*scale).copyTo(bmp, x*scale, y*scale);
}

void Screen::update()
{
    SDL_UpdateRect(surface, 0, 0, surface->w, surface->h);
}
