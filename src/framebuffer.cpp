#include "framebuffer.hpp"

Framebuffer::Framebuffer(GLuint w, GLuint h):
width(w),
height(h),
texture(w, h),
renderbuffer(w, h) {
    glGenFramebuffers(1, &handle);
    glBindFramebuffer(GL_FRAMEBUFFER, handle);
    
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture.getHandle(), 0);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, renderbuffer.getHandle());
}

Framebuffer::~Framebuffer() {
    glDeleteFramebuffers(1, &handle);
}

Texture& Framebuffer::getTexture() {
    return texture;
}

Renderbuffer& Framebuffer::getRenderbuffer() {
    return renderbuffer;
}

void Framebuffer::bind() {
    glBindFramebuffer(GL_FRAMEBUFFER, handle);
    glViewport(0, 0, width, height);
}

GLuint Framebuffer::getWidth() {
    return width;
}

GLuint Framebuffer::getHeight() {
    return height;
}
