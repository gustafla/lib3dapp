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

#include "gfx_utils.hpp"

float max(float n, float m) {
    return (n>m) ? n : m;
}

float min(float n, float m) {
    return (n>m) ? m : n;
}

float clamp(float n, float a, float b) {
    return ((n<a) ? a : ((n>b) ? b : n));
}

float smoothstep(float edge0, float edge1, float x) { //Stolen from Wikipedia :^)
    // Scale, bias and saturate x to 0..1 range
    x = clamp((x - edge0)/(edge1 - edge0), 0.0, 1.0); 
    // Evaluate polynomial
    return x*x*(3 - 2*x);
}

//Templates, again... Well, this works too.
float mix(float a, float b, float n) {
    return a*(1-n)+b*n;
}

vec2 mix(vec2 a, vec2 b, float n) {
    return a*(1-n)+b*n;
}

vec3 mix(vec3 a, vec3 b, float n) {
    return a*(1-n)+b*n;
}

vec4 mix(vec4 a, vec4 b, float n) {
    return a*(1-n)+b*n;
}

vec3 triangleNormal(vec3 a, vec3 b, vec3 c) {
    vec3 v, w;
    v = b - a;
    w = c - a;
    return vnml(vec3((v.y*w.z - v.z*w.y), (v.z*w.x - v.x*w.z), (v.x*w.y - v.y*w.x)));
}

RgbaImage getPixel(vec4 color, bool alpha) {
    RgbaImage pixel(1, 1, alpha ? 4:3, true, alpha);
    pixel.getArray()[0] = color.x;
    pixel.getArray()[1] = color.y;
    pixel.getArray()[2] = color.z;
    if (alpha)
        pixel.getArray()[3] = color.w;
    return pixel;
}
