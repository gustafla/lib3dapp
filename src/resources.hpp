#pragma once

#include <vector>
#include <string>
#include <map>
#include "mesh.hpp"
#include "shader.hpp"
#include "static_model.hpp"
#include "primitives.hpp"

/* STD::MAP MIGHT BE SLOW, CONSIDER REPLACING */

class Resources {
    public:
        StaticModel& getStaticModel(std::string name);
        void freeStaticModels();
        
        const Primitives primitives;
        
    private:
        std::map<std::string, StaticModel*> staticModels;
};
