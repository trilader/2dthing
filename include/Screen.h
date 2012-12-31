#ifndef SCREEN_H
#define SCREEN_H

class SDL_Surface;

class Screen
{
public:
    Screen(int w, int h, int scale);
    ~Screen();
    int getW() const;
    int getH() const;
    bool draw(Bitmap *bitmap, int x, int y);
    void update();
private:
    int w, h;
    int scale;
    SDL_Surface *surface;
    Bitmap *bmp;
};

#endif // SCREEN_H
