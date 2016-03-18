#include "lighting_state.hpp"

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
