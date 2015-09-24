#pragma once

#include <map>
#include <string>
#include "graphics.hpp"

std::string shaderPath(std::string name);

class Shader {
    public:
        Shader();
        Shader(std::string vsName, std::string fsName);
        ~Shader();
        GLuint getHandle();
        GLuint getUfmHandle(std::string);
        GLuint getAtrHandle(std::string);
        GLint compProgram(std::string vsString, std::string fsString);
        void use();
    
    private:
        std::map<std::string, GLuint> uniforms;
        std::map<std::string, GLuint> attributes;
        std::string vname;
        std::string fname;
        GLuint compShader(GLenum type, const char* src);
    
        GLuint handle;
};
