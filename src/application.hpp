#pragma once

#include "window.hpp"
#include "resource_handler.hpp"
#include "program.hpp"
#include "mvp.hpp"
#include "framebuffer.hpp"

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
        Program* ppProgram;
        mat4 projection;
        MVP* mvp;
        StaticModel* quad;
        Framebuffer ppBuf;
};
