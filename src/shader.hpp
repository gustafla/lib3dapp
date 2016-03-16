#pragma once

#include <string>
#include "lighting_state.hpp"
#include "graphics.hpp"

class Shader {
    public:
        Shader(std::string filename, LightingState lights=LightingState());
        ~Shader();
        GLuint getHandle();
        std::string getName();
    private:
        GLuint handle;
        std::string name;
};
