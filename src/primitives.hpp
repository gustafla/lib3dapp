#pragma once

#include "static_model.hpp"

class Primitives {
    public:
        Primitives();
        
        //StaticModel cube;
        StaticModel quad;
        
        //Mesh cubeMesh;
        Mesh quadMesh;
        
    private:
    
        //Mesh buildCubeMesh();
        Mesh buildQuadMesh();
};
