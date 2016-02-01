#pragma once

#include "config.hpp"
#include "graphics.hpp"
#include <string>

class Window {
    public:
        Window(const Config& conf, std::string caption="");
        ~Window();
        void close();
        void swapBuffers();
        void bindFramebuffer();
        float getTime();
        unsigned int getWidth();
        unsigned int getHeight();
        float getAspect();
        void resize(unsigned int w, unsigned int h);
        void restoreViewport();
    private:
        #ifdef RASPI_BUILD
            EGLNativeWindowType window;
            EGLDisplay display;
            EGLContext context;
            EGLSurface buffer;
            struct timeval tTmp;
            struct timeval startT;
            float t;
        #else
            SDL_Window* window;
            SDL_GLContext context;
            SDL_Event events;
        #endif
        unsigned int width;
        unsigned int height;
        float aspect;
};
