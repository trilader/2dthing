#include <SDL/SDL.h>
#include <iostream>
#include "Bitmap.h"
#include "Color.h"

Bitmap::Bitmap(int w, int h)
{
    this->w=w;
    this->h=h;
    this->managed=true;
    this->surface=SDL_CreateRGBSurface(SDL_SWSURFACE, w, h, 32, 0, 0, 0, 0);
}

Bitmap::Bitmap(SDL_Surface *s, bool manage)
{
    this->w=s->w;
    this->h=s->h;
    this->managed=manage;
    this->surface=s;
}

Bitmap::~Bitmap()
{
    if(managed)
        SDL_FreeSurface(this->surface);
}

int Bitmap::getW() const
{
    return w;
}

int Bitmap::getH() const
{
    return h;
}

bool Bitmap::getManaged()
{
    return managed;
}
/*
bool Bitmap::copyTo(Bitmap *b, int tx, int ty, bool transparent)
{
    int ow=b->getW(), oh=b->getH();
    if(tx>ow||ty>oh) return false;
    for(int y=0;y<h;y++)
    {
        if(ty+y>oh) continue;
        for(int x=0;x<w;x++)
        {
            if(tx+x>ow) continue;
            Uint32 p=getPixel(x,y);
            if(transparent && Color(p,surface->format)==Color(255,0,255)) continue;
            b->setPixel(tx+x, ty+y, p);
        }
    }
    return true;
}
*/
bool Bitmap::copyTo(Bitmap *b, int tx, int ty, int sx, int sy, int cw, int ch, bool transparent)
{
    int ow=b->getW(), oh=b->getH();
    if(cw==-1) cw=w-sx;
    if(ch==-1) ch=h-sy;

    if(tx>ow||ty>oh) return false;
    for(int y=sy;y<ch;y++)
    {
        if(ty+y>=oh) continue;
        for(int x=sx;x<cw;x++)
        {
            if(tx+x>=ow) continue;
            Uint32 p=getPixel(x,y);
            if(transparent && Color(p,surface->format)==Color(255,0,255)) continue;
            b->setPixel(tx+x, ty+y, p);
        }
    }
    return true;
}

void Bitmap::setPixel(int x, int y, Uint32 color)
{
    *(Uint32*)((Uint8*)surface->pixels+y*surface->pitch+x*surface->format->BytesPerPixel)=color;
}

void Bitmap::setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b)
{
    setPixel(x,y,SDL_MapRGB(surface->format,r,g,b));
}

Uint32 Bitmap::getPixel(int x, int y)
{
    return *(Uint32*)((Uint8*)surface->pixels+y*surface->pitch+x*surface->format->BytesPerPixel);
}

Bitmap Bitmap::scale(int nw, int nh)
{
    Bitmap ret(nw,nh);

    double sx = double(nw)/double(surface->w),
           sy = double(nh)/double(surface->h);

    for(int y = 0; y < surface->h; y++)
        for(int x = 0; x < surface->w; x++)
            for(int o_y = 0; o_y < sy; ++o_y)
                for(int o_x = 0; o_x < sx; ++o_x)
                    ret.setPixel(int(sx*x)+o_x, int(sy*y)+o_y, getPixel(x, y));
    return ret;
}

SDL_Surface *Bitmap::getSurface()
{
    return surface;
}
