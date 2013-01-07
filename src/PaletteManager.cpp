#include <map>
#include <string>
#include "Palette.h"
#include "PaletteManager.h"

PaletteManager::PaletteManager()
{
    palettes["grass"] = new Palette({0});
}

PaletteManager& PaletteManager::getInstance()
{
    static PaletteManager instance;
    return instance;
}

Palette* PaletteManager::getPalette(std::string name)
{
    if (getInstance().palettes.find(name) == getInstance().palettes.end()) return NULL;
    return getInstance().palettes.at(name);
}
