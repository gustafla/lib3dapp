#pragma once

#include "window.hpp"

class Game {
    public:
        Game(Window& _gameWin);
        void draw();
        bool isRunning();
    private:
        Window& gameWin;
        bool running;
};
