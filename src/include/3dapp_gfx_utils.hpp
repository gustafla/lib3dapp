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

#include <cmath>
#include "3dapp_vectors.hpp"
#include "3dapp_rgba_image.hpp"

namespace Lib3dapp {
    float max(float n, float m);
    float min(float n, float m);
    float clamp(float n, float a, float b);
    float smoothstep(float edge0, float edge1, float x);
    float mix(float a, float b, float n);
    vec2 mix(vec2 a, vec2 b, float n);
    vec3 mix(vec3 a, vec3 b, float n);
    vec4 mix(vec4 a, vec4 b, float n);
    vec3 triangleNormal(vec3 a, vec3 b, vec3 c);
    RgbaImage getPixel(vec4 color, bool alpha=false);
};

using namespace Lib3dapp;
