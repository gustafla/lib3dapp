#include "uniforms.hpp"
#include "define.hpp"
#include <cstring>

void setBaseUniforms(Program& shader, unsigned int nTex, LightingState lights, vec4 color) {
    setTextureUniforms(shader, nTex);
    setLightingUniforms(shader, lights);
    setColorUniform(shader, color);
}

void setTextureUniforms(Program& shader, unsigned int n) {
    shader.use();
    int* tab = new int[n];
    for (unsigned int i=0; i<n; i++) {
        tab[i] = i;
    }
    glUniform1iv(shader.getUfmHandle(NAME_U_TEXTURES), n, (const GLint*)tab);
    delete[] tab;
}

void setLightingUniforms(Program& shader, LightingState lights) {
    shader.use();
    glUniform1f(shader.getUfmHandle(NAME_U_LIGTH_AMBIENT), lights.getAmbient());
    glUniform3fv(shader.getUfmHandle(NAME_U_LIGTHS_DIRECTIONAL), lights.getDirectionalLights().size()*2, (GLfloat*)&lights.getDirectionalLights()[0]);
    glUniform3fv(shader.getUfmHandle(NAME_U_LIGTHS_POINT), lights.getPointLights().size()*2, (GLfloat*)&lights.getPointLights()[0]);
}

void setTimeUniform(Program& shader, float t) {
    shader.use();
    glUniform1f(shader.getUfmHandle(NAME_U_TIME), t);
}

void setColorUniform(Program& shader, vec4 c) {
    shader.use();
    glUniform4fv(shader.getUfmHandle(NAME_U_COLOR), 1, (GLfloat*)&c);
}

void setResolutionUniform(Program& shader, vec2 r) {
    shader.use();
    glUniform2fv(shader.getUfmHandle(NAME_U_RESOLUTION), 1, (GLfloat*)&r);
}
