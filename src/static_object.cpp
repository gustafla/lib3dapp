#include "static_object.hpp"
#include "graphics.hpp"
#include <vector>
#include <cstdlib>
#include <iostream>
#include "define.hpp"

StaticObject::StaticObject(Mesh& mesh):
normals(false),
texcoords(false),
data(NULL),
stride(SIZE_POS),
verts(mesh.getPositions().size()) {
    if (mesh.getNormals().size()) {
        normals = true;
        stride += SIZE_NORMAL;
    }
    if (mesh.getTexcoords().size()) {
        texcoords = true;
        stride += SIZE_TEXCOORD;
    }
    std::vector<GLfloat> array;
    if (!mesh.getAOSArray(array)) {
        std::cout << "StaticObject " << this << " tried to load an incomplete Mesh: " << &mesh << ".\n";
        std::cout << "Mesh vertices:  " << mesh.getPositions().size() << "\n";
        std::cout << "Mesh texcoords: " << mesh.getTexcoords().size() << "\n";
        std::cout << "Mesh normals:   " << mesh.getNormals().size() << "\n";
        exit(ERR_STATIC_OBJECT);
    }
    data = new Buffer(&array[0], array.size()*sizeof(GLfloat), GL_STATIC_DRAW);
}

StaticObject::~StaticObject() {
    delete data;
}

void StaticObject::draw(Shader& shader) {
    shader.use();
    
    GLuint offset=0;
    
    data->bind();
    
    glEnableVertexAttribArray(shader.getAtrHandle(NAME_POS));
    glVertexAttribPointer(shader.getAtrHandle(NAME_POS), SIZE_POS, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*stride, INT2P(offset));
    offset += SIZE_POS * sizeof(GLfloat);
    
    if (texcoords) {
        glEnableVertexAttribArray(shader.getAtrHandle(NAME_TEXCOORD));
        glVertexAttribPointer(shader.getAtrHandle(NAME_TEXCOORD), SIZE_TEXCOORD, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*stride, INT2P(offset));
        offset += SIZE_TEXCOORD * sizeof(GLfloat);
    }
    
    if (normals) {
        glEnableVertexAttribArray(shader.getAtrHandle(NAME_NORMAL));
        glVertexAttribPointer(shader.getAtrHandle(NAME_NORMAL), SIZE_NORMAL, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*stride, INT2P(offset));
        offset += SIZE_NORMAL * sizeof(GLfloat);
    }
    
    glDrawArrays(GL_TRIANGLES, 0, verts);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
