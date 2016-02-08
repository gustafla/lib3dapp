#pragma once
#include <string>
#include "vectors.hpp"

float randf();
bool isdigits(std::string s);
bool isfloat(std::string s);
bool loadFile(std::string inFileName, std::string& outString, int linesize=4096);
int countSubstring(const std::string& str, const std::string& sub);
float max(float n, float m);
float min(float n, float m);
float clamp(float n, float a, float b);
float smoothstep(float edge0, float edge1, float x);
float mix(float a, float b, float n);
vec2 mix(vec2 a, vec2 b, float n);
vec3 mix(vec3 a, vec3 b, float n);
vec4 mix(vec4 a, vec4 b, float n);
