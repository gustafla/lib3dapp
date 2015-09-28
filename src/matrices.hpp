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
};

mat4 getPProjMat(float fov, float aspect, float znear=1.0, float zfar=10.0);
mat4 getXRotMat(float a);
mat4 getYRotMat(float a);
mat4 getZRotMat(float a);
mat4 getXYZRotMat(float x, float y, float z);
mat4 getTranslationMat(float x, float y, float z);
mat4 getScaleMat(float x, float y, float z);
mat4 getScaleMat(float x);
