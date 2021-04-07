#version 460

out vec2 vpos;
uniform mat4 modelViewProjectionMatrix;
in vec2 position;

void main() {
	vpos = position-1.0;
	gl_Position = vec4(vpos,0.0,1.0);
}