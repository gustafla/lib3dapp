#include "texture.hpp"
#include <iostream>
#include "define.hpp"

Texture::Texture(RgbaImage& image) {
    GLuint format;
    if (image.hasAlpha() && image.hasColor())
        format = GL_RGBA;
    else if (!image.hasAlpha() && image.hasColor())
        format = GL_RGB;
    else if (image.hasAlpha() && !image.hasColor())
        format = GL_RED;
    else {
        std::cout << "Texture tried to load a broken RgbaImage!\n";
        exit(ERR_TEXTURE);
    }
    glActiveTexture(GL_TEXTURE0);
    glGenTextures(1, &handle);
    glBindTexture(GL_TEXTURE_2D, handle);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, format, image.getWidth(), image.getHeight(), 0, format, GL_UNSIGNED_BYTE, image.getArray());
    std::cout << "Texture loaded. " << format << " " << image.getWidth() << " " << image.getHeight() << " " << (image.hasAlpha() ? "alpha" : "no alpha") << std::endl;
}

Texture::~Texture() {
    glDeleteTextures(1, &handle);
}

void Texture::bindToUnit(GLuint unit) {
    glActiveTexture(GL_TEXTURE0+unit);
    glBindTexture(GL_TEXTURE_2D, handle);
}
