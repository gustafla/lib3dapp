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

#include "shader.hpp"
#include "util.hpp"
#include "define.hpp"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <climits>

Shader::Shader(std::string filename, LightingState lights):
handle(0),
name(filename) {
    GLenum type = GL_VERTEX_SHADER;
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
    
    handle = glCreateShader(type);
    if (handle == 0) {
        std::cout << "Shader couldn't create a new shader object for " << filename << std::endl;
        exit(ERR_SHADER);
    }
    check();
    
    const unsigned int NUM_DIGITS = 16;
    char lightsStr[sizeof("#define ")*2 + sizeof(MACRO_LIGHTS_DIRECTIONAL) + sizeof(MACRO_LIGHTS_POINT) + NUM_DIGITS*2 + 3];
    char directionalLightsStr[NUM_DIGITS];
    char pointLightsStr[NUM_DIGITS];
    sprintf(directionalLightsStr, "%d", lights.getDirectionalLights().size());
    sprintf(pointLightsStr, "%d", lights.getPointLights().size());
    strcpy(lightsStr, "#define ");
    strcat(lightsStr, MACRO_LIGHTS_DIRECTIONAL);
    strcat(lightsStr, " ");
    strcat(lightsStr, directionalLightsStr);
    strcat(lightsStr, "\n#define ");
    strcat(lightsStr, MACRO_LIGHTS_POINT);
    strcat(lightsStr, " ");
    strcat(lightsStr, pointLightsStr);
    strcat(lightsStr, "\n");
    
    const char* sourceStr = source.c_str();
    const char* finalSource[2] = {lightsStr, sourceStr};
    glShaderSource(handle, 2, finalSource, NULL);
    check();
    
    glCompileShader(handle);
    check();

    GLint compiled;
    glGetShaderiv(handle, GL_COMPILE_STATUS, &compiled);
    check();

    if (!compiled) {
        GLint infoLen = 0;
        glGetShaderiv(handle, GL_INFO_LOG_LENGTH, &infoLen);
        check();
        
        if (infoLen > 1) {
            char* infoLog = (char*)malloc(sizeof(char) * infoLen);
            glGetShaderInfoLog(handle, infoLen, NULL, infoLog);
            std::cout << "Shader couldn't compile file " << filename << std::endl;
            std::cout << infoLog << std::endl;
            free(infoLog);
        }
        glDeleteShader(handle);
        exit(ERR_SHADER);
    }
}

GLuint Shader::getHandle() {
    return handle;
}

Shader::~Shader() {
    glDeleteShader(handle);
    check();
}

std::string Shader::getName() {
    return name;
}
