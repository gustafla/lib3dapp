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

#include "3dapp_paths.hpp"
#include <string>

std::string Lib3dapp::meshPath(std::string filename) {
    std::string tmp = DATA_DIR;
    tmp+="/";
    tmp+=MESH_DIR;
    tmp+="/";
    tmp+=filename;
    return tmp;
}

std::string Lib3dapp::texturePath(std::string filename) {
    std::string tmp = DATA_DIR;
    tmp+="/";
    tmp+=TEXTURE_DIR;
    tmp+="/";
    tmp+=filename;
    return tmp;
}

std::string Lib3dapp::shaderPath(std::string name) {
    std::string tmp = DATA_DIR;
    tmp += "/";
    tmp += SHADER_DIR;
    tmp += "/";
    tmp += name;
    return tmp;
}
