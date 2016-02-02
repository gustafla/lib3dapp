#include "rgba_image.hpp"
#include <iostream>

RgbaImage::RgbaImage(unsigned int w, unsigned int h, unsigned int s, bool c, bool a):
color(c),
alpha(a),
width(w),
height(h),
size(s) {
     image = new GLubyte[s];
}

RgbaImage::~RgbaImage() {
    std::cout << "RgbaImage destroyed.\n";
    delete[] image;
}

GLubyte* RgbaImage::getArray() {
    return image;
}

unsigned int RgbaImage::getSize() {
    return size;
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
