#pragma once

void multMat4(float* result, float* a, float* b);
void getPProjMat(float* mat, float fov, float aspect, float znear=1.0, float zfar=10.0);
void getXRotMat(float* mat, float a);
void getYRotMat(float* mat, float a);
void getZRotMat(float* mat, float a);
void getXYZRotMat(float* mat, float x, float y, float z);
void getTranslationMat(float* mat, float x, float y, float z);
void getScaleMat(float* mat, float x, float y, float z);
void getScaleMat(float* mat, float x);
