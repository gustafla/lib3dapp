#include "shader.hpp"
#include "util.hpp"
#include "define.hpp"
#include <iostream>
#include <cstdlib>

Shader::Shader(std::string filename):
handle(0),
name(filename) {
    GLuint type = GL_VERTEX_SHADER;
    std::size_t found = filename.find_last_of(".");
    std::string extension = filename.substr(found+1);
    if (extension != "vert") {
        if (extension != "frag") {
            std::cout << "Shader unsure of file type " << filename << std::endl;
            exit(ERR_SHADER);
        } else {
            type = GL_FRAGMENT_SHADER;
        }
    }
    
    std::string source;
    if (!loadFile(filename, source)) {
        std::cout << "Shader couldn't load file " << filename << std::endl;
    }
    
    if ((handle = glCreateShader(type)) == 0) {
        std::cout << "Shader couldn't create a new shader object for " << filename << std::endl;
        exit(ERR_SHADER);
    }
    
    const char* sourcePtr = source.c_str();
    glShaderSource(handle, 1, &sourcePtr, NULL);
    glCompileShader(handle);

    GLint compiled;
    glGetShaderiv(handle, GL_COMPILE_STATUS, &compiled);

    if (!compiled) {
        GLint infoLen = 0;
        glGetShaderiv(handle, GL_INFO_LOG_LENGTH, &infoLen);

        if (infoLen > 1) {
            char* infoLog = (char*)malloc(sizeof(char) * infoLen);
            glGetShaderInfoLog(handle, infoLen, NULL, infoLog);
            std::cout << "Shader couldn't compile file " << filename << std::endl;
            std::cout << infoLog << std::endl;
            free(infoLog);
        }
        glDeleteShader(handle);
    }
}

GLuint Shader::getHandle() {
    return handle;
}

Shader::~Shader() {
    glDeleteShader(handle);
}

std::string Shader::getName() {
    return name;
}
