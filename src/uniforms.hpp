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

#pragma once

#include "lighting_state.hpp"
#include "program.hpp"
#include "graphics.hpp"
#include "define.hpp"

void setBaseUniforms(Program& shader, unsigned int nTex=1, LightingState lights=LightingState(), vec4 color=vec4(0.0f), float opacity=1.0f);
void setTextureUniforms(Program& shader, unsigned int n=1);
void setLightingUniforms(Program& shader, LightingState lights=LightingState());
void setTimeUniform(Program& shader, float t=0.0f);
void setColorUniform(Program& shader, vec4 c=vec4(0.0f));
void setOpacityUniform(Program& shader, float a);
void setResolutionUniform(Program& shader, vec2 r=vec2(SCREEN_W, SCREEN_H));
