#pragma once
#include <string>
#include "vectors.hpp"

float randf();
bool isdigits(std::string s);
bool isfloat(std::string s);
bool loadFile(std::string inFileName, std::string& outString, int linesize=4096);
int countSubstring(const std::string& str, const std::string& sub);
