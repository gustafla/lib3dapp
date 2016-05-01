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

#include <string>
#include "lighting_state.hpp"
#include "graphics.hpp"

class Shader {
    public:
        Shader(std::string source, GLenum type, std::string _name="unknown shader", LightingState lights=LightingState());
        ~Shader();
        GLuint getHandle();
        std::string getName();
        
        static Shader loadFromFile(std::string filename, LightingState lights=LightingState());
        
    private:
        GLuint handle;
        std::string name;
};
