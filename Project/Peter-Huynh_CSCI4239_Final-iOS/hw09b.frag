#version 120
/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW9 - Particle Systems and Advanced Shaders
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes:
 *    Large Point Texture for Large Particle, same as Fragment shader for large particle in Ex19
 ***************************** */

uniform sampler2D img;

void main()
{
   //  Sample texture
   vec4 color = texture2D(img,gl_PointCoord.st);
   //  Set alpha as 1/3 the color
   color.a = 0.3*length(color.rgb);
   //  Blend point color with texture
   gl_FragColor = gl_Color*color;
}
