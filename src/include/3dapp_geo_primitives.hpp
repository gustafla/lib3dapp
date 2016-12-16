// Copyright 2016 Lauri Gustafsson
/*  This file is part of lib3dapp.

    lib3dapp is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    lib3dapp is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with lib3dapp.  If not, see <http://www.gnu.org/licenses/>.*/

#pragma once

#include "3dapp_static_model.hpp"
#include "3dapp_mesh.hpp"
#include "3dapp_geo_quad.hpp"
#include "3dapp_geo_triangle_equilateral.hpp"

namespace Lib3dapp {
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
        private:
            GeoPrimitives():
            meshes(new _GeoPrimitivesMeshes()),
            quad(meshes->quad),
            triangleEquilateral(meshes->triangleEquilateral) {
                delete meshes;
            }
            
            _GeoPrimitivesMeshes* meshes;
        
        public:
            static GeoPrimitives& singleton() {
                static GeoPrimitives instance;
                return instance;
            }
        
            StaticModel quad;
            StaticModel triangleEquilateral;
    };
};

