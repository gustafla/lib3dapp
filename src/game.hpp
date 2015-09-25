#pragma once

#include "window.hpp"
#include "static_object.hpp"
#include "shader.hpp"

class Game {
    public:
        Game(Window& _window);
        void draw();
        bool isRunning();
    private:
        Window& window;
        bool running;
        StaticObject* triangle;
        Shader shader;
};
