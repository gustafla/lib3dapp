#ifdef RASPI_BUILD

#include "window.hpp"
#include <iostream>
#include <cstdlib>
#include "define.hpp"
#include <cstring>
#include "define.hpp"
#include <sys/time.h>

Window::Window(const Config& conf, std::string caption, vec2 realsize):
width(conf.w),
height(conf.h),
aspect(((float)conf.w)/((float)conf.h)) {
    std::cout << caption << std::endl;
    
    EGLint attribList[] = {
        EGL_RED_SIZE,       5,
        EGL_GREEN_SIZE,     6,
        EGL_BLUE_SIZE,      5,
        EGL_ALPHA_SIZE,     8,
        EGL_DEPTH_SIZE,     8,
        EGL_STENCIL_SIZE,   8,
        EGL_SAMPLE_BUFFERS, 0,
        EGL_NONE
    };
    
    if (conf.fullscreen && realsize.y > 0.1f) { //The Pi H/W has a picture scaler
        width = aspect*realsize.y; //So let's utilize it instead of a shader pass
        height = realsize.y;
    }

    static EGL_DISPMANX_WINDOW_T nativewindow;

    DISPMANX_ELEMENT_HANDLE_T dispman_element;
    DISPMANX_DISPLAY_HANDLE_T dispman_display;
    DISPMANX_UPDATE_HANDLE_T dispman_update;
    VC_RECT_T dst_rect;
    VC_RECT_T src_rect;

    uint32_t w;
    uint32_t h;
    uint32_t x;
    uint32_t y;

    w = conf.w;
    h = conf.h;
    x = 0;
    y = 0;

    dst_rect.x = x;
    dst_rect.y = y;
    dst_rect.width = w;
    dst_rect.height = h;

    src_rect.x = x;
    src_rect.y = y;
    src_rect.width = width<<16;
    src_rect.height = height<<16;

    dispman_display = vc_dispmanx_display_open(0);
    dispman_update = vc_dispmanx_update_start(0);

    VC_DISPMANX_ALPHA_T alpha = {
        DISPMANX_FLAGS_ALPHA_FIXED_ALL_PIXELS,255,0
    };

    dispman_element = vc_dispmanx_element_add(dispman_update, dispman_display, 0, &dst_rect, 0, &src_rect, DISPMANX_PROTECTION_NONE, &alpha, 0, (DISPMANX_TRANSFORM_T)0);

    nativewindow.element = dispman_element;
    nativewindow.width = width;
    nativewindow.height = height;
    vc_dispmanx_update_submit_sync(dispman_update);
    
    window = &nativewindow;

    EGLint numConfigs;
    EGLint majorVersion;
    EGLint minorVersion;
    EGLDisplay eglDisplay;
    EGLContext eglContext;
    EGLSurface eglBuffer;
    EGLConfig config;

    EGLint contextAttribs[] = {EGL_CONTEXT_CLIENT_VERSION, 2, EGL_NONE};

    eglDisplay = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    if (eglDisplay == EGL_NO_DISPLAY) {
        exit(ERR_WINDOW);
    }

    if (!eglInitialize(eglDisplay, &majorVersion, &minorVersion)) {
        exit(ERR_WINDOW);
    }

    if (!eglChooseConfig(eglDisplay, attribList, &config, 1, &numConfigs)) {
        exit(ERR_WINDOW);
    }

    eglBuffer = eglCreateWindowSurface(eglDisplay, config, (EGLNativeWindowType)window, NULL);
    if (eglBuffer == EGL_NO_SURFACE) {
        exit(ERR_WINDOW);
    }

    eglContext = eglCreateContext(eglDisplay, config, EGL_NO_CONTEXT, contextAttribs);
    if (eglContext == EGL_NO_CONTEXT) {
        exit(ERR_WINDOW);
    }

    if (!eglMakeCurrent(eglDisplay, eglBuffer, eglBuffer, eglContext)) {
        exit(ERR_WINDOW);
    }

    display = eglDisplay;
    buffer = eglBuffer;
    context = eglContext;

    restoreViewport();
    bindFramebuffer();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void Window::close() {
}

Window::~Window() {
    close();
}

void Window::swapBuffers() {
    eglSwapBuffers(display, buffer);
    
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
}

void Window::restoreViewport() {
    glViewport(0, 0, width, height);
}

#endif
