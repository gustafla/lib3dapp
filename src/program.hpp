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

#include <map>
#include <string>
#include "shader.hpp"
#include "graphics.hpp"

std::string shaderPath(std::string name);

class Program {
    public:
        Program();
        Program(Shader vertexShader, Shader fragmentShader);
        ~Program();
        GLuint getHandle();
        GLuint getUfmHandle(std::string);
        GLuint getAtrHandle(std::string);
        void use();
    
    private:
        std::map<std::string, GLuint> uniforms;
        std::map<std::string, GLuint> attributes;
        //std::string vname;
        //std::string fname;
        //GLuint compShader(GLenum type, const char* src);
    
        GLuint handle;
};
