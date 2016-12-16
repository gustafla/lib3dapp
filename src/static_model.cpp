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

#include "3dapp_static_model.hpp"
#include "3dapp_graphics.hpp"
#include <vector>
#include <cstdlib>
#include <iostream>
#include "3dapp_consts.hpp"

using namespace Lib3dapp;

StaticModel::StaticModel(Mesh mesh):
normals(false),
texcoords(false),
data(NULL),
stride(SIZE_POS),
verts(mesh.getPositions().size()) {
    if (mesh.getNormals().size() > 0) {
        normals = true;
        stride += SIZE_NORMAL;
    }
    if (mesh.getTexcoords().size() > 0) {
        texcoords = true;
        stride += SIZE_TEXCOORD;
    }
    std::vector<GLfloat> array;
    if (!mesh.getAOSArray(array)) {
        std::cout << "StaticModel " << this << " tried to load an incomplete Mesh: " << &mesh << ".\n";
        std::cout << "Mesh vertices:  " << mesh.getPositions().size() << "\n";
        std::cout << "Mesh texcoords: " << mesh.getTexcoords().size() << "\n";
        std::cout << "Mesh normals:   " << mesh.getNormals().size() << "\n";
        exit(ERR_STATIC_OBJECT);
    }
    data = new Buffer(&array[0], array.size()*sizeof(GLfloat), GL_STATIC_DRAW);
    check();
}

StaticModel::~StaticModel() {
    delete data;
}

void StaticModel::draw(Program& shader, GLuint mode) {
    shader.use();
    check();
    
    GLint atrPs = shader.getAtrHandle(NAME_A_POSITION);
    GLint atrNm = shader.getAtrHandle(NAME_A_NORMAL);
    GLint atrTc = shader.getAtrHandle(NAME_A_TEXCOORD);
    
    GLuint offset=0;
    
    data->bind();
    check();
    
    if (atrPs != -1) {
        glEnableVertexAttribArray(atrPs);
        glVertexAttribPointer(atrPs, SIZE_POS, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*stride, INT2P(offset));
        check();
        offset += SIZE_POS * sizeof(GLfloat);
    }
    if (atrTc != -1) {
        if (texcoords) {
            glEnableVertexAttribArray(atrTc);
            glVertexAttribPointer(atrTc, SIZE_TEXCOORD, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*stride, INT2P(offset));
            check();
            offset += SIZE_TEXCOORD * sizeof(GLfloat);
        } else {
            glDisableVertexAttribArray(atrTc);
        }
    }
    if (atrNm != -1) {
        if (normals) {
            glEnableVertexAttribArray(shader.getAtrHandle(NAME_A_NORMAL));
            glVertexAttribPointer(shader.getAtrHandle(NAME_A_NORMAL), SIZE_NORMAL, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*stride, INT2P(offset));
            check();
            offset += SIZE_NORMAL * sizeof(GLfloat);
        } else {
            glDisableVertexAttribArray(atrNm);
        }
    }
    
    glDrawArrays(mode, 0, verts);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    check();
}
