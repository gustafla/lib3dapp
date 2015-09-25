#pragma once

#include <vector>
#include "vectors.hpp"

class Mesh {
    public:
        Mesh();
        void pushPosition(vec4 position);
        void pushNormal(vec4 normal);
        void pushTexcoord(vec2 texcoord);
        std::vector<vec4>& getPositions();
        std::vector<vec4>& getNormals();
        std::vector<vec2>& getTexcoords();
        bool getAOSArray(std::vector<float>& array);
        void getSOAArray(std::vector<float>& posArray, std::vector<float>& nmlArray, std::vector<float>& texArray);
    private:
        std::vector<vec4> positions;
        std::vector<vec4> normals;
        std::vector<vec2> texcoords;
};
