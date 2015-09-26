#pragma once

#include "config.hpp"
#include "graphics.hpp"

class Window {
    public:
        Window(const Config conf);
        ~Window();
        void close();
        void swapBuffers();
        void bindBuffer();
        float getTime();
    private:
        SDL_Window* window;
        SDL_GLContext context;
        SDL_Event events;
};
