#include "scaling_rectangle.hpp"
#include "matrices.hpp"
#include "gfx_utils.hpp"

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
