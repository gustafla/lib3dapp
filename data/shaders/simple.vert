#ifdef GL_ES
    precision highp float;
#endif

attribute vec4 a_position;

void main() {
    gl_Position = a_position;
}
