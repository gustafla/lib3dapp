#pragma once

#include "config.hpp"
#include "vectors.hpp"
#include "graphics.hpp"
#include <string>

class Window {
    public:
        Window(const Config& conf, std::string caption="", vec2 realsize=vec2(0));
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
        #else
            SDL_Window* window;
            SDL_GLContext context;
        #endif
        SDL_Event events;
        unsigned int width;
        unsigned int height;
        float aspect;
};
