#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "ImageLoader.h"
#include "Bitmap.h"

ImageLoader::ImageLoader()
{

}

Bitmap* ImageLoader::load(std::string filename)
{
    IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG);
    SDL_Surface *tmp=IMG_Load(filename.c_str());
    IMG_Quit();
    if(!tmp) exit(1);
    return new Bitmap(tmp);
}
