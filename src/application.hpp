#pragma once

#include "window.hpp"
#include "resource_handler.hpp"

class Application {
    public:
        Application(Window& _window);
        virtual void draw();
        virtual bool isRunning();
    protected:
        ResourceHandler resources;
        Window& window;
        bool running;
};
