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
