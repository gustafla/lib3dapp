#pragma once

#include <vector>
#include "graphics.hpp"

class RgbaImage {
    public:
        RgbaImage(unsigned int w, unsigned int h, unsigned int s, bool c=true, bool a=true);
        ~RgbaImage();
        GLubyte* getArray();
        unsigned int getSize();
        bool hasColor();
        bool hasAlpha();
        unsigned int getWidth();
        unsigned int getHeight();
    private:
        unsigned int width;
        unsigned int height;
        bool color;
        bool alpha;
        
        GLubyte* image;
        unsigned int size;
};
