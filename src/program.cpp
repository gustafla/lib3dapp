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

#include "program.hpp"
#include "util.hpp"
#include <iostream>
#include <cstdlib>
#include "define.hpp"
#include "shader.hpp"

Program::Program(Shader vertexShader, Shader fragmentShader):
handle(0) {
    GLint linked;
    
    handle = glCreateProgram();
    check();

    if (handle == 0) {
        std::cout << "Program couldn't create a new program object for " << vertexShader.getName() << " and " << fragmentShader.getName() << std::endl;
        exit(ERR_PROGRAM);
    }

    glAttachShader(handle, vertexShader.getHandle());
    check();
    glAttachShader(handle, fragmentShader.getHandle());
    check();

    glLinkProgram(handle);
    check();

    glGetProgramiv(handle, GL_LINK_STATUS, &linked);

    if (!linked) {
        GLint infoLen = 0;
        glGetProgramiv ( handle, GL_INFO_LOG_LENGTH, &infoLen );

        if (infoLen > 1) {
            char* infoLog = (char*)malloc(sizeof(char) * infoLen);

            glGetProgramInfoLog ( handle, infoLen, NULL, infoLog);
            std::cout << "Program couldn't link " << vertexShader.getName() << " and " << fragmentShader.getName() << std::endl << infoLog << std::endl;

            free(infoLog);
        }
        glDeleteProgram(handle);
        exit(ERR_PROGRAM);
    }
}

Program::~Program() {
    glDeleteProgram(handle);
    check();
}

GLuint Program::getHandle() {
    return handle;
}

GLuint Program::getUfmHandle(std::string name) {
    if (uniforms.find(name) == uniforms.end())
        uniforms[name] = glGetUniformLocation(handle, name.c_str());
    check();
    return uniforms[name];
}

GLuint Program::getAtrHandle(std::string name) {
    if (attributes.find(name) == attributes.end())
        attributes[name] = glGetAttribLocation(handle, name.c_str());
    check();
    return attributes[name];
}

void Program::use() {
    glUseProgram(handle);
    check();
}
