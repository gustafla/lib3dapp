#pragma once

#include "graphics.hpp"
#include "texture.hpp"
#include "renderbuffer.hpp"

class Framebuffer {
    public:
        Framebuffer(GLuint w, GLuint h);
        ~Framebuffer();
        Texture& getTexture();
        Renderbuffer& getRenderbuffer();
        void bind();
        
        GLuint getWidth();
        GLuint getHeight();
        
    private:
        GLuint handle;
        Texture texture;
        Renderbuffer renderbuffer;
        
        GLuint width;
        GLuint height;
};
