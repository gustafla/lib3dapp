#pragma once

#include <vector>
#include "vectors.hpp"

class Mesh {
    public:
        Mesh();
        void pushCoord(vec4 coord);
        void pushNormal(vec4 normal);
        void pushTexcoord(vec2 texcoord);
        std::vector<vec4>& getCoords();
        std::vector<vec4>& getNormals();
        std::vector<vec2>& getTexcoords();
        bool getAOSArray(std::vector<float>& array);
        void getSOAArray(std::vector<float>& posArray, std::vector<float>& nmlArray, std::vector<float>& texArray);
    private:
        std::vector<vec4> positions;
        std::vector<vec4> normals;
        std::vector<vec2> texcoords;
};
