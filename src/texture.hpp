#pragma once

#include "graphics.hpp"
#include "rgba_image.hpp"

class Texture {
    public:
        Texture(RgbaImage image);
        Texture(GLuint w, GLuint h);
        ~Texture();
        
        GLuint getHandle();
        void bindToUnit(GLuint unit);
        
        GLuint getWidth();
        GLuint getHeight();
        float getAspect();
        
        void setFilter(GLuint _filter=GL_LINEAR);
        
    private:
        GLuint handle;
        GLuint width;
        GLuint height;
        GLuint filter;
};
