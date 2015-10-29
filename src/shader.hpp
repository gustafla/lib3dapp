#pragma once

#include <string>
#include "graphics.hpp"

class Shader {
    public:
        Shader(std::string filename);
        ~Shader();
        GLuint getHandle();
        std::string getName();
    private:
        GLuint handle;
        std::string name;
};
