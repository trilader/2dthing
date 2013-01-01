#ifndef FONT_H
#define FONT_H

#include <iostream>
#include <vector>
#include "StringUtil.h"

class Bitmap;

class Font
{
public:
    Font();
    virtual ~Font();
    virtual void drawTo(Bitmap *b, int x, int y, std::string text)=0;
    int measureH(std::string text);
    int measureW(std::string text);
protected:
    std::vector<Bitmap*> data;
    std::string lookup;
};

#endif // FONT_H
