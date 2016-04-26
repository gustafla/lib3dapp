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

#include "uniforms.hpp"
#include "define.hpp"
#include <cstring>

void setBaseUniforms(Program& shader, unsigned int nTex, LightingState lights, vec4 color, float opacity) {
    setTextureUniforms(shader, nTex);
    setLightingUniforms(shader, lights);
    setColorUniform(shader, color);
    setOpacityUniform(shader, opacity);
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

void setOpacityUniform(Program& shader, float a) {
    shader.use();
    glUniform1f(shader.getUfmHandle(NAME_U_OPACITY), a);
}

void setColorUniform(Program& shader, vec4 c) {
    shader.use();
    glUniform4fv(shader.getUfmHandle(NAME_U_COLOR), 1, (GLfloat*)&c);
}

void setResolutionUniform(Program& shader, vec2 r) {
    shader.use();
    glUniform2fv(shader.getUfmHandle(NAME_U_RESOLUTION), 1, (GLfloat*)&r);
}
