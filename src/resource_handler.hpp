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
#include <string>
#include <map>
#include "mesh.hpp"
#include "program.hpp"
#include "static_model.hpp"
#include "texture.hpp"
#include "graphics.hpp"

/* STD::MAP MIGHT BE SLOW, CONSIDER REPLACING */

class ResourceHandler {
    public:
        StaticModel* getStaticModel(std::string name);
        Texture* getTexture(std::string name);
        void freeStaticModels();
        void freeTextures();
        
    private:
        std::map<std::string, StaticModel*> staticModels;
        std::map<std::string, Texture*> textures;
};
