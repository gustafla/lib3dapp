#include "renderbuffer.hpp"

Renderbuffer::Renderbuffer(GLuint w, GLuint h) {
    glGenRenderbuffers(1, &handle);
    glBindRenderbuffer(GL_RENDERBUFFER, handle);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, w, h);
}

Renderbuffer::~Renderbuffer() {
    glDeleteRenderbuffers(1, &handle);
}

GLuint Renderbuffer::getHandle() {
    return handle;
}

void Renderbuffer::bind() {
    glBindRenderbuffer(GL_RENDERBUFFER, handle);
}
