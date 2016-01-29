#pragma once

#include <vector>
#include "vectors.hpp"

class Mesh {
    public:
        Mesh();
        void pushPosition(vec4 position);
        void pushNormal(vec4 normal);
        void pushTexcoord(vec2 texcoord);
        const std::vector<vec4>& getPositions();
        const std::vector<vec4>& getNormals();
        const std::vector<vec2>& getTexcoords();
        const bool getAOSArray(std::vector<float>& array);
        void getSOAArray(std::vector<float>& posArray, std::vector<float>& nmlArray, std::vector<float>& texArray);
    private:
        std::vector<vec4> positions;
        std::vector<vec4> normals;
        std::vector<vec2> texcoords;
};
