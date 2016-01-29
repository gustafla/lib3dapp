#include "geo_triangle_equilateral.hpp"

Mesh buildTriangleEquilateralMesh() {
    Mesh mesh;
    mesh.pushPosition(vec4(-1.0, -1.0,  0.0,  1.0));
    mesh.pushPosition(vec4( 1.0, -1.0,  0.0,  1.0));
    mesh.pushPosition(vec4( 0.0,  1.0,  0.0,  1.0));
    
    mesh.pushNormal(vec4(0.0, 0.0, 1.0, 0.0));
    mesh.pushNormal(vec4(0.0, 0.0, 1.0, 0.0));
    mesh.pushNormal(vec4(0.0, 0.0, 1.0, 0.0));
    
    mesh.pushTexcoord(vec2(0.0, 0.0));
    mesh.pushTexcoord(vec2(1.0, 0.0));
    mesh.pushTexcoord(vec2(0.5, 1.0));
    
    return mesh;
}
