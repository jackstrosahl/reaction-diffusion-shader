#version 460

struct Cell {
    float a;
    float b;
};

layout(std140, binding=0) buffer cellBuf {
    Cell c[];
};

in vec2 vpos;
uniform float time;
uniform vec2 ssize;
out vec4 color;

int getId(vec2 coord) {
    return  int(coord.x  + (coord.y * ssize.x));
}
float f = .055;
float k = .062;
Cell d = {1,.5};

Cell laplace(vec2 pos) {
    Cell sum = {0,0};
    float ox = pos.x;
    float oy = pos.y;
    for(float x=ox-1;x<=ox+1;x++) {
        for(float y=oy-1;y<=oy+1;y++) {
            if(x<0 || x>ssize.x || y<0 || y>ssize.y)
                continue;
            Cell n = c[getId(vec2(x,y))];
            
            float dx = x-ox;
            float dy = y-oy;
            float weight = -1;
            if(dx != 0 && dy !=0) {
                weight = .05;
            } else if(dx != 0 || dy != 0) {
                weight = .2;
            }

            sum.a += n.a * weight;
            sum.b += n.b * weight;
        }
    }
    return sum;
}

void main() {
    vec2 pos = gl_FragCoord.xy;
    int id = getId(pos);
    float ab2 = c[id].a*c[id].b*c[id].b;
    Cell laplace = laplace(pos);
    //c[id].a += d.a*laplace.a-ab2+f*(1-c[id].a);
    //c[id].b += d.b*laplace.b+ab2-(k+f)*c[id].b;
    color = vec4(c[id].a,c[id].b,0.0,1.0);;
}