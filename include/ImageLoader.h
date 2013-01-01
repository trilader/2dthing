#ifndef IMAGE_LOADER_H
#define IMAGE_LOADER_H
#include <iostream>

class Bitmap;

class ImageLoader
{
public:
    static Bitmap* load(std::string filename);
private:
    ImageLoader();
};

#endif // IMAGE_LOADER_H
