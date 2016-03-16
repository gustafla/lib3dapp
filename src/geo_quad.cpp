#include "geo_quad.hpp"

Mesh buildQuadMesh() {
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
