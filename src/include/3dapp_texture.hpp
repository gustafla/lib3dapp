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

#include "3dapp_graphics.hpp"
#include "3dapp_rgba_image.hpp"

namespace Lib3dapp {
    class Texture {
        public:
            Texture(RgbaImage image);
            Texture(GLuint w, GLuint h);
            ~Texture();
            
            GLuint getHandle();
            void bindToUnit(GLuint unit);
            
            GLuint getWidth();
            GLuint getHeight();
            float getAspect();
            
            void setFilter(GLuint _filter=GL_LINEAR);
            
        private:
            GLuint handle;
            GLuint width;
            GLuint height;
            GLuint filter;
    };
};

using namespace Lib3dapp;
