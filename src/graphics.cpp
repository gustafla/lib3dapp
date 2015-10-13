#include "graphics.hpp"
#include <cstdlib>
#include <iostream>

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
