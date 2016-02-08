#include "graphics.hpp"
#include <cstdlib>
#include <iostream>
#include "define.hpp"

void checkGl(std::string file, int line) {
    #ifdef DEBUG_BUILD
        GLenum glErr = glGetError();
        if (glErr) {
            std::cout << "glGetError returned ";
            switch(glErr) {
                case GL_INVALID_ENUM:
                std::cout << "GL_INVALID_ENUM";
                break;
                
                case GL_INVALID_VALUE:
                std::cout << "GL_INVALID_VALUE";
                break;
                
                case GL_INVALID_OPERATION:
                std::cout << "GL_INVALID_OPERATION";
                break;
                
                case GL_INVALID_FRAMEBUFFER_OPERATION:
                std::cout << "GL_INVALID_FRAMEBUFFER_OPERATION";
                break;
                
                case GL_OUT_OF_MEMORY:
                std::cout << "GL_OUT_OF_MEMORY";
                break;
            }
            std::cout << " on line " << line << " of " << file << ".\n";
            exit(glErr);
        }
    #endif
}

void cleanupGraphics() {
    #ifdef RASPI_BUILD
        bcm_host_deinit();
    #endif
    SDL_Quit();
}

void initializeGraphics() {
    #ifdef RASPI_BUILD
        bcm_host_init();
        if ((SDL_Init(SDL_INIT_TIMER|SDL_INIT_AUDIO|SDL_INIT_VIDEO)) != 0) {
            std::cout << "SDL failed to initialize.\n";
            exit(ERR_WTF);
        }
        SDL_SetVideoMode(0,0,0,SDL_SWSURFACE); //Null video surface to receive keyboard input
        SDL_ShowCursor(0);
    #else
        if ((SDL_Init(SDL_INIT_EVERYTHING)) != 0) {
            std::cout << "SDL failed to initialize.\n";
            exit(ERR_WTF);
        }
    #endif
}
