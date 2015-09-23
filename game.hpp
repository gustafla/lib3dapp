#pragma once

#include "window.hpp"

class Game {
    public:
        Game(Window& _window);
        void draw();
        bool isRunning();
    private:
        Window& window;
        bool running;
};
