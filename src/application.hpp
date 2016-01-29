#pragma once

#include "window.hpp"
#include "resource_handler.hpp"
#include "program.hpp"
#include "mvp.hpp"

class Application {
    public:
        Application(Window& _window);
        void draw();
        bool isRunning();
    private:
        ResourceHandler resources;
        Window& window;
        bool running;
        
        Program* shaderProgram;
        mat4 projection;
        MVP* mvp;
};
