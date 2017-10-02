/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      PTH - Final Project
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes: 
 *    OpenGL Color setting for Frag Vertices
 ***************************** */

varying vec3 View;               //  Eye position
varying vec3 Light;              //  Light direction
varying vec3 Normal;             //  Normal vector
uniform sampler2D tex;           //  Textures passed from main program


void main()
{
    //  N is the object normal
    vec3 N = normalize(Normal);
    //  L is the light direction
    vec3 L = normalize(Light);

    //  Diffuse light is cosine of light and normal vectors
    float Id = dot(L,N);

    if (Id>0.0)
    {
        //  R is the reflected light vector R = 2(L.N)N - L
        vec3 R = reflect(L,N);
        //  V is the view vector (eye vector)
        vec3 V = normalize(View);
        //  Specular is cosine of reflected and view vectors
        float Is = dot(R,V);
        //  Adjust brightness for gloss
        if (Is>0.0) Id += pow(Is,32.0);
    }

    //gl_FragColor = gl_Color; 
    //if(mode = 0) gl_FragColor = Id*texture2D(donutPinkTex,gl_TexCoord[0].st);
    //else if(mode = 1) gl_FragColor = Id*texture2D(donutPinkTex,gl_TexCoord[0].st);
    gl_FragColor = Id*texture2D(tex,gl_TexCoord[0].st);
}

