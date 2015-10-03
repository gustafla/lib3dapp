#include "primitives.hpp"
#include "vectors.hpp"

Primitives::Primitives():
quadMesh(buildQuadMesh()),
quad(quadMesh) {
    
}

/*Mesh buildCubeMesh() {
    Mesh mesh;
    //TODO
    return mesh;
}*/

Mesh Primitives::buildQuadMesh() {
    Mesh mesh;
    mesh.pushPosition(vec4(-1.0, -1.0,  0.0,  1.0));
    mesh.pushPosition(vec4( 1.0, -1.0,  0.0,  1.0));
    mesh.pushPosition(vec4( 1.0,  1.0,  0.0,  1.0));
    mesh.pushPosition(vec4( 1.0,  1.0,  0.0,  1.0));
    mesh.pushPosition(vec4(-1.0,  1.0,  0.0,  1.0));
    mesh.pushPosition(vec4(-1.0, -1.0,  0.0,  1.0));
    
    mesh.pushNormal(vec4(0.0, 0.0, 1.0, 0.0));
    mesh.pushNormal(vec4(0.0, 0.0, 1.0, 0.0));
    mesh.pushNormal(vec4(0.0, 0.0, 1.0, 0.0));
    mesh.pushNormal(vec4(0.0, 0.0, 1.0, 0.0));
    mesh.pushNormal(vec4(0.0, 0.0, 1.0, 0.0));
    mesh.pushNormal(vec4(0.0, 0.0, 1.0, 0.0));
    
    mesh.pushTexcoord(vec2(0.0, 0.0));
    mesh.pushTexcoord(vec2(1.0, 0.0));
    mesh.pushTexcoord(vec2(1.0, 1.0));
    mesh.pushTexcoord(vec2(1.0, 1.0));
    mesh.pushTexcoord(vec2(0.0, 1.0));
    mesh.pushTexcoord(vec2(0.0, 0.0));
    
    return mesh;
}
