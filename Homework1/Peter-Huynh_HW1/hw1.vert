/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW1 - NDC to RGB Shader
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes: 
 *    Main C++ File used to initialize QT Application with Viewer
 ***************************** */

void main()
{
    //  Vertex coords
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
   
    /*
     *  Get pixel location in mapping vector
     *  Mapping of NDC (-1 to 1) into RGB format (0 to 1):
     *  -(1 to 1) -> (0 to 2)*HALF for RGB
     *  W for depth
     */
    gl_FrontColor = (((gl_Position/gl_Position.w)+1.0 ) * 0.5);
}
