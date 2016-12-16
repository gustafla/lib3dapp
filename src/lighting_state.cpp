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

#include "3dapp_lighting_state.hpp"

using namespace Lib3dapp;

LightingState::LightingState(float _ambient, const Light* _pointLights, unsigned int nPointLights, const Light* _directionalLights, unsigned int nDirectionalLights):
ambient(_ambient) {
    for (int i=0; i<nPointLights; i++) {
        pointLights.push_back(_pointLights[i]);
    }
    
    for (int i=0; i<nDirectionalLights; i++) {
        directionalLights.push_back(_directionalLights[i]);
    }
}

void LightingState::addPointLight(Light light) {
    pointLights.push_back(light);
}

void LightingState::addDirectionalLight(Light light) {
    directionalLights.push_back(Light(vnml(light.vector), light.color));
}

void LightingState::setAmbient(float _ambient) {
    ambient = _ambient;
}

std::vector<Light>& LightingState::getPointLights() {
    return pointLights;
}

std::vector<Light>& LightingState::getDirectionalLights() {
    return directionalLights;
}

float LightingState::getAmbient() {
    return ambient;
}

void LightingState::setPointLight(unsigned int i, Light light) {
    pointLights[i] = light;
}

void LightingState::setDirectionalLight(unsigned int i, Light light) {
    directionalLights[i] = light;
}
