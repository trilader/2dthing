#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <SDL/SDL.h>
#include "Bitmap.h"
#include "Screen.h"
#include "Gui.h"
#include "Color.h"
#include "NormalFont.h"
#include "Palette.h"

int main(int argc, char *argv[])
{
    new NormalFont();
    Screen screen = Screen(100, 100, 6);

    Color p_cols[]={Color::Blue,
        Color::Red,
        Color(0xcf,0xcf,0xcf),
        Color::White,
        Color::White,
        Color::White,
        Color::White,
        Color::Transparent
    };

    Palette p(p_cols);
    Bitmap bg(100,100);
    bg.fill(Color(0xab,0xab,0xab));
    //Gui::Box box(NormalFont::instance->measureW("Test"),8,&p);
    Gui::Box box(10,10,&p);
    Bitmap b=box.render();
    //NormalFont::instance->drawTo(&b,5,5,"Test");

    screen.draw(&bg,0,0);
    screen.draw(&b,0,0);
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
