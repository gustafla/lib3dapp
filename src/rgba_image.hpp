#pragma once

#include <vector>
#include "graphics.hpp"

class RgbaImage {
    public:
        RgbaImage(unsigned int w, unsigned int h, bool c=true, bool a=true);
        GLubyte* getArray();
        unsigned int getSize();
        void pushByte(GLubyte byte);
        bool hasColor();
        bool hasAlpha();
        unsigned int getWidth();
        unsigned int getHeight();
    private:
        unsigned int width;
        unsigned int height;
        bool color;
        bool alpha;
        std::vector<GLubyte> image;
};
