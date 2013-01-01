#include <string>
#include "Font.h"

Font::Font()
{

}

Font::~Font()
{

}

int Font::measureH(std::string text)
{
    size_t res=0;
    std::vector<std::string> substrs=StringUtil::split(text);
    for(std::vector<std::string>::iterator it=substrs.begin(); it!=substrs.end(); it++)
        res=std::max(res,(*it).length());
    return res*8;
}

int Font::measureW(std::string text)
{
    return std::max(8,StringUtil::count(text,'\n')*8);
}
