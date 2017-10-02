/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW1 - NDC to RGB Shader
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes:
 *    OpenGL Color setting for Frag Vertices
 ***************************** */

//  Model coordinates and light from vertex shader
varying float frontColor;

void main()
{
    gl_FragColor = vec4(tan(gl_TexCoord[0].s)*0.5+0.5, tan(gl_TexCoord[0].t)*0.5+0.5, 1.0, 1.0) * frontColor;
}

