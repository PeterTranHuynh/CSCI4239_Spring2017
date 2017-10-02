/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW7 - Image Processing
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes:
 *    OpenGL Widget Header
 ***************************** */

#ifndef HW7OPENGL_H
#define HW7OPENGL_H

#include "CUgl.h"

class Hw7opengl : public CUgl
{
Q_OBJECT
private:
   float   x0,y0;        //  Image center
   float   zoom;         //  Zoom
   int     w,h;          //  Image size
   int     frac;         //  Image fraction
public:
   Hw7opengl(QWidget* parent=0);                   //  Constructor
   QSize sizeHint() const {return QSize(400,400);} //  Default size of widget
public slots:
   void setFrac(int pct);                 //  Slot to set fraction
   void setMode(int mode);                //  Slot to set mode
   void reset();                          //  Reset view
protected:
   void initializeGL();                   //  Initialize widget
   void resizeGL(int width, int height);  //  Resize widget
   void paintGL();                        //  Draw widget
   void mouseMoveEvent(QMouseEvent*);     //  Mouse moved
   void wheelEvent(QWheelEvent*);         //  Mouse wheel
};

#endif
