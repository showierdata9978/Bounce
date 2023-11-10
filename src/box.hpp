#ifndef BOX_HPP
#define BOX_HPP

#include <raylib.h>

class WindowManager;

#define BOX_SIZE 50.0f
#define OOB_SIZE 1

template <typename T>
T devflr(T x, T y);

class Box
{
private:
    float x;
    float y;

    int x_dir;
    int y_dir;

    WindowManager *window;

public:

    Box(int x, int y, WindowManager *window);
    Box();

    void tick();
    void draw();
};

#endif // BOX_HPP
