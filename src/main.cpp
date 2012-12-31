#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <SDL/SDL.h>

Uint32 GetPixel(SDL_Surface *s, Uint32 x, Uint32 y)
{
    return *(Uint16*)((Uint8*)s->pixels+y*s->pitch+x*2);
}

void SetPixel(SDL_Surface *s, Uint32 x, Uint32 y, Uint32 col)
{
    *(Uint16*)((Uint8*)s->pixels+y*s->pitch+x*2)=col;
}

SDL_Surface *ScaleSurface(SDL_Surface *Surface, Uint16 Width, Uint16 Height)
{
    if(!Surface || !Width || !Height)
        return 0;

    SDL_Surface *_ret = SDL_CreateRGBSurface(Surface->flags, Width, Height, Surface->format->BitsPerPixel,
        Surface->format->Rmask, Surface->format->Gmask, Surface->format->Bmask, Surface->format->Amask);

    double _stretch_factor_x = (static_cast<double>(Width)  / static_cast<double>(Surface->w)),
           _stretch_factor_y = (static_cast<double>(Height) / static_cast<double>(Surface->h));

    for(Sint32 y = 0; y < Surface->h; y++)
        for(Sint32 x = 0; x < Surface->w; x++)
            for(Sint32 o_y = 0; o_y < _stretch_factor_y; ++o_y)
                for(Sint32 o_x = 0; o_x < _stretch_factor_x; ++o_x)
                    SetPixel(_ret, static_cast<Sint32>(_stretch_factor_x * x) + o_x, static_cast<Sint32>(_stretch_factor_y * y) + o_y, GetPixel(Surface, x, y));
    return _ret;
}

int main(int argc, char *argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO)<0)
        return 1;
    atexit(SDL_Quit);

    SDL_Surface *screen=SDL_SetVideoMode(800,600,16,SDL_SWSURFACE);
    SDL_Surface *buffer=SDL_CreateRGBSurface(SDL_SWSURFACE,200,150,16,0,0,0,0);

    Uint32 col = SDL_MapRGB(screen->format, 255, 255, 255);
    SetPixel(buffer,10,10,col);

    SDL_Surface *scaled=ScaleSurface(buffer,800,600);
    SDL_BlitSurface(scaled,NULL,screen,NULL);
    SDL_UpdateRect(screen,0,0,screen->w,screen->h);

    SDL_Event event;
    while(1)
    {
        SDL_WaitEvent(&event);

        switch (event.type)
        {
        case SDL_QUIT:
            exit(0);
        default:
            break;
        }
    }
}
