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
#include "matrices.hpp"
#include "program.hpp"

class MVP {
    public:
        MVP(mat4 _projection, GLfloat vtx=0.0f, GLfloat vty=0.0f, GLfloat vtz=0.0f, GLfloat vrx=0.0f, GLfloat vry=0.0f, GLfloat vrz=0.0f, GLfloat tx=0.0f, GLfloat ty=0.0f, GLfloat tz=0.0f, GLfloat rx=0.0f, GLfloat ry=0.0f, GLfloat rz=0.0f, GLfloat _scale=1.0f);
        
        /*const mat4& getView();
        const mat4& getModel();
        const mat4& getMVP();
        const float* getMVPArray();
        const float* getModelRotationArray();*/
        void setProjection(mat4& projection);
        
        void setView(GLfloat vtx=0.0f, GLfloat vty=0.0f, GLfloat vtz=0.0f, GLfloat vrx=0.0f, GLfloat vry=0.0f, GLfloat vrz=0.0f);
        void setViewTranslation(GLfloat vtx=0.0f, GLfloat vty=0.0f, GLfloat vtz=0.0f);
        void setViewRotation(GLfloat vrx=0.0f, GLfloat vry=0.0f, GLfloat vrz=0.0f);
        
        void setModel(GLfloat tx=0.0f, GLfloat ty=0.0f, GLfloat tz=0.0f, GLfloat rx=0.0f, GLfloat ry=0.0f, GLfloat rz=0.0f, GLfloat _scale=1.0f);
        void setModelTranslation(GLfloat tx=0.0f, GLfloat ty=0.0f, GLfloat tz=0.0f);
        void setModelRotation(GLfloat rx=0.0f, GLfloat ry=0.0f, GLfloat rz=0.0f);
        void setModelScale(GLfloat _scale=1.0f);
        
        void apply(Program& shader);
        
        void reset();
        
    private:
        void buildModel();
        void buildView();
    
        bool viewModified;
        bool modelModified;
        bool projectionModified;
    
        mat4 projection;
        
        mat4 viewTranslation;
        mat4 viewRotation;
        mat4 view;
        
        mat4 modelRotation;
        mat4 modelScale;
        mat4 modelTranslation;
        mat4 model;
        
        mat4 identity;
};
