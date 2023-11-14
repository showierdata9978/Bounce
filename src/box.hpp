#ifndef BOX_HPP
#define BOX_HPP

#include <raylib.h>

class WindowManager;



static constexpr float BOX_SIZE = 50.0f;


template <typename T>
T devflr(T x, T y);

class Box
{
private:
    float x;
    float y;

    int x_dir;
    int y_dir;

public:

    Box(int x, int y);
    Box() = delete;

    void tick(WindowManager *window);
    void draw(WindowManager *window);
};

#endif // BOX_HPP
