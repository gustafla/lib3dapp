#include "rgba_image.hpp"

RgbaImage::RgbaImage(unsigned int w, unsigned int h, bool c, bool a):
color(c),
alpha(a),
width(w),
height(h) {
    
}

GLubyte* RgbaImage::getArray() {
    return &image[0];
}

unsigned int RgbaImage::getSize() {
    return image.size();
}

void RgbaImage::pushByte(GLubyte byte) {
    image.push_back(byte);
}

bool RgbaImage::hasColor() {
    return color;
}

bool RgbaImage::hasAlpha() {
    return alpha;
}

unsigned int RgbaImage::getWidth() {
    return width;
}

unsigned int RgbaImage::getHeight() {
    return height;
}
