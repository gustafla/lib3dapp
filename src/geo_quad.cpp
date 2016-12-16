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

#include "3dapp_geo_quad.hpp"

using namespace Lib3dapp;

Mesh Lib3dapp::buildQuadMesh() {
    Mesh mesh;
    mesh.pushPosition(vec3(-1.0, -1.0,  0.0));
    mesh.pushPosition(vec3( 1.0, -1.0,  0.0));
    mesh.pushPosition(vec3( 1.0,  1.0,  0.0));
    mesh.pushPosition(vec3( 1.0,  1.0,  0.0));
    mesh.pushPosition(vec3(-1.0,  1.0,  0.0));
    mesh.pushPosition(vec3(-1.0, -1.0,  0.0));
    
    mesh.pushNormal(vec3(0.0, 0.0, 1.0));
    mesh.pushNormal(vec3(0.0, 0.0, 1.0));
    mesh.pushNormal(vec3(0.0, 0.0, 1.0));
    mesh.pushNormal(vec3(0.0, 0.0, 1.0));
    mesh.pushNormal(vec3(0.0, 0.0, 1.0));
    mesh.pushNormal(vec3(0.0, 0.0, 1.0));
    
    mesh.pushTexcoord(vec2(0.0, 0.0));
    mesh.pushTexcoord(vec2(1.0, 0.0));
    mesh.pushTexcoord(vec2(1.0, 1.0));
    mesh.pushTexcoord(vec2(1.0, 1.0));
    mesh.pushTexcoord(vec2(0.0, 1.0));
    mesh.pushTexcoord(vec2(0.0, 0.0));
    
    return mesh;
}
