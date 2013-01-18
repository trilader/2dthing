#ifndef GUI_H
#define GUI_H
#include <vector>

class Palette;
class Bitmap;

namespace Gui
{

class Element
{

};

class Window: public Element
{

};

class Dialog: public Window
{

};

class Menu: public Window
{

};

class Control: public Element
{

};

class Box
{
public:
    Box(int iw, int ih, Palette *p);
    Bitmap render();
private:
    int innerWidth, innerHeight;
    int width, height;
    Palette *palette;
    std::vector<Bitmap*> parts;
};

}
#endif // GUI_H
