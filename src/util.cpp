#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include "vectors.hpp"

bool isdigits(std::string s) {
    return s.find_first_not_of("0123456789") == std::string::npos;
}

bool isfloat(std::string s) {
    return s.find_first_not_of("0123456789.") == std::string::npos;
}

bool loadFile(std::string inFileName, std::string& outString, int linesize) {
    std::ifstream inFile(inFileName.c_str());
    if (!inFile.is_open())
    {
        std::cout << inFileName << ": No such file\n";
        return false;
    }

    char tmp[(linesize)];

    while (!inFile.eof())
    {
        inFile.getline(tmp, linesize);
        outString += tmp;
        outString += "\n";
    }
    return true;
}

int countSubstring(const std::string& str, const std::string& sub) {
    if (sub.length() == 0)
        return 0;
    int count = 0;
    for (size_t offset = str.find(sub); offset != std::string::npos; offset = str.find(sub, offset + sub.length())) {
        count++;
    }
    return count;
}

float randf() {
    return ((float(rand()%100000)/100000.0f)-0.5)*2.0;
}

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
