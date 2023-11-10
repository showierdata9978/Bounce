#include <raylib.h>
#include <cmath>
#include "box.hpp"

#include "window.hpp"

template <typename T>
T devflr(T x, T y)
{
    return std::floor(x / y) * y;
}


Box::Box(int x, int y, WindowManager *window)
    : x(x), y(y)
{
    this->x = devflr(x, 10);
    this->y = devflr(y, 10);

    this->x_dir = 1;
    this->y_dir = 1;

    this->window = window;
};

Box::Box()
{
    this->x = 0;
    this->y = 0;

    this->x_dir = 1;
    this->y_dir = 1;
}

void Box::tick()
{
    // move the box


    if (x <= BOX_SIZE || x >= window->width + BOX_SIZE)
    {
        x_dir = -x_dir; // reverse the direction when hitting the boundaries
    }

    if (y <= BOX_SIZE || y >= window->height)
    {
        y_dir = -y_dir; // reverse the direction when hitting the boundaries
    }

    float frameTime = GetFrameTime();
    float speed = 10.0f;
    // slowly move the box
    x += ((x_dir * BOX_SIZE) * speed * frameTime);
    y += ((y_dir * BOX_SIZE) * speed * frameTime);
}

void Box::draw()
{

    // calculate the size based on the box's position
    float size = (BOX_SIZE - 1) + abs(x_dir) + abs(y_dir);

    // draw the box with changing size
    DrawRectangleRec(Rectangle{devflr(x, BOX_SIZE), devflr(y, BOX_SIZE), size, size}, Color{255, 0, 0, 255});
}