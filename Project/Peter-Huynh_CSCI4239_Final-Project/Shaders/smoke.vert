#version 120
/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW9 - Particle Systems and Advanced Shaders
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes:
 *    smoke Shader, derived from Ex19 Confetti Cannon - Orange Book
 ***************************** */
//  Lame fire

uniform   float time;      //  Time
attribute float Start;     //  Start time
attribute vec3  Vel;       //  Initial velocity
uniform sampler3D Noise3D; //  Noise texture

//  Perlin noise function
float noise(vec3 X)
{
   vec4 nv = texture3D(Noise3D,X);
   return nv[0]+nv[1]+nv[2]+nv[3]+0.03135;
}

void main(void)
{
   //  Particle life is mod Start time
   float t = mod(time,Start);

   //  Particle location moved above and out of view, OLD -vec4 vert = gl_Vertex;
   vec4 vert = vec4(3.0*(gl_Vertex[0]+0.1), gl_Vertex[1]+1.5, 3.0*(gl_Vertex[2]), gl_Vertex[3]);

   //  Initial position
   //vec4 vert = gl_Vertex;
   //  Noisy movement
   vec3 X = vec3(0.1*t,vert.x,vert.y)+gl_Color.rgb;
   vert.y += t;
   vert.x += noise(X)-0.01;
   vert.z += noise(X)-0.01;
   //  Contract with elevation
   //vert.x *= 1.0-0.5*vert.y;
   //vert.z *= 1.0-0.5*vert.y;


   /*  Pre-launch color black
   if (t<0.0)
      gl_FrontColor = vec4(0,0,0,1);
   else
   {
      //  Particle color, Set to Mostly Blue, OLD - gl_FrontColor = gl_Color;
      gl_FrontColor = vec4(0.5, 0.5, gl_Color.b+0.6, 1);
      //  Gravity based on time^2 and velocity of y, OLD - vert.y = 4.9*t*t;
      vert.y -= Vel.y*t*t;
   }
   //  Transform particle location
   gl_Position = gl_ModelViewProjectionMatrix*vert;
   */

   gl_FrontColor = vec4(0,0,0,1);

   //  Transform particle location
   gl_Position = gl_ModelViewProjectionMatrix*vert;
}


