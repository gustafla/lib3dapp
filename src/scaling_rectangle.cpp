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

#include "3dapp_scaling_rectangle.hpp"
#include "3dapp_matrices.hpp"
#include "3dapp_gfx_utils.hpp"

using namespace Lib3dapp;

ScalingRectangle::ScalingRectangle(vec2 src, vec2 tgt, float scale, vec2 offset):
vbo(NULL),
source(src),
target(tgt) {
    vertices[0] = vec4(-1.0, -1.0,  -1.0,  1.0);
    vertices[1] = vec4( 1.0, -1.0,  -1.0,  1.0);
    vertices[2] = vec4( 1.0,  1.0,  -1.0,  1.0);
    vertices[3] = vec4( 1.0,  1.0,  -1.0,  1.0);
    vertices[4] = vec4(-1.0,  1.0,  -1.0,  1.0);
    vertices[5] = vec4(-1.0, -1.0,  -1.0,  1.0);
    resize(src, tgt, scale, offset);
}

ScalingRectangle::~ScalingRectangle() {
    if (vbo)
        delete vbo;
}

void ScalingRectangle::draw(Program& shader) {
    vbo->draw(shader);
}

void ScalingRectangle::resize(vec2 src, vec2 tgt, float scale, vec2 offset) {
    source = src;
    target = tgt;
    if (vbo)
        delete vbo;
    Mesh mesh;
    
    float aspectRatio = (tgt.x/tgt.y) / (src.x/src.y);
    mat4 tfm = getOProjMat(max(aspectRatio, 1.0f), max(1.0/aspectRatio, 1.0f), -max(aspectRatio, 1.0f), -max(1.0/aspectRatio, 1.0f));
    
    for (unsigned int i=0; i<6; i++) {
        vec4 aspectCorrectedVertex = tfm * vertices[i];
        aspectCorrectedVertex.x = aspectCorrectedVertex.x*scale + offset.x;
        aspectCorrectedVertex.y = aspectCorrectedVertex.y*scale + offset.y;
        mesh.pushPosition(vec3(aspectCorrectedVertex.x, aspectCorrectedVertex.y, aspectCorrectedVertex.z));
    }
    
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
    
    vbo = new StaticModel(mesh);
}

void ScalingRectangle::move(vec2 offset, float scale) {
    resize(source, target, scale, offset);
}
