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
#include "3dapp_vectors.hpp"
#include "3dapp_matrices.hpp"

namespace Lib3dapp {
    class Mesh {
        public:
        Mesh();
        void pushPosition(vec3 position);
        void pushNormal(vec3 normal);
        void pushTexcoord(vec2 texcoord);
        void transform(mat4 matrix);
        void join(Mesh& mesh);
        const std::vector<vec3>& getPositions();
        const std::vector<vec3>& getNormals();
        const std::vector<vec2>& getTexcoords();
        const bool getAOSArray(std::vector<float>& array);
        void getSOAArray(std::vector<float>& posArray, std::vector<float>& nmlArray, std::vector<float>& texArray);
        
        private:
        std::vector<vec3> positions;
        std::vector<vec3> normals;
        std::vector<vec2> texcoords;
    };
};

using namespace Lib3dapp;
