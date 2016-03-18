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
