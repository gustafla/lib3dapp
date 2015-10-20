#pragma once

#include "graphics.hpp"
#include "rgba_image.hpp"

class Texture {
    public:
        Texture(RgbaImage& image);
        ~Texture();
        void bindToUnit(GLuint unit);
    private:
        GLuint handle;
};
