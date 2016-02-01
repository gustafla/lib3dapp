#pragma once

#include <map>
#include <string>
#include "shader.hpp"
#include "graphics.hpp"

std::string shaderPath(std::string name);

class Program {
    public:
        Program();
        Program(Shader vertexShader, Shader fragmentShader);
        ~Program();
        GLuint getHandle();
        GLuint getUfmHandle(std::string);
        GLuint getAtrHandle(std::string);
        void use();
    
    private:
        std::map<std::string, GLuint> uniforms;
        std::map<std::string, GLuint> attributes;
        //std::string vname;
        //std::string fname;
        //GLuint compShader(GLenum type, const char* src);
    
        GLuint handle;
};
