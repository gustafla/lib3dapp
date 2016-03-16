#pragma once

#include "lighting_state.hpp"
#include "program.hpp"
#include "graphics.hpp"

void setUniforms(Program& shader, unsigned int nTex=4, LightingState lights=LightingState());
void setTextureUniforms(Program& shader, unsigned int n=4);
void setLightingUniforms(Program& shader, LightingState lights=LightingState());
