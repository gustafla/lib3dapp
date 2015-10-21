#pragma once

#include <string>
#include "graphics.hpp"

class Shader {
    public:
        Shader(std::string filename);
        ~Shader();
        GLuint getHandle();
    private:
        GLuint handle;
}
