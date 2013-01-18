#include "Gui.h"
#include <iostream>
#include "Bitmap.h"
#include "Palette.h"
#include "ImageLoader.h"
#include "BitmapSlicer.h"

namespace Gui
{
    Box::Box(int iw, int ih, Palette *p)
    {
        this->innerWidth=iw;
        this->innerHeight=ih;
        this->palette=p;
        this->height=innerHeight+10;
        this->width=innerWidth+10;
        Bitmap *tmp=ImageLoader::load("res/gui/box.png");
        if(tmp)
        {
            this->parts=BitmapSlicer::slice(tmp,8);
            delete tmp;
        }
        else std::cerr<<"Could not load res/gui/box.png"<<std::endl;

    }

    Bitmap Box::render()
    {
        Bitmap m(width, height);
        parts[0]->copyTo(&m,0,0,3,3);
        parts[1]->scale(innerWidth,8).copyTo(&m,5,0,0,3);
        parts[2]->copyTo(&m,width-5,0,0,3);
        parts[7]->scale(8,innerHeight).copyTo(&m,0,5,3);
        parts[8]->scale(innerWidth,innerHeight).copyTo(&m,5,5);
        parts[3]->scale(8,innerHeight).copyTo(&m,width-5,5,0,0);
        parts[4]->copyTo(&m,0,height-5,3,0);
        parts[5]->scale(innerWidth,8).copyTo(&m,5,height-5);
        parts[6]->copyTo(&m,width-5,height-5);
        return m;
    }

}
