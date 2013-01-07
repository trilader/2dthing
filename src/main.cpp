#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <SDL/SDL.h>
#include "Bitmap.h"
#include "Screen.h"
#include "NormalFont.h"

int main(int argc, char *argv[])
{
    new NormalFont();
    Screen screen = Screen(100, 100, 4);

    /*Bitmap *b = new Bitmap(200,150);
    for(int i=0;i<10;i++)
    {
        b->setPixel(10+i,10,50+i*20,255,255);
        b->setPixel(10+i,11,255,255,255);
    }
    screen.draw(b, 0, 0);*/

    Bitmap b2(100,100);
    //for(int i=0;i<16*6;i++) NormalFont::instance->debug(&b2,i);
    NormalFont::instance->drawTo(&b2,0,0,std::string("Hallo Welt."));
    //NormalFont::instance->printLookup();
    screen.draw(&b2,0,0);

    screen.update();

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
