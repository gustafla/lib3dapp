#pragma once

#include "window.hpp"
#include "resource_handler.hpp"
#include "shader.hpp"
#include "mvp.hpp"

class Game {
    public:
        Game(Window& _window);
        void draw();
        bool isRunning();
    private:
        ResourceHandler resources;
        Window& window;
        bool running;
        
        Shader shader;
        mat4 projection;
        MVP* mvp;
};
