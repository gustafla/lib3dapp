#pragma once

#include "buffer.hpp"
#include "mesh.hpp"
#include "program.hpp"

class StaticModel {
    public:
        StaticModel(Mesh mesh);
        ~StaticModel();
        void draw(Program& shader);
    private:
        GLuint verts;
        bool texcoords;
        bool normals;
        GLuint stride;
        Buffer* data;
};
