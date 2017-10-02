/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW 2 - Procedural Textures
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes:
 *    OpenGL Widget
 ***************************** */
#include "hw2opengl.h"
#include "Cube.h"
#include "WaveOBJ.h"
#include "Teapot.h"

//
//  Constructor
//
Hw2opengl::Hw2opengl(QWidget* parent)
    : CUgl(parent)
{
   x0 = y0 = 0;
   z0 = 1;

   //  ADDED, Based off variables from Ex01 and HW1, now in CUgl
   mode = 0;       //  Mode Variable
   mouse = false;  //  Mouse Control
   asp = 1;        //  Aspect
   dim = 3;        //  Dimensional View, Zoom
   fov = 0;        //  Field of View
   th = ph = 0;    //  Angle of View

   loaded  = false;  //  Initialization Variable
}

//
//  Set X position
//
void Hw2opengl::setX(int X)
{
   x0 = X;
   getObj()->setTranslate(x0, getObj()->getY(), getObj()->getZ());
   //  Request redisplay
   update();
}

//
//  Set Y position
//
void Hw2opengl::setY(int Y)
{
   y0 = Y;
   getObj()->setTranslate(getObj()->getX(), y0, getObj()->getZ());
   //  Request redisplay
   update();
}

//
//  Set Zoom
//
void Hw2opengl::setZoom(int Z)
{
   z0 = Z;
   getObj()->setTranslate(getObj()->getX(), getObj()->getY(), z0);
   //  Request redisplay
   update();
}

//
//  Initialize
//
void Hw2opengl::initializeGL()
{
   if(loaded) return;
   loaded = true;

   //  Load shaders
   addShader(":/hw2a.vert",":/hw2a.frag");
   addShader(":/hw2c.vert",":/hw2b.frag");
   addShader(":/hw2c.vert",":/hw2c.frag");
   addShader(":/hw2c.vert",":/hw2d.frag");

   // Load objects REMOVED Pi.png
   addObject(new Cube(":/"));
   addObject(new Teapot(8,":/",0.5,Color(0,1,1)));
   addObject(new WaveOBJ("suzanne.obj",":/",1.0));
   setObject(0);
}

//
//  Draw the window
//
void Hw2opengl::paintGL()
{
   //  Clear screen and Z-buffer
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glEnable(GL_DEPTH_TEST);

   //  Set view
   doView();

   //  Enable lighting
   doLight();

   //  Apply shader
   if (mode)
   {
      shader[mode]->bind();
      //  Dimensions
      QVector3D loc(x0,y0,1/z0);
      shader[mode]->setUniformValue("loc",loc);
      //  Time
      float t = getTime();
      shader[mode]->setUniformValue("time",t);
   }

   //  Draw scene
   doScene();

   //  Release shader
   if (mode) shader[mode]->release();
   glDisable(GL_LIGHTING);
   glDisable(GL_DEPTH_TEST);
   
   //  Emit centers to display
   emit zoom(QString::number(z0));

   //  ADDED - Emit angle as well
   emit angles(QString::number(th) + ", " + QString::number(ph));
}
