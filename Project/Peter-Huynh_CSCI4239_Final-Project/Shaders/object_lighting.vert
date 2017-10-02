/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      PTH - Final Project
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes: 
 *    Main C++ File used to initialize QT Application with Viewer
 ***************************** */

varying vec3 View;     //  Eye position
varying vec3 Light;    //  Light direction
varying vec3 Normal;   //  Normal vector

void main()
{
    //
    //  Lighting values needed by fragment shader
    //
    //  Vertex location in modelview coordinates
    vec3 P = vec3(gl_ModelViewMatrix * gl_Vertex);
    //  Light direction
    Light = vec3(gl_LightSource[0].position.x+0.2, gl_LightSource[0].position.y, gl_LightSource[0].position.z-0.2);
    //  Normal
    Normal = gl_NormalMatrix * gl_Normal;
    //  Eye position
    View  = -P;

    //  Texture coordinate for fragment shader
    gl_TexCoord[0] = gl_MultiTexCoord0;

    //  Set vertex position
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}
