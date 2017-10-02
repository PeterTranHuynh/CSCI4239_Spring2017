/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW 2 - Procedural Textures
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes:
 *    Shader 1, Custom RGB Strip Pattern
 ***************************** */

//  Model coordinates and light from vertex shader
varying float frontColor;

// Given in main application
uniform float time;

void main()
{
  // Texture coordinates multiplied and into trig functions!
  float a = tan(gl_TexCoord[0].q*5.0*time)+0.5;
  float b = sin(gl_TexCoord[0].r*5.0*time)+0.5;
  float c = cos(gl_TexCoord[0].s*5.0*time)+0.5;
  float d = (cos(gl_TexCoord[0].t*5.0*time)+0.5)/(sin(gl_TexCoord[0].r*5.0*time)+0.5);

  //  Create color for fragment
  gl_FragColor = vec4(a, b, c, d) * frontColor;
}
