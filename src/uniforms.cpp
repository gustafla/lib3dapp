#include "uniforms.hpp"
#include <cstring>

void setUniforms(Program& shader, unsigned int nTex, LightingState lights) {
    setTextureUniforms(shader, nTex);
    setLightingUniforms(shader, lights);
}

void setTextureUniforms(Program& shader, unsigned int n) {
    shader.use();
    char buf[16];
    for(GLuint i=0; i<n; i++) {
        sprintf(buf, "u_texture%d", i);
        glUniform1i(shader.getUfmHandle(std::string(buf)), i);
    }
}

void setLightingUniforms(Program& shader, LightingState lights) {
    shader.use();
    glUniform1f(shader.getUfmHandle("u_light_ambient"), lights.getAmbient());
    glUniform3fv(shader.getUfmHandle("u_lights_directional"), lights.getDirectionalLights().size(), (GLfloat*)&lights.getDirectionalLights()[0]);
    glUniform3fv(shader.getUfmHandle("u_lights_point"), lights.getPointLights().size(), (GLfloat*)&lights.getPointLights()[0]);
}
