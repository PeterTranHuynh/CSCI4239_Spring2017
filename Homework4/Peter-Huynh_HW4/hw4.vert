#version 400 core
/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW 4 - OpenGL 3 & 4
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes:
 *    Vertex Shader
 ***************************** */

//  Transformation matrices
uniform mat4 ModelViewMatrix;
uniform mat4 ProjectionMatrix;
  //  ADDED: EXTRA MATRIX VERSIONS
uniform mat3 NormalMatrix;
uniform mat4 ViewMatrix;

//  ADDED: LIGHT VECTOR VARS
uniform vec3 Ambient;
uniform vec3 Diffuse;
uniform vec3 Specular;
uniform vec4 Position;

//  Vertex attributes (input)
layout(location = 0) in vec4 Vertex;
layout(location = 1) in vec3 Color;
  //  ADDED MORE LAYOUTS
layout(location = 2) in vec3 Normal;
layout(location = 3) in vec2 Texture;

//  Output to next shader
out vec3 FrontColor;
out vec2 TextureCoord;

void main()
{

    //  ADDED: LIGHT TAKEN FROM HW2-3
    vec3 P = vec3(ModelViewMatrix * Vertex);
    vec3 N = normalize(NormalMatrix * Normal);
    vec3 L = normalize(vec3(ViewMatrix*Position) - P);
    vec3 color = Ambient;

    // I Matrix created from dot product of L and N
    float Identity = dot(L, N);
    if (Identity > 0.0)
    {
       color += Identity * Diffuse;
       vec3 R = reflect(-L, N);
       vec3 V = normalize(-P);
       float Is = dot(R,V);
       if (Is>0.0) color += pow(Is,32.0)*Specular;
    }

   //  Pass colors to fragment shader (will be interpolated)
   FrontColor = color*Color; // Used to be Color
   
   //  ADDED: TEXTURE COORDS FOR FRAG SHADER
   TextureCoord = Texture;
   
   //  Set transformed vertex location
   gl_Position =  ProjectionMatrix * ModelViewMatrix * Vertex;
}
