#include "buffer.hpp"

Buffer::Buffer(GLfloat* data, GLuint size, GLenum hint) {
    glGenBuffers(1, &handle);
    check();
    bind();
    glBufferData(GL_ARRAY_BUFFER, size, data, hint);
    check();
}

Buffer::Buffer():
handle(0) {
}

Buffer::~Buffer() {
    glDeleteBuffers(1, &handle);
    check();
}

void Buffer::bind() {
    glBindBuffer(GL_ARRAY_BUFFER, handle);
    check();
}
