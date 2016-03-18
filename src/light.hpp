#pragma once

#include "vectors.hpp"

struct Light {
    Light(vec3 _vector=vec3(0.0), vec3 _color=vec3(1.0));
    vec3 vector;
    vec3 color;
};
