#include "resources.hpp"
#include "obj_file.hpp"
#include "mesh.hpp"

StaticModel& Resources::getStaticModel(std::string name) {
    if (staticModels.find(name) == staticModels.end()) {
        Mesh modelMesh = loadOBJFile(meshPath(name));
        staticModels[name] = new StaticModel(modelMesh);
        //staticModels.insert(std::pair<std::string, StaticModel*>(name, new StaticModel(modelMesh)));
    }
    return *(staticModels[name]);
}

void Resources::freeStaticModels() {
    for (std::map<std::string, StaticModel*>::iterator it = staticModels.begin(); it != staticModels.end(); it++) {
        delete it->second;
    }
    staticModels.clear();
}
