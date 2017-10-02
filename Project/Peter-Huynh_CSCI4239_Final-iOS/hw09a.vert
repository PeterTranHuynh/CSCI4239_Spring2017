/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW9 - Particle Systems and Advanced Shaders
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes:
 *    Rain Vertex Shader, derived from Ex19 Confetti Cannon - Orange Book
 ***************************** */

uniform   float time;  //  Time
attribute float Start; //  Start time
attribute vec3  Vel;   //  Velocity

void main(void)
{
   //  Particle location moved above and out of view, OLD -vec4 vert = gl_Vertex;
   vec4 vert = vec4(10.0*(gl_Vertex[0]+0.25), gl_Vertex[1]+7.0, 10.0*(gl_Vertex[2]+0.25), gl_Vertex[3]);

   //  Time offset mod 5
   float t = mod(time,5.0)-Start;

   //  Pre-launch color black
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
}
