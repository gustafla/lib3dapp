#pragma once

#include "graphics.hpp"

class Renderbuffer {
    public:
        Renderbuffer(GLuint w, GLuint h);
        ~Renderbuffer();
        
        GLuint getHandle();
        void bind();
        
    private:
        GLuint handle;
};
