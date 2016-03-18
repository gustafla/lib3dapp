#pragma once

#include "lighting_state.hpp"
#include "program.hpp"
#include "graphics.hpp"
#include "define.hpp"

void setBaseUniforms(Program& shader, unsigned int nTex=1, LightingState lights=LightingState(), vec4 color=vec4(0.0f));
void setTextureUniforms(Program& shader, unsigned int n=1);
void setLightingUniforms(Program& shader, LightingState lights=LightingState());
void setTimeUniform(Program& shader, float t=0.0f);
void setColorUniform(Program& shader, vec4 c=vec4(0.0f));
void setResolutionUniform(Program& shader, vec2 r=vec2(SCREEN_W, SCREEN_H));
