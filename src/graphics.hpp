#pragma once

#ifdef RASPI_BUILD
#include <bcm_host.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <GLES2/gl2.h>
#else
#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>
#endif

#include <string>

#define INT2P(i) (static_cast<char*>(0) + (i))
#define check() checkGl(__FILE__, __LINE__)

/* The call with string and int parameters should be optimized out in release as the function will be empty? */
/* Assert? Who needs that thing? :DDDD */

void checkGl(std::string file, int line);
void initializeGraphics();
void cleanupGraphics();
