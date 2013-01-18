#ifndef NORMAL_FONT_H
#define NORMAL_FONT_H

#include "Font.h"

class NormalFont: public Font
{
public:
    NormalFont();
    ~NormalFont();
    void drawTo(Bitmap *b, int x, int y, std::string text);
    int measureW(std::string text);
    static NormalFont *instance;
private:
    int glyphWidth;
    int glyphHeight;
    int glyphSpace;
    int lineHeight;
    int lineSpace;
};

#endif // NORMAL_FONT_H
