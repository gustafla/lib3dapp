#pragma once

#include <vector>
#include "vectors.hpp"

class LightingState {
    public:
        LightingState(float _ambient=1.0f, std::vector<vec3> _pointLights = std::vector<vec3>(), std::vector<vec3> _directionalLights = std::vector<vec3>());
        void addPointLight(vec3 position);
        void addDirectionalLight(vec3 direction);
        void setAmbient(float _ambient);
        std::vector<vec3>& getPointLights();
        std::vector<vec3>& getDirectionalLights();
        float getAmbient();
        
    private:
        float ambient;
        std::vector<vec3> pointLights;
        std::vector<vec3> directionalLights;
};
