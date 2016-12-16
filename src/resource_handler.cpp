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

#include "3dapp_resource_handler.hpp"
#include "3dapp_obj_file.hpp"
#include "3dapp_tga_file.hpp"
#include "3dapp_mesh.hpp"
#include "3dapp_rgba_image.hpp"
#include <iostream>
#include "3dapp_paths.hpp"

using namespace Lib3dapp;

StaticModel* ResourceHandler::getStaticModel(std::string name) {
    if (staticModels.find(name) == staticModels.end()) {
        Mesh modelMesh = loadOBJFile(meshPath(name));
        staticModels[name] = new StaticModel(modelMesh);
    }
    return staticModels[name];
}

Texture* ResourceHandler::getTexture(std::string name) {
    if (textures.find(name) == textures.end()) {
        RgbaImage image = loadTGAFile(texturePath(name));
        textures[name] = new Texture(image);
    }
    return textures[name];
}

void ResourceHandler::freeStaticModels() {
    for (std::map<std::string, StaticModel*>::iterator it = staticModels.begin(); it != staticModels.end(); ++it) {
        delete it->second;
    }
    staticModels.clear();
}

void ResourceHandler::freeTextures() {
    for (std::map<std::string, Texture*>::iterator it = textures.begin(); it != textures.end(); ++it) {
        delete it->second;
    }
    textures.clear();
}
