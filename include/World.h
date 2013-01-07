#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "Tile.h"
#include "TileSetManager.h"

class World
{
public:
    World(int w, int h, Screen* screen, Camera* camera);
    ~World();
    TileSetManager *getTileSetManager() const;
    void render();
private:
    int w, h;
    Screen* screen;
    Camera* camera;
    TileSetManager* tileSetManager;
    std::vector<std::vector<Tile*>* > tiles;
};

#endif // WORLD_H
