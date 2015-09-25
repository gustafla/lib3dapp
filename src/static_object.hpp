#pragma once

#include "buffer.hpp"
#include "mesh.hpp"
#include "shader.hpp"

class StaticObject {
    public:
        StaticObject(Mesh& mesh);
        ~StaticObject();
        void draw(Shader& shader);
    private:
        GLuint verts;
        bool texcoords;
        bool normals;
        GLuint stride;
        Buffer* data;
};
