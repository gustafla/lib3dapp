#pragma once

#include <cmath>
#include "vectors.hpp"

float max(float n, float m);
float min(float n, float m);
float clamp(float n, float a, float b);
float smoothstep(float edge0, float edge1, float x);
float mix(float a, float b, float n);
vec2 mix(vec2 a, vec2 b, float n);
vec3 mix(vec3 a, vec3 b, float n);
vec4 mix(vec4 a, vec4 b, float n);
vec3 triangleNormal(vec3 a, vec3 b, vec3 c);
