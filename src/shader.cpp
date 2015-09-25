#include "shader.hpp"
#include "util.hpp"
#include <iostream>
#include "define.hpp"

inline std::string shaderPath(std::string name) {
    std::string tmp = DATA_DIR;
    tmp += "/";
    tmp += SHADER_DIR;
    tmp += "/";
    tmp += name;
    return tmp;
}

Shader::Shader():
handle(0), vname("no filename"), fname("no filename") {

}

Shader::Shader(std::string vsName, std::string fsName):
handle(0), vname(vsName), fname(fsName) {
    //Load, compile shaders
    std::string fsTemp;
    std::string vsTemp;
    if (!loadFile(fsName, fsTemp))
        exit(ERR_SHADER);
    if (!loadFile(vsName, vsTemp))
        exit(ERR_SHADER);
    if(compProgram(vsTemp, fsTemp) == GL_FALSE)
        exit(ERR_SHADER);
}

Shader::~Shader() {
    glDeleteProgram(handle);
}

GLuint Shader::getHandle() {
    return handle;
}

GLuint Shader::getUfmHandle(std::string name) {
    if (uniforms.find(name) == uniforms.end())
        uniforms[name] = glGetUniformLocation(handle, name.c_str());
    return uniforms[name];
}

GLuint Shader::getAtrHandle(std::string name) {
    if (attributes.find(name) == attributes.end())
        attributes[name] = glGetAttribLocation(handle, name.c_str());
    return attributes[name];
}

GLuint Shader::compShader(GLenum type, const char* src) {
    GLuint shader;
    GLint compiled;

    shader = glCreateShader(type);

    if (shader == 0)
        return 0;

    glShaderSource(shader, 1, &src, NULL);
    glCompileShader(shader);

    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);

    if (!compiled)
    {
        GLint infoLen = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);

        if (infoLen > 1)
        {
            char* infoLog = (char*)malloc(sizeof(char) * infoLen);
            glGetShaderInfoLog(shader, infoLen, NULL, infoLog);
            std::cout << "Error compiling shader: ";
            if (type == GL_VERTEX_SHADER)
                std::cout << vname;
            else
                std::cout << fname;
            std::cout << std::endl << infoLog << std::endl;
            free(infoLog);
        }
        glDeleteShader(shader);
        return 0;
    }
    return shader;
}

GLint Shader::compProgram(std::string vsString, std::string fsString) {
    GLuint vertexShader;
    GLuint fragmentShader;
    GLint linked;

    vertexShader = compShader(GL_VERTEX_SHADER, vsString.c_str());
    fragmentShader = compShader(GL_FRAGMENT_SHADER, fsString.c_str());

    handle = glCreateProgram();

    if (handle == 0)
        return 0;

    glAttachShader(handle, vertexShader);
    glAttachShader(handle, fragmentShader);

    glLinkProgram(handle);

    glGetProgramiv(handle, GL_LINK_STATUS, &linked);

    if (!linked)
    {
        GLint infoLen = 0;
        glGetProgramiv ( handle, GL_INFO_LOG_LENGTH, &infoLen );

        if ( infoLen > 1 )
        {
            char* infoLog = (char*)malloc(sizeof(char) * infoLen);

            glGetProgramInfoLog ( handle, infoLen, NULL, infoLog);
            std::cout << "Error linking program: " << vname << " " << fname << std::endl << infoLog << std::endl;

            free(infoLog);
        }
        glDeleteProgram(handle);
        return GL_FALSE;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return GL_TRUE;
}

void Shader::use() {
    glUseProgram(handle);
}
