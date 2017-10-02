/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW1 - NDC to RGB Shader
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes:
 *    Main C++ File used to initialize QT Application with Viewer
 ***************************** */

// Intensity
varying float frontColor;


vec4 phong()
{
   //  P is the vertex coordinate on body
   vec3 P = vec3(gl_ModelViewMatrix * gl_Vertex);
   //  N is the object normal at P
   vec3 N = normalize(gl_NormalMatrix * gl_Normal);
   //  Light Position for light 0
   vec3 LightPos = vec3(gl_LightSource[0].position);
   //  L is the light vector
   vec3 L = normalize(LightPos - P);
   //  R is the reflected light vector R = 2(L.N)N - L
   vec3 R = reflect(-L, N);
   //  V is the view vector (eye at the origin)
   vec3 V = normalize(-P);

   //  Diffuse light intensity is cosine of light and normal vectors
   float Id = max(dot(L,N) , 0.0);
   //  Shininess intensity is cosine of light and reflection vectors to a power
   float Is = (Id>0.0) ? pow(max(dot(R,V) , 0.0) , gl_FrontMaterial.shininess) : 0.0;

   //  Vertex color REPLACE - (NO Emission or Global Ambient), set to rgb values for length
   return //gl_FrontMaterial.emission                         // Emission color
     //+    gl_LightModel.ambient*gl_FrontMaterial.ambient    // Global ambient
         gl_FrontLightProduct[0].ambient                   // Light[0] ambient
     + Id*gl_FrontLightProduct[0].diffuse                   // Light[0] diffuse
     + Is*gl_FrontLightProduct[0].specular;                 // Light[0] specular
}

void main()
{
    //  Vertex color (using Phong lighting)
    frontColor = length(phong());

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
