#pragma once

#include "graphics.hpp"
#include "matrices.hpp"

class MVP {
    public:
        MVP(mat4 _projection, GLfloat vtx=0.0f, GLfloat vty=0.0f, GLfloat vtz=0.0f, GLfloat vrx=0.0f, GLfloat vry=0.0f, GLfloat vrz=0.0f, GLfloat tx=0.0f, GLfloat ty=0.0f, GLfloat tz=0.0f, GLfloat rx=0.0f, GLfloat ry=0.0f, GLfloat rz=0.0f, GLfloat _scale=1.0f);
        void buildMVP();
        void buildModel();
        void buildView();
        
        const mat4& getView();
        const mat4& getModel();
        const mat4& getMVP();
        const float* getMVPArray();
        void setProjection(mat4& projection);
        
        void setView(GLfloat vtx=0.0f, GLfloat vty=0.0f, GLfloat vtz=0.0f, GLfloat vrx=0.0f, GLfloat vry=0.0f, GLfloat vrz=0.0f);
        void setViewTranslation(GLfloat vtx=0.0f, GLfloat vty=0.0f, GLfloat vtz=0.0f);
        void setViewRotation(GLfloat vrx=0.0f, GLfloat vry=0.0f, GLfloat vrz=0.0f);
        
        void setModel(GLfloat tx=0.0f, GLfloat ty=0.0f, GLfloat tz=0.0f, GLfloat rx=0.0f, GLfloat ry=0.0f, GLfloat rz=0.0f, GLfloat _scale=1.0f);
        void setModelTranslation(GLfloat tx=0.0f, GLfloat ty=0.0f, GLfloat tz=0.0f);
        void setModelRotation(GLfloat rx=0.0f, GLfloat ry=0.0f, GLfloat rz=0.0f);
        void setModelScale(GLfloat _scale=1.0f);
        
    private:
        mat4 mvp;
    
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
