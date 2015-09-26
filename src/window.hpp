#pragma once

#include "config.hpp"
#include "graphics.hpp"

class Window {
    public:
        Window(const Config& conf);
        ~Window();
        void close();
        void swapBuffers();
        void bindBuffer();
        float getTime();
        unsigned int getWidth();
        unsigned int getHeight();
        float getAspect();
        void resize(unsigned int w, unsigned int h);
    private:
        SDL_Window* window;
        SDL_GLContext context;
        SDL_Event events;
        unsigned int width;
        unsigned int height;
        float aspect;
};
