#include "NormalFont.h"
#include "Bitmap.h"
#include "ImageLoader.h"
#include "BitmapSlicer.h"

NormalFont *NormalFont::instance;

NormalFont::NormalFont(): Font()
{
    Bitmap *font=ImageLoader::load("res/fonts/normal.png");
    data=BitmapSlicer::slice(font,8);
    lookup="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890!\"$%&/()=?[]{}\\.,:-+_><|;'~*^ ";
    glyphWidth=5;
    glyphHeight=8;
    glyphSpace=1;
    lineHeight=8;
    lineSpace=1;
    delete font;
    instance=this;
}

NormalFont::~NormalFont()
{
    instance=NULL;
}

void NormalFont::printLookup()
{
    for(size_t i=0;i<lookup.length();i++)
        std::cout<<"Lookup: "<<std::cout.width(2)<<i<<"=\""<<lookup[i]<<"\""<<std::endl;
}

void NormalFont::debug(Bitmap *b, int num)
{
    data[num]->copyTo(b,(num%8)*8,(num/8)*8);
}

void NormalFont::drawTo(Bitmap *b, int x, int y, std::string text)
{
    std::vector<std::string> parts=StringUtil::split(text);
    int y0=0;
    for(std::vector<std::string>::iterator it=parts.begin();it!=parts.end();it++)
    {
        std::string part=*it;
        std::cout<<"part:"<<part<<std::endl;
        for(size_t i=0;i<part.length();i++)
        {
            int pos=lookup.find(part[i]);
            std::cout<<"found "<<part[i]<<" at index "<<pos<<std::endl;
            data[pos]->copyTo(b,x+i*(glyphWidth+glyphSpace),y+y0,0,0,glyphWidth,glyphHeight);
        }
        y0+=glyphHeight+lineSpace;
    }
}

