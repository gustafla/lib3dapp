#pragma once

#include "window.hpp"
#include "static_object.hpp"
#include "shader.hpp"
#include "mvp.hpp"

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
        GLfloat projection[4*4];
        MVP* mvp;
};
