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

#include <vector>
#include <cstdlib>
#include "vectors.hpp"
#include "light.hpp"

class LightingState {
    public:
        LightingState(float _ambient=1.0f, const Light* _pointLights=NULL, unsigned int nPointLights=0, const Light* _directionalLights=NULL, unsigned int nDirectionalLights=0);
        void addPointLight(Light light);
        void addDirectionalLight(Light light);
        void setAmbient(float _ambient);
        void setPointLight(unsigned int i, Light light);
        void setDirectionalLight(unsigned int i, Light light);
        std::vector<Light>& getPointLights();
        std::vector<Light>& getDirectionalLights();
        float getAmbient();
        
    private:
        float ambient;
        std::vector<Light> pointLights;
        std::vector<Light> directionalLights;
};
