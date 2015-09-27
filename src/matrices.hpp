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

void multMat4(float* result, float* a, float* b);
void getPProjMat(float* mat, float fov, float aspect, float znear=1.0, float zfar=10.0);
mat4 getPProjMat(float fov, float aspect, float znear=1.0, float zfar=10.0);
void getXRotMat(float* mat, float a);
void getYRotMat(float* mat, float a);
void getZRotMat(float* mat, float a);
void getXYZRotMat(float* mat, float x, float y, float z);
void getTranslationMat(float* mat, float x, float y, float z);
void getScaleMat(float* mat, float x, float y, float z);
void getScaleMat(float* mat, float x);
