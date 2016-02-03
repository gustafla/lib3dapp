#pragma once

#include "graphics.hpp"
#include "vectors.hpp"
#include "program.hpp"
#include "static_model.hpp"

class ScalingRectangle {
    public:
        ScalingRectangle(vec2 src, vec2 tgt);
        ~ScalingRectangle();
        void draw(Program& shader);
        void resize(vec2 src, vec2 tgt);
    private:
        vec4 vertices[6];
        StaticModel* vbo;
};
