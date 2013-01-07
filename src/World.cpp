#include <cmath>
#include <vector>
#include "Bitmap.h"
#include "Screen.h"
#include "Tile.h"
#include "StaticTile.h"
#include "Camera.h"
#include "World.h"
#include "Palette.h"
#include <map>

World::World(int w, int h, Screen* screen, Camera* camera)
{
    this->w = w;
    this->h = h;
    this->screen = screen;
    this->camera = camera;
}

World::~World()
{
}

TileSetManager *World::getTileSetManager() const
{
    return tileSetManager;
}

void World::render()
{
    if (tiles.empty()) return;
    unsigned int idxFromX = floor(camera->getX() / float(TILE_SIZE));
    unsigned int idxToX = ceil((camera->getX() + camera->getViewportW()) / float(TILE_SIZE)) - 1;
    unsigned int idxFromY = floor(camera->getY() / float(TILE_SIZE));
    unsigned int idxToY = ceil((camera->getY() + camera->getViewportH()) / float(TILE_SIZE)) - 1;
    if (idxFromX>(tiles.size()-1)||idxToX>(tiles.size()-1)) return;
    int offX = camera->getX() % TILE_SIZE;
    int offY = camera->getY() % TILE_SIZE;
    for (unsigned int x = idxFromX; x <= idxToX; x++)
    {
        if (!tiles[x]) return;
        for (unsigned int y = idxFromY; y <= idxToY; y++)
        {
            screen->draw((*tiles[x])[y]->getBitmap(), -offX + x * TILE_SIZE, -offY + y * TILE_SIZE);
        }
    }
    screen->update();
}
