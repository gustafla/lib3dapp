#include "resource_handler.hpp"
#include "obj_file.hpp"
#include "tga_file.hpp"
#include "mesh.hpp"
#include "rgba_image.hpp"
#include <iostream>
#include "paths.hpp"

StaticModel* ResourceHandler::getStaticModel(std::string name) {
    if (staticModels.find(name) == staticModels.end()) {
        Mesh modelMesh = loadOBJFile(meshPath(name));
        staticModels[name] = new StaticModel(modelMesh);
    }
    return staticModels[name];
}

Texture* ResourceHandler::getTexture(std::string name) {
    if (textures.find(name) == textures.end()) {
        RgbaImage image = loadTGAFile(texturePath(name));
        textures[name] = new Texture(image);
    }
    return textures[name];
}

void ResourceHandler::freeStaticModels() {
    for (std::map<std::string, StaticModel*>::iterator it = staticModels.begin(); it != staticModels.end(); ++it) {
        delete it->second;
    }
    staticModels.clear();
}

void ResourceHandler::freeTextures() {
    for (std::map<std::string, Texture*>::iterator it = textures.begin(); it != textures.end(); ++it) {
        delete it->second;
    }
    textures.clear();
}
