#include "Camera.h"

Camera::Camera(int vw, int vh, int x, int y)
{
    this->vw = vw;
    this->vh = vh;
    this->x = x;
    this->y = y;
}

void Camera::move(int vx, int vy)
{
    this->x = x;
    this->y = y;
}

int Camera::getViewportW() const
{
    return vw;
}

int Camera::getViewportH() const
{
    return vh;
}

int Camera::getX() const
{
    return x;
}

int Camera::getY() const
{
    return y;
}
