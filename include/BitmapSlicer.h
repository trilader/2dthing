#ifndef BITMAP_SLICER_H
#define BITMAP_SLICER_H
#include <vector>

class Bitmap;

class BitmapSlicer
{
public:
    static std::vector<Bitmap*> slice(Bitmap *input, int size);
private:
    BitmapSlicer();
};

#endif // BITMAP_SLICER_H
