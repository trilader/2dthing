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
    virtual int measureH(std::string text);
    virtual int measureW(std::string text);
protected:
    std::vector<Bitmap*> data;
    std::string lookup;
};

#endif // FONT_H
