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
    gl_FragColor = gl_Color * frontColor;
}

