#include "lighting_state.hpp"

LightingState::LightingState(float _ambient, std::vector<vec3> _pointLights, std::vector<vec3> _directionalLights):
ambient(_ambient),
pointLights(_pointLights),
directionalLights(_directionalLights) {
    
}

void LightingState::addPointLight(vec3 position) {
    pointLights.push_back(position);
}

void LightingState::addDirectionalLight(vec3 direction) {
    directionalLights.push_back(vnml(direction));
}

void LightingState::setAmbient(float _ambient) {
    ambient = _ambient;
}

std::vector<vec3>& LightingState::getPointLights() {
    return pointLights;
}

std::vector<vec3>& LightingState::getDirectionalLights() {
    return directionalLights;
}

float LightingState::getAmbient() {
    return ambient;
}
