#include "buffer.hpp"

Buffer::Buffer(GLfloat* data, GLuint size, GLuint hint) {
    glGenBuffers(1, &handle);
    bind();
    glBufferData(GL_ARRAY_BUFFER, size, data, hint);
}

Buffer::Buffer():
handle(0) {
}

Buffer::~Buffer() {
    glDeleteBuffers(1, &handle);
}

void Buffer::bind() {
    glBindBuffer(GL_ARRAY_BUFFER, handle);
}
