#ifndef TILESETMANAGER_H
#define TILESETMANAGER_H

#include <string>
#include <map>
#include <vector>

class Bitmap;

class TileSetManager
{
public:
    TileSetManager();
    void load(std::string filename, std::string name);
    Bitmap* getTileBitmap(int id, std::string tileset);
private:
    std::map<std::string, std::vector<Bitmap*> > tilesets;
};

#endif // TILESETMANAGER_H
