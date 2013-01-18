#ifndef PALETTEMANAGER_H
#define PALETTEMANAGER_H

#include <string>
#include <map>

class PaletteManager
{
public:
    static PaletteManager& getInstance();
    static Palette* getPalette(std::string name);
private:
    PaletteManager();
    static PaletteManager *instance;
    std::map<std::string, Palette*> palettes;
};

#endif // PALETTEMANAGER_H
