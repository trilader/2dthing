#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <SDL/SDL.h>
#include "Bitmap.h"
#include "Screen.h"

int main(int argc, char *argv[])
{
    Screen screen = Screen(50, 50, 4);

    Bitmap *b = new Bitmap(200,150);
    b->setPixel(10,10,255,255,255);

    screen.draw(b, 0, 0);

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
