#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <SDL/SDL.h>
#include "Bitmap.h"

int main(int argc, char *argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO)<0)
        return 1;
    atexit(SDL_Quit);

    SDL_Surface *screen=SDL_SetVideoMode(800,600,16,SDL_SWSURFACE);
    Bitmap screenB(screen, false);

    Bitmap b(200,150);
    b.setPixel(10,10,255,255,255);

    b.scale(800,600).copyTo(screenB,0,0);
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
