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
        this->height=innerHeight+8;
        this->width=innerWidth+8;

        Bitmap *tmp=ImageLoader::load("res/gui/box.png");
        if(tmp)
        {
            this->parts=BitmapSlicer::slice(tmp,8);
            delete tmp;
        }
        else std::cerr<<"Could not load res/gui/box.png"<<std::endl;
        for(auto it=parts.begin();it!=parts.end();it++)
            (*it)->applyPalette(palette);

    }

    Bitmap Box::render()
    {

        Bitmap m(width, height);
        parts[0]->copyTo(&m,0,0,4,4);
        parts[1]->scale(innerWidth,8).copyTo(&m,4,0,0,4);
        parts[0]->flipH().copyTo(&m,width-4,0,0,4,4);
        parts[2]->flipH().scale(8,innerHeight).copyTo(&m,0,4,4);
        parts[3]->scale(innerWidth,innerHeight).copyTo(&m,4,4);
        parts[2]->scale(8,innerHeight).copyTo(&m,width-4,4,0,0);
        parts[0]->flipV().copyTo(&m,0,height-4,4,0,4);
        parts[1]->flipV().scale(innerWidth,8).copyTo(&m,4,height-4);
        parts[0]->flipV().flipH().copyTo(&m,width-4,height-4);
        return m;
    }

}
