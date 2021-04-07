#version 460

uniform vec2 ssize;

layout(rgba8, binding=0) uniform image2D trails;

layout(local_size_x = 1024, local_size_y = 1, local_size_z = 1) in;

struct Agent {
	vec2 pos;
	vec2 vel;
	vec4 col;
};

layout(std430, binding=1) buffer agentbuffer {
	Agent a[];
};

float rand(vec2 co){
    return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);
}

void main() {
	uint id = gl_GlobalInvocationID.x;

	//imageStore(trails, ivec2(a[id].pos.xy),  vec4(0.0));

	a[id].pos += a[id].vel;
	
	if(a[id].pos.x > ssize.x || a[id].pos.x < 0.0) {
		a[id].vel.x *= -1;
	}
	if(a[id].pos.y > ssize.y || a[id].pos.y < 0.0) {
		a[id].vel.y *= -1;
	}


	imageStore(trails, ivec2(a[id].pos.xy),  a[id].col);
}