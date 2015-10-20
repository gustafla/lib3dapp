#pragma once

#include <vector>
#include <string>
#include <map>
#include "mesh.hpp"
#include "shader.hpp"
#include "static_model.hpp"
#include "texture.hpp"
#include "primitives.hpp"

/* STD::MAP MIGHT BE SLOW, CONSIDER REPLACING */

class ResourceHandler {
    public:
        StaticModel* getStaticModel(std::string name);
        Texture* getTexture(std::string name);
        void freeStaticModels();
        void freeTextures();
        
        //const Primitives primitives;
        
    private:
        std::map<std::string, StaticModel*> staticModels;
        std::map<std::string, Texture*> textures;
};
