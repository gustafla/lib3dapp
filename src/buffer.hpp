#pragma once

#include "graphics.hpp"

class Buffer {
    public:
        Buffer(GLfloat* data, GLuint size, GLuint hint=GL_STATIC_DRAW);
        Buffer();
        ~Buffer();
        void bind();
    private:
        GLuint handle;
};
