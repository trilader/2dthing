#include "Tile.h"
#include "ImageLoader.h"
#include "Bitmap.h"
#include "BitmapSlicer.h"
#include "TileSetManager.h"

TileSetManager::TileSetManager()
{
    //ctor
}

void TileSetManager::load(std::string filename, std::string name)
{
    Bitmap* tmp = ImageLoader::load(filename);
    tilesets[name] = BitmapSlicer::slice(tmp, TILE_SIZE);
    delete tmp;
}

Bitmap* TileSetManager::getTileBitmap(int id, std::string tileset)
{
    return tilesets[tileset][id];
}
