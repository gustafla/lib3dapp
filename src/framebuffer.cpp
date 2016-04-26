// Copyright 2016 Lauri Gustafsson
/*  This file is part of lib3dapp.

    lib3dapp is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    lib3dapp is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with lib3dapp.  If not, see <http://www.gnu.org/licenses/>.*/

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
