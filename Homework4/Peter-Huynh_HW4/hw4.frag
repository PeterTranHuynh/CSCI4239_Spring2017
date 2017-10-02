#version 400 core
/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW 4 - OpenGL 3 & 4
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes:
 *    Fragment Shader
 ***************************** */
precision highp int;
precision highp float;
precision highp vec2;
precision highp vec3;
precision highp vec4;

//  Input from previous shader
in vec3 FrontColor;
//  ADDED: TAKES IN TEXTURE COORDINATE AS WELL
in vec2 TextureCoord;

//  Fragment color
layout (location=0) out vec4 Fragcolor;

//  ADDED Texture
uniform sampler2D tex;

void main()
{
   // ADDED: Multiple of texture2D
   Fragcolor = vec4(FrontColor,1.0) * texture2D(tex, TextureCoord);
}
