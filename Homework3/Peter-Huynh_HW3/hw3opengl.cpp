/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW 3 - Performance
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes:
 *    OpenGL Widget
 ***************************** */
#include "hw3opengl.h"
#include "Cube.h"
#include "WaveOBJ.h"
#include "Teapot.h"

//
//  Constructor
//
Hw3opengl::Hw3opengl(QWidget* parent)
    : CUgl(parent)
{
   t0 = frame = 0;
}

//
//  Initialize
//
void Hw3opengl::initializeGL()
{
   //  Load shaders
   addShader("",":/hw3a.frag");
   addShader(":/hw3b.vert",":/hw3b.frag");
   addShader(":/hw3c.vert",":/hw3c.frag");
   addShader(":/hw3d.vert",":/hw3d.frag");
   addShader(":/hw3e.vert",":/hw3e.frag");
   addShader(":/hw2a.vert",":/hw2a.frag");
   addShader(":/hw2c.vert",":/hw2b.frag");
   addShader(":/hw2c.vert",":/hw2c.frag");
   addShader(":/hw2c.vert",":/hw2d.frag");

   //  Load objects
   addObject(new Cube(":/crate.png"));
   addObject(new Teapot(8,":/pi.png",0.5));
   addObject(new WaveOBJ("cruiser.obj",":/"));
   addObject(new WaveOBJ("suzanne.obj",":/"));
   setObject(0);

   //  Set max frame rate
   maxFPS(0);
}

//
//  Draw the window
//
void Hw3opengl::paintGL()
{
   //  Clear screen and Z-buffer
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glEnable(GL_DEPTH_TEST);

   //  Set view
   doView();

   //  Apply lighting
   doLight();

   //  Apply shader
   if (mode) shader[mode]->bind();

   //  Draw scene
   doScene();

   //  Release shader
   if (mode) shader[mode]->release();
   glDisable(GL_LIGHTING);
   glDisable(GL_DEPTH_TEST);

   //  Frame counter
   frame++;
   int t = time.elapsed()/1000;
   if (t>t0)
   {
      emit fps(QString::number(frame));
      t0 = t;
      frame = 0;
   }
}
