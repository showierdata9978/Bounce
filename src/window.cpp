
// create a raylib window class

#include <raylib.h>
#include <vector>
#include "box.hpp"
#include "window.hpp"


WindowManager::WindowManager(int width, int height, const char *title, int boxCount)
    : width(width), height(height)
{
    this->boxCount = boxCount;
    this->width = width;
    this->height = height;

    InitWindow(width, height, title);

    SetTargetFPS(60);


    for (int i = 0; i < boxCount; i++)
    {
        this->boxes.push_back(Box(rand() % width, rand() % height) );
    }
}

void WindowManager::update()
{
    // make the window size % BOX_SIZE, if it has changed

    this->width = devflr((float)GetScreenWidth(), BOX_SIZE);
    this->height = devflr((float)GetScreenHeight(), BOX_SIZE);

    for (auto &box : this->boxes)
    {
        box.tick(this);
    }
}

void WindowManager::draw()
{
    BeginDrawing();

    ClearBackground(BLACK);

    DrawRectangle(width, height, 0, 0, Color{0, 0, 0, 254});

    for (auto &box : this->boxes)
    {
        box.draw(this);
    }

    // draw a series of lines in a grid, going across the screen

    for (int i = 0; i < width; i += BOX_SIZE)
    {
        DrawLine(i, 0, i, height, Color{255, 255, 255, 255});
    }

    for (int i = 0; i < height; i += BOX_SIZE)
    {
        DrawLine(0, i, width, i, Color{255, 255, 255, 255});
    };

    EndDrawing();
}

/**
 * @brief Main loop that runs until the window is closed.
 */
void WindowManager::start_loop()
{
    while (!WindowShouldClose())
    {

        update();
        draw();
    }
}

