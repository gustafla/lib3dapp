#pragma once

#include "graphics.hpp"

class Buffer {
    public:
        Buffer(GLfloat* data, unsigned int size, GLuint hint=GL_STATIC_DRAW);
        ~Buffer();
        void bind();
    private:
        GLuint handle;
};
