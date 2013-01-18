#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <SDL/SDL.h>
#include "Bitmap.h"
#include "Screen.h"
#include "Gui.h"
#include "Color.h"
#include "NormalFont.h"

int main(int argc, char *argv[])
{
    new NormalFont();
    Screen screen = Screen(100, 100, 4);

    //Bitmap b2(100,10);
    //NormalFont::instance->drawTo(&b2,0,0,std::string("Hallo Welt."));
    //Color p_cols[]={Color::Blue,Color(0xab,0xab,0xab),Color(0xcf,0xcf,0xcf),Color(),Color(),Color(),Color(),Color::Transparent};
    //Palette p(p_cols);
    Gui::Box box(NormalFont::instance->measureW("Test"),8,NULL);
    Bitmap b=box.render();
    NormalFont::instance->drawTo(&b,5,5,std::string("Test"));
    screen.draw(&b,0,0);

    //screen.draw(&b2,0,10);

    screen.update();

    SDL_Event event;
    while(1)
    {
        SDL_WaitEvent(&event);

        switch (event.type)
        {
        case SDL_QUIT:
            delete NormalFont::instance;
            exit(0);
        default:
            break;
        }
    }
}
