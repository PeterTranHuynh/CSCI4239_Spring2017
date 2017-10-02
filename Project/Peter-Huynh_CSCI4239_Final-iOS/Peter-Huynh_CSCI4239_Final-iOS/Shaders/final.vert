const char* SimpleVertexShader = STRINGIFY(

attribute vec4 XYZW;
attribute vec4 RGBA;
varying vec4 Color;
varying vec4 Color2;
varying vec3 RGB;
varying vec2 XY;
uniform mat4 Projection;
uniform mat4 Modelview;

void main(void)
{
    Color = RGBA;
    gl_Position = Projection * Modelview * XYZW;
    
    // Grabbing XY
    XY[0] = XYZW[0]; XY[1] = XYZW[1];
    // Grabbing RGB
    RGB[0] = Color[0]; RGB[1] = Color[1]; RGB[2] = Color[2];
    // Adds Gradient, col2 = opacity
    Color2 = 0.5 * gl_Position;
    // Intensity
    Color2[0]+=0.5; Color2[1]+=0.5; Color2[2]+=0.5; Color2[3]+=0.5;
}
);
