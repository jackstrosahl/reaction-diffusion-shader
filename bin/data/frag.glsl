#version 460

layout(rgba8, binding=0) uniform image2D trails;

in vec2 vpos;
uniform float time;
out vec4 color;
void main() {
    color = imageLoad(trails, ivec2(gl_FragCoord));
}