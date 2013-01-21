#include <SDL/SDL.h>
#include <iostream>
#include "Bitmap.h"
#include "Color.h"
#include "Palette.h"

Bitmap::Bitmap(int w, int h, bool transparent)
{
    this->w=w;
    this->h=h;
    this->transparent=transparent;
    this->managed=true;
    this->surface=SDL_CreateRGBSurface(SDL_SWSURFACE, w, h, 32, 0, 0, 0, 0);
    if(transparent)
        fill(Color::Transparent);
}

Bitmap::Bitmap(SDL_Surface *s, bool manage)
{
    this->w=s->w;
    this->h=s->h;
    this->transparent=false;
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

bool Bitmap::getManaged() const
{
    return managed;
}

// tx=Target-X, ty=Target-Y, sx=Source-X, sy=Source-Y, cw=Copy-Width, ch=Copy-Height
bool Bitmap::copyTo(Bitmap *b, int tx, int ty, int sx, int sy, int cw, int ch, bool transparent) const
{
    int ow=b->getW(), oh=b->getH();
    if(cw==-1) cw=w-sx;
    if(ch==-1) ch=h-sy;

    if(tx>ow||ty>oh) return false;
    for(int y=0;y<ch;y++)
    {
        if(ty+y>=oh) continue;
        for(int x=0;x<cw;x++)
        {
            if(tx+x>=ow) continue;
            Uint32 p=getPixel(x+sx,y+sy);
            if(transparent && Color(p,surface->format)==Color::Transparent) continue;
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

Uint32 Bitmap::getPixel(int x, int y) const
{
    return *(Uint32*)((Uint8*)surface->pixels+y*surface->pitch+x*surface->format->BytesPerPixel);
}

Bitmap Bitmap::flipH() const
{
    Bitmap m(w,h);
    for(int y=0; y<h; y++)
        for(int x=0; x<w; x++)
            m.setPixel(x,y,getPixel(w-x-1,y));
    return m;
}

Bitmap Bitmap::flipV() const
{
    Bitmap m(w,h);
    for(int y=0; y<h; y++)
        for(int x=0; x<w; x++)
            m.setPixel(x,y,getPixel(x,h-y-1));
    return m;
}

Bitmap Bitmap::clone() const
{
    Bitmap m(w,h);
    SDL_BlitSurface(getSurface(),NULL,m.getSurface(),NULL);
    return m;
}

Bitmap Bitmap::scale(int nw, int nh) const
{
    Bitmap ret(nw,nh);

    double sx = double(nw)/double(w),
           sy = double(nh)/double(h);

    for(int y = 0; y < h; y++)
        for(int x = 0; x < w; x++)
            for(int o_y = 0; o_y < sy; ++o_y)
                for(int o_x = 0; o_x < sx; ++o_x)
                    ret.setPixel(int(sx*x)+o_x, int(sy*y)+o_y, getPixel(x, y));
    return ret;
}

void Bitmap::fill(Color col)
{
    Uint32 pix=col.toPixel(surface->format);
    for(int y=0;y<h; y++)
        for(int x=0; x<w; x++)
            setPixel(x,y,pix);
}

void Bitmap::applyPalette(Palette *p)
{
    if(p==NULL)
        return;

    SDL_PixelFormat *fmt=surface->format;
    Color cur;
    Color rep;

    for(int y=0; y<h; y++)
    {
        for(int x=0; x<w; x++)
        {
            cur.fromPixel(getPixel(x,y),fmt);
            rep=p->getReplacementColor(cur);
            setPixel(x,y,rep.toPixel(fmt));
        }
    }
}

SDL_Surface *Bitmap::getSurface() const
{
    return surface;
}
