#pragma once

#include "static_model.hpp"
#include "mesh.hpp"

#include "geo_quad.hpp"
#include "geo_triangle_equilateral.hpp"

class _GeoPrimitivesMeshes {
    public:
    
    _GeoPrimitivesMeshes():
    quad(buildQuadMesh()),
    triangleEquilateral(buildTriangleEquilateralMesh()) {
        
    }
    
    Mesh quad;
    Mesh triangleEquilateral;
};

class GeoPrimitives {
    public:
    
    GeoPrimitives():
    meshes(new _GeoPrimitivesMeshes()),
    quad(meshes->quad),
    triangleEquilateral(meshes->triangleEquilateral) {
        delete meshes;
    }
    
    static GeoPrimitives& singleton() {
        static GeoPrimitives instance;
        return instance;
    }
    
    _GeoPrimitivesMeshes* meshes;
    
    StaticModel quad;
    StaticModel triangleEquilateral;
};
