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

#include "3dapp_program.hpp"
#include "3dapp_util.hpp"
#include <iostream>
#include <cstdlib>
#include "3dapp_consts.hpp"
#include "3dapp_shader.hpp"

using namespace Lib3dapp;

Program::Program(Shader vertexShader, Shader fragmentShader):
handle(0) {
    GLint linked; //Link status flag, used later
    
    handle = glCreateProgram();
    check();

    if (handle == 0) {
        std::cout << "Program couldn't create a new program object for " << vertexShader.getName() << " and " << fragmentShader.getName() << std::endl;
        exit(ERR_PROGRAM);
    }

    //Link the Program
    use();
    glAttachShader(handle, vertexShader.getHandle());
    glAttachShader(handle, fragmentShader.getHandle());
    glLinkProgram(handle);
    check();

    glGetProgramiv(handle, GL_LINK_STATUS, &linked);

    //In case of failure
    if (!linked) {
        GLint infoLen = 0;
        glGetProgramiv (handle, GL_INFO_LOG_LENGTH, &infoLen);

        if (infoLen > 1) {
            GLchar* infoLog = new GLchar[infoLen];
            glGetProgramInfoLog (handle, infoLen, NULL, infoLog);
            std::cout << "Program couldn't link " << vertexShader.getName() << " and " << fragmentShader.getName() << std::endl << infoLog << std::endl;
            delete[] infoLog;
        }
        glDeleteProgram(handle);
        exit(ERR_PROGRAM);
    }
    
    //Look up and store all uniforms to a string keyed std::map
    int uniformCount;
    int uniformLength;
    glGetProgramiv(handle, GL_ACTIVE_UNIFORMS, &uniformCount);
    glGetProgramiv(handle, GL_ACTIVE_UNIFORM_MAX_LENGTH, &uniformLength);
    GLchar* ufmName = new GLchar[uniformLength];
    GLint ufmSize;
    GLenum ufmType;
    for (int i=0; i<uniformCount; i++) {
        glGetActiveUniform(handle, i, uniformLength, NULL, &ufmSize, &ufmType, ufmName);
        uniforms[std::string(ufmName)] = glGetUniformLocation(handle, ufmName)+1;
    }
    delete[] ufmName;
    
    //Look up and store all attributes to a string keyed std::map
    //Incremented by 1 because 0 is the default in std::map<,int>
    //And we in fact want -1
    int attribCount;
    int attribLength;
    glGetProgramiv(handle, GL_ACTIVE_ATTRIBUTES, &attribCount);
    glGetProgramiv(handle, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &attribLength);
    GLchar* atrName = new GLchar[attribLength];
    GLint atrSize;
    GLenum atrType;
    for (int i=0; i<attribCount; i++) {
        glGetActiveAttrib(handle, i, attribLength, NULL, &atrSize, &atrType, atrName);
        attributes[std::string(atrName)] = glGetAttribLocation(handle, atrName)+1;
    }
    delete[] atrName;
}

Program::~Program() {
    glDeleteProgram(handle);
}

GLuint Program::getHandle() {
    return handle;
}

GLint Program::getUfmHandle(std::string name) {
    return uniforms[name]-1; //Decrement back to original.
    //Default 0 will give -1 now.
}

GLint Program::getAtrHandle(std::string name) {
    return attributes[name]-1;
}

void Program::use() {
    glUseProgram(handle);
}
