#ifndef CAMERA_H
#define CAMERA_H


class Camera
{
public:
    Camera(int vw, int vh, int x = 0, int y = 0);
    void move(int x, int y);
    int getViewportW() const;
    int getViewportH() const;
    int getX() const;
    int getY() const;
private:
    int x, y;
    int vw, vh;
};

#endif // CAMERA_H
