#include "matrices.hpp"
#include "graphics.hpp"
#include <cmath>

mat4 getPProjMat(float fov, float aspect, float znear, float zfar) {
    mat4 mat;
    
    float xymax = znear * tan(fov * (M_PI/360.0));
    float ymin = -xymax;
    float xmin = -xymax;

    float width = xymax - xmin;
    float height = xymax - ymin;

    float depth = zfar - znear;
    float q = -(zfar + znear) / depth;
    float qn = -2 * (zfar * znear) / depth;

    float w = 2 * znear / width;
    w = w / aspect;
    float h = 2 * znear / height;
    
    mat.a.x = w;
    mat.b.y = h;
    mat.c.z = q;
    mat.c.w = -1.0f;
    mat.d.z = qn;
    
    return mat;
}

mat4 getOProjMat(float right, float top, float left, float bottom, float near, float far) {
	mat4 mat;
			
	mat.a.x = 2.0f / (right - left);
	mat.b.y = 2.0f / (top - bottom);
	mat.c.z = -2.0f / (far - near);
	mat.d.x = -(right + left  ) / (right - left  );
	mat.d.y = -(top   + bottom) / (top   - bottom);
	mat.d.z = -(far   + near  ) / (far   - near  );
	mat.d.w = 1.0f;
			
	return mat;
}

mat4 getXRotMat(float a) {
    mat4 mat;
    
    mat.a.x = 1.0;
    mat.b.y = cos(a);
    mat.b.z = -sin(a);
    mat.c.y = sin(a);
    mat.c.z = cos(a);
    mat.d.w = 1.0f;
    
    return mat;
}

mat4 getYRotMat(float a) {
    mat4 mat;
    
    mat.a.x = cos(a);
    mat.a.z = sin(a);
    mat.b.y = 1.0f;
    mat.c.x = -sin(a);
    mat.c.z = cos(a);
    mat.d.w = 1.0f;
    
    return mat;
}

mat4 getZRotMat(float a) {
    mat4 mat;
    
    mat.a.x = cos(a);
    mat.a.y = -sin(a);
    mat.b.x = sin(a);
    mat.b.y = cos(a);
    mat.c.z = 1.0f;
    mat.d.w = 1.0f;
    
    return mat;
}

mat4 getXYZRotMat(float x, float y, float z) {
    return getXRotMat(x) * getYRotMat(y) * getZRotMat(z);
}

mat4 getTranslationMat(float x, float y, float z) {
    mat4 mat;
    
    mat.a.x = 1.0f;
    mat.b.y = 1.0f;
    mat.c.z = 1.0f;
    mat.d.x = x;
    mat.d.y = y;
    mat.d.z = z;
    mat.d.w = 1.0f;
    
    return mat;
}

mat4 getScaleMat(float x, float y, float z) {
    mat4 mat;
    
    mat.a.x = x;
    mat.b.y = y;
    mat.c.z = z;
    mat.d.w = 1.0f;
    
    return mat;
}

mat4 getScaleMat(float x) {
    mat4 mat;
    
    mat.a.x = x;
    mat.b.y = x;
    mat.c.z = x;
    mat.d.w = 1.0f;
    
    return mat;
}

mat4::mat4() {
    a = b = c = d = vec4(0.0f);
}

mat4::mat4(const mat4& r) {
    a = r.a;
    b = r.b;
    c = r.c;
    d = r.d;
}

mat4::mat4(vec4 _a, vec4 _b, vec4 _c, vec4 _d) {
    a = _a;
    b = _b;
    c = _c;
    d = _d;
}

mat4& mat4::operator=(mat4 r) {
    a = r.a;
    b = r.b;
    c = r.c;
    d = r.d;
    return *this;
}

mat4& mat4::operator*=(mat4 r) {
    vec4 res[4];
    vec4 rhs[4] = {r.a, r.b, r.c, r.d};
    vec4 lhsRows[4] = {
        vec4(a.x, b.x, c.x, d.x),
        vec4(a.y, b.y, c.y, d.y),
        vec4(a.z, b.z, c.z, d.z),
        vec4(a.w, b.w, c.w, d.w)
    };
    
    for (int i=0; i<4; i++) {
        res[i].x = vdot(lhsRows[0], rhs[i]);
        res[i].y = vdot(lhsRows[1], rhs[i]);
        res[i].z = vdot(lhsRows[2], rhs[i]);
        res[i].w = vdot(lhsRows[3], rhs[i]);
    }
    
    a=res[0];
    b=res[1];
    c=res[2];
    d=res[3];
    
    return *this;
}

mat4 mat4::operator*(const mat4& b) {
    mat4 a = *this;
    a *= b;
    return a;
}

vec4 mat4::operator*(const vec4& vec) {
    vec4 product;
    product.x = vec.x*a.x + vec.y*a.y + vec.z*a.z + vec.w*a.w;
    product.y = vec.x*b.x + vec.y*b.y + vec.z*b.z + vec.w*b.w;
    product.z = vec.x*c.x + vec.y*c.y + vec.z*c.z + vec.w*c.w;
    product.w = vec.x*d.x + vec.y*d.y + vec.z*d.z + vec.w*d.w;
    return product;
}
