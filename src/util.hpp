#pragma once
#include <string>

float randf();
bool isdigits(std::string s);
bool isfloat(std::string s);
bool loadFile(std::string inFileName, std::string& outString, int linesize=4096);
int countSubstring(const std::string& str, const std::string& sub);
float max(float n, float m);
float min(float n, float m);
float clamp(float n, float a, float b);
float smoothstep(float edge0, float edge1, float x);
