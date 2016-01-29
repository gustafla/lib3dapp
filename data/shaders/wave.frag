#ifdef GL_ES
precision highp float;
#endif

uniform vec2 iResolution;
uniform float iGlobalTime;
uniform sampler2D iChannel0;

void main() {
    vec2 uv = gl_FragCoord.xy/iResolution.xy;
    uv.x+=sin(uv.y*10.0+iGlobalTime)*0.1;
    gl_FragColor = vec4(texture2D(iChannel0, uv).rgb, 1.0);
}
