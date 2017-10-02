/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW7 - Image Processing
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes:
 *    OpenGL Widget
 ***************************** */
#include "Hw7opengl.h"

//
//  Constructor
//
Hw7opengl::Hw7opengl(QWidget* parent)
    : CUgl(parent,false)
{
   x0 = y0 = 0;
   zoom = 1;
   frac = 0;
}

//
//  Reset view
//
void Hw7opengl::reset()
{
   x0 = y0 = 0;
   zoom = 1;
   frac = 0;
   //  Request redisplay
   update();
}

//
//  Set mode
//
void Hw7opengl::setMode(int m)
{
   mode = m;
   //  Request redisplay
   update();
}

//
//  Set shader
//
void Hw7opengl::setFrac(int pct)
{
   frac = pct;
   //  Request redisplay
   update();
}

//
//  Initialize
//
void Hw7opengl::initializeGL()
{
   //  Load shader
   addShader("",":/Hw7.frag");

   //  Load first image to texture unit 0
   glActiveTexture(GL_TEXTURE0);
   loadImage(":/doge.png");
   //  Load second image to texture unit 1
   glActiveTexture(GL_TEXTURE1);
   loadImage(":/fabio.png");
}

//
//  Set projection
//
void Hw7opengl::resizeGL(int width, int height)
{
   //  Window aspect ratio
   float asp = width/(float)height;
   //  Viewport is entire window
   glViewport(0,0,width,height);
   //  Set Projection
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-asp, +asp, -1, +1, -1, +1);
   //  Set Projection
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

//
//  Draw the window
//
void Hw7opengl::paintGL()
{
   //  Enable shader
   shader[0]->bind();

   //  Set pixel increments
   shader[0]->setUniformValue("img0",0);
   shader[0]->setUniformValue("img1",1);
   shader[0]->setUniformValue("frac",(float)(frac/100.0));
   shader[0]->setUniformValue("mode",mode);

   //  Set ModelView
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glScaled(zoom,zoom,1);
   glTranslated(x0,y0,0);

   //  Draw to screen
   glClear(GL_COLOR_BUFFER_BIT);
   glBegin(GL_QUADS);
   glTexCoord2f(0,0); glVertex2f(-1,-1);
   glTexCoord2f(1,0); glVertex2f(+1,-1);
   glTexCoord2f(1,1); glVertex2f(+1,+1);
   glTexCoord2f(0,1); glVertex2f(-1,+1);
   glEnd();

   //  Done with shader
   shader[0]->release();
}

/******************************************************************/
/*************************  Mouse Events  *************************/
/******************************************************************/
//
//  Mouse moved
//
void Hw7opengl::mouseMoveEvent(QMouseEvent* e)
{
   if (mouse)
   {
      QPoint d = e->pos()-pos;      //  Change in mouse location
      x0 += d.x()/(zoom*width());   //  Translate x movement to azimuth
      y0 -= d.y()/(zoom*height());  //  Translate y movement to elevation
      pos = e->pos();               //  Remember new location
      update();                   //  Request redisplay
   }
}

//
//  Mouse wheel
//
void Hw7opengl::wheelEvent(QWheelEvent* e)
{
   //  Zoom out
   if (e->delta()<0)
      zoom *= 1.05;
   //  Zoom in
   else if (zoom>1)
      zoom /= 1.05;
   //  Request redisplay
   update();
}
