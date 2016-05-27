// Copyright 2016 Lauri Gustafsson
/*  This file is part of lib3dapp.

    lib3dapp is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    lib3dapp is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with lib3dapp.  If not, see <http://www.gnu.org/licenses/>.*/

#include "3dapp_rgba_image.hpp"
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
