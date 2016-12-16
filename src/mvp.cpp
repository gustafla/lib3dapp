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

#include "3dapp_mvp.hpp"
#include "3dapp_consts.hpp"

using namespace Lib3dapp;

MVP::MVP(mat4 _projection, GLfloat vtx, GLfloat vty, GLfloat vtz, GLfloat vrx, GLfloat vry, GLfloat vrz, GLfloat tx, GLfloat ty, GLfloat tz, GLfloat rx, GLfloat ry, GLfloat rz, GLfloat _scale):
projection(_projection),
modelModified(true),
viewModified(true),
projectionModified(true) {
    identity = getScaleMat(1.0f);
    viewTranslation = getTranslationMat(vtx, vty, vtz);
    viewRotation = getXYZRotMat(vrx, vry, vrz);
    view  = viewTranslation*viewRotation;
    
    modelTranslation = getTranslationMat(tx, ty, tz);
    modelRotation = getXYZRotMat(rx, ry, rz);
    modelScale = getScaleMat(_scale);
}

/*void MVP::buildMVP() {
    if (viewModified) {
        buildView();
    }
    
    if (modelModified) {
        buildModel();
    }
    
    mv = view * model;
    //mvp = projection * mv;
    
    modelModified = false;
    viewModified = false;
}*/

void MVP::buildModel() {
    model = modelTranslation * modelRotation * modelScale;
}

void MVP::buildView() {
    view = viewRotation * viewTranslation;
}

void MVP::setProjection(mat4& _projection) {
    projection = _projection;
    projectionModified = true;
}

void MVP::setView(GLfloat vtx, GLfloat vty, GLfloat vtz, GLfloat vrx, GLfloat vry, GLfloat vrz) {
    viewTranslation = getTranslationMat(vtx, vty, vtz);
    viewRotation = getXYZRotMat(vrx, vry, vrz);
    viewModified = true;
}

void MVP::setViewTranslation(GLfloat vtx, GLfloat vty, GLfloat vtz) {
    viewTranslation = getTranslationMat(vtx, vty, vtz);
    viewModified = true;
}

void MVP::setViewRotation(GLfloat vrx, GLfloat vry, GLfloat vrz) {
    viewRotation = getXYZRotMat(vrx, vry, vrz);
    viewModified = true;
}

void MVP::setModel(GLfloat tx, GLfloat ty, GLfloat tz, GLfloat rx, GLfloat ry, GLfloat rz, GLfloat _scale) {
    modelTranslation = getTranslationMat(tx, ty, tz);
    modelRotation = getXYZRotMat(rx, ry, rz);
    modelScale = getScaleMat(_scale);
    modelModified = true;
}

void MVP::setModelTranslation(GLfloat tx, GLfloat ty, GLfloat tz) {
    modelTranslation = getTranslationMat(tx, ty, tz);
    modelModified = true;
}

void MVP::setModelRotation(GLfloat rx, GLfloat ry, GLfloat rz) {
    modelRotation = getXYZRotMat(rx, ry, rz);
    modelModified = true;
}
void MVP::setModelScale(GLfloat _scale) {
    modelScale = getScaleMat(_scale);
    modelModified = true;
}

/*
const mat4& MVP::getView() {
    return view;
}

const mat4& MVP::getModel() {
    return model;
}

const mat4& MVP::getMVP() {
    return mvp;
}

const float* MVP::getMVPArray() {
    return (const float*)&mvp;
}

const float* MVP::getModelRotationArray() {
    return (const float*)&modelRotation;
}*/

void MVP::apply(Program& shader) {
    //buildMVP();
    shader.use();
    
    glUniformMatrix4fv(shader.getUfmHandle(NAME_U_MAT_PROJECTION), 1, GL_FALSE, (GLfloat*)&projection);
    
    if (modelModified) {
        buildModel();
    }
    glUniformMatrix4fv(shader.getUfmHandle(NAME_U_MAT_MODEL), 1, GL_FALSE, (GLfloat*)&model);
    
    if (viewModified) {
        buildView();
    }
    glUniformMatrix4fv(shader.getUfmHandle(NAME_U_MAT_VIEW), 1, GL_FALSE, (GLfloat*)&view);
    
    projectionModified = false;
    viewModified = false;
    modelModified = false;
}

void MVP::reset() {
    setView();
    setModel();
}
