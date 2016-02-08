#ifndef RASPI_BUILD

#include "window.hpp"
#include <iostream>
#include <cstdlib>
#include "define.hpp"
#include <cstring>

Window::Window(const Config& conf, std::string caption, vec2 realsize):
width(conf.w),
height(conf.h),
aspect(((float)conf.w)/((float)conf.h)) {
    int err;

    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    window = SDL_CreateWindow(caption.c_str(), SDL_WINDOWPOS_CENTERED_DISPLAY(conf.display), SDL_WINDOWPOS_CENTERED_DISPLAY(conf.display), conf.w, conf.h, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | (conf.fullscreen ? SDL_WINDOW_FULLSCREEN : 0));
    if (!window) {
        std::cout << "Couldn't get SDL OpenGL window.\n";
        std::cout << "SDL Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(ERR_WINDOW);
    }

    context = SDL_GL_CreateContext(window);

    GLenum rev;
    glewExperimental = GL_TRUE;
    rev = glewInit();

    if (rev != GLEW_OK) {
        std::cout << "Glew error: " << glewGetErrorString(rev) << std::endl;
        exit(ERR_WINDOW);
    }

    SDL_GL_SetSwapInterval(1);
    
    SDL_ShowCursor(0);
    
    restoreViewport();
    bindFramebuffer();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void Window::close() {
    SDL_DestroyWindow(window);
}

Window::~Window() {
    close();
}

void Window::swapBuffers() {
    SDL_GL_SwapWindow(window);

    SDL_PollEvent(&events);

    if (events.type == SDL_QUIT)
        exit(ERR_SUCCESS);
    else if (events.type == SDL_KEYDOWN)
        if (events.key.keysym.sym == SDLK_ESCAPE)
            exit(ERR_SUCCESS);
}

float Window::getTime() {
    return (1.0f*SDL_GetTicks())/1000.0f;
}

void Window::bindFramebuffer() {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    restoreViewport();
}

unsigned int Window::getWidth() {
    return width;
}

unsigned int Window::getHeight() {
    return height;
}

float Window::getAspect() {
    return aspect;
}

void Window::resize(unsigned int w, unsigned int h) {
    width=w;
    height=h;
    aspect=((float)w)/((float)h);
    SDL_SetWindowSize(window, w, h);
    glViewport(0, 0, w, h);
}

void Window::restoreViewport() {
    glViewport(0, 0, width, height);
}

#endif
