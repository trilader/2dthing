#include "BitmapSlicer.h"
#include "Bitmap.h"

BitmapSlicer::BitmapSlicer()
{

}

std::vector<Bitmap*> BitmapSlicer::slice(Bitmap *input, int size)
{
    int tx=input->getW()/size;
    int ty=input->getH()/size;
    std::vector<Bitmap*> res;

    for(int sy=0;sy<ty;sy++)
    {
        for(int sx=0;sx<tx;sx++)
        {
            Bitmap *b=new Bitmap(size, size);
            for(int py=0;py<size;py++)
                for(int px=0;px<size;px++)
                    b->setPixel(px,py,input->getPixel(sx*size+px,sy*size+py));
            res.push_back(b);
        }
    }
    return res;
}

