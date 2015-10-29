#pragma once

#include "window.hpp"
#include "resource_handler.hpp"
#include "program.hpp"
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
        
        Program shader;
        Shader vertexShader;
        Shader fragmentShader;
        mat4 projection;
        MVP* mvp;
};
