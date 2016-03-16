#pragma once

#include <vector>
#include "vectors.hpp"

class Mesh {
    public:
        Mesh();
        void pushPosition(vec3 position);
        void pushNormal(vec3 normal);
        void pushTexcoord(vec2 texcoord);
        const std::vector<vec3>& getPositions();
        const std::vector<vec3>& getNormals();
        const std::vector<vec2>& getTexcoords();
        const bool getAOSArray(std::vector<float>& array);
        void getSOAArray(std::vector<float>& posArray, std::vector<float>& nmlArray, std::vector<float>& texArray);
    private:
        std::vector<vec3> positions;
        std::vector<vec3> normals;
        std::vector<vec2> texcoords;
};
