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
