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

#include "vectors.hpp"

struct mat4 {
    //Columns, because OpenGL.
    vec4 a;
    vec4 b;
    vec4 c;
    vec4 d;
    mat4();
    mat4(vec4 _a, vec4 _b, vec4 _c, vec4 _d);
    mat4(const mat4& r);
    mat4& operator=(mat4 r);
    mat4& operator*=(mat4 r);
    mat4 operator*(const mat4& b);
    vec4 operator*(const vec4& b);
};

mat4 getPProjMat(float fov, float aspect, float znear=1.0, float zfar=10.0);
mat4 getOProjMat(float right, float top, float left=0.0f, float bottom=0.0f, float near=-1.0f, float far=1.0f);
mat4 getXRotMat(float a);
mat4 getYRotMat(float a);
mat4 getZRotMat(float a);
mat4 getXYZRotMat(float x, float y, float z);
mat4 getTranslationMat(float x, float y, float z);
mat4 getScaleMat(float x, float y, float z);
mat4 getScaleMat(float x);
