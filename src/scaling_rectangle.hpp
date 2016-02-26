#pragma once

#include "graphics.hpp"
#include "vectors.hpp"
#include "program.hpp"
#include "static_model.hpp"

class ScalingRectangle {
    public:
        ScalingRectangle(vec2 src, vec2 tgt, float scale=1.0, vec2 offset=vec2(0.0));
        ~ScalingRectangle();
        void draw(Program& shader);
        void resize(vec2 src, vec2 tgt, float scale=1.0, vec2 offset=vec2(0.0));
        void move(vec2 offset, float scale=1.0);
    private:
        vec2 source;
        vec2 target;
        vec4 vertices[6];
        StaticModel* vbo;
};
