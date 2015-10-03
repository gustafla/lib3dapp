#pragma once

#include "buffer.hpp"
#include "mesh.hpp"
#include "shader.hpp"

class StaticModel {
    public:
        StaticModel(Mesh& mesh);
        ~StaticModel();
        void draw(Shader& shader);
    private:
        GLuint verts;
        bool texcoords;
        bool normals;
        GLuint stride;
        Buffer* data;
};
