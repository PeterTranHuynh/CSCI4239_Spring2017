const char* SimpleFragmentShader = STRINGIFY(

varying lowp vec4 Color;
varying lowp vec4 Color2;
varying lowp vec3 RGB;
varying lowp vec2 XY;

// Static Effect
highp float ran = fract(sin(dot(vec2(XY[0], XY[1]) ,vec2(12.9898, 78.233))) * 43758.5453);
void main(void)
{
    // Placed ran in Red slot, thus making red static!
    gl_FragColor = vec4(ran, RGB)*Color2;
}
);
