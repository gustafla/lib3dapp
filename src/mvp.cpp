#include "mvp.hpp"

MVP::MVP(mat4& _projection, GLfloat vtx, GLfloat vty, GLfloat vtz, GLfloat vrx, GLfloat vry, GLfloat vrz, GLfloat tx, GLfloat ty, GLfloat tz, GLfloat rx, GLfloat ry, GLfloat rz, GLfloat _scale):
projection(_projection) {
    identity = getScaleMat(1.0f);
    viewTranslation = getTranslationMat(vtx, vty, vtz);
    viewRotation = getXYZRotMat(vrx, vry, vrz);
    view  = viewTranslation*viewRotation;
    
    modelTranslation = getTranslationMat(tx, ty, tz);
    modelRotation = getXYZRotMat(rx, ry, rz);
    modelScale = getScaleMat(_scale);
    
    buildModel();
    buildMVP();
}

void MVP::buildMVP() {
    mvp = projection * view * model;
}

void MVP::buildModel() {
    model = modelTranslation * modelRotation * modelScale;
}

void MVP::buildView() {
    view = viewRotation * viewTranslation;
}

void MVP::setProjection(mat4& _projection) {
    projection = _projection;
}

void MVP::setView(GLfloat vtx, GLfloat vty, GLfloat vtz, GLfloat vrx, GLfloat vry, GLfloat vrz) {
    viewTranslation = getTranslationMat(vtx, vty, vtz);
    viewRotation = getXYZRotMat(vrx, vry, vrz);
    buildView();
}

void MVP::setViewTranslation(GLfloat vtx, GLfloat vty, GLfloat vtz) {
    viewTranslation = getTranslationMat(vtx, vty, vtz);
    view = viewRotation * viewTranslation;
}

void MVP::setViewRotation(GLfloat vrx, GLfloat vry, GLfloat vrz) {
    viewRotation = getXYZRotMat(vrx, vry, vrz);
    view = viewRotation * viewTranslation;
}

void MVP::setModel(GLfloat tx, GLfloat ty, GLfloat tz, GLfloat rx, GLfloat ry, GLfloat rz, GLfloat _scale) {
    modelTranslation = getTranslationMat(tx, ty, tz);
    modelRotation = getXYZRotMat(rx, ry, rz);
    modelScale = getScaleMat(_scale);
    model = modelTranslation * modelRotation * modelScale;
}

void MVP::setModelTranslation(GLfloat tx, GLfloat ty, GLfloat tz) {
    modelTranslation = getTranslationMat(tx, ty, tz);
}

void MVP::setModelRotation(GLfloat rx, GLfloat ry, GLfloat rz) {
    modelRotation = getXYZRotMat(rx, ry, rz);
}
void MVP::setModelScale(GLfloat _scale) {
    modelScale = getScaleMat(_scale);
}

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
