/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      PTH - Final Project
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes: 
 *    OpenGL Color setting for Frag Vertices
 ***************************** */

uniform sampler2D tex; //  Textures passed from main program

void main()
{
    gl_FragColor = texture2D(tex,gl_TexCoord[0].st);
}

