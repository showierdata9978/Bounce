#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <raylib.h>
#include <cmath>
#include <vector>
#include "box.hpp"

class WindowManager {
    public:
        size_t width;
        size_t height;
        int boxCount;

        std::vector<Box> boxes;

        WindowManager(int width, int height, const char* title, int boxCount);
        void start_loop();
        void draw();
        void update();
};

#endif // WINDOW_HPP
