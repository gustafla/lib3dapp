// Copyright 2016 Lauri Gustafsson
/*  This file is part of lib3dapp.

    lib3dapp is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    lib3dapp is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with lib3dapp.  If not, see <http://www.gnu.org/licenses/>.*/

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
