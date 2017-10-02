/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW9 - Particle Systems and Advanced Shaders
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes:
 *    OpenGl Widget Header
 ***************************** */

#ifndef HW09OPENGL_H
#define HW09OPENGL_H

#include "CUgl.h"

class Hw09opengl : public CUgl
{
Q_OBJECT
private:
   int     N;         //  Particle count
   float   zh;        //  Light position
   int     n;         //  Particle count
   float*  Vert;      //  Vertices
   float*  Color;     //  Colors
   float*  Vel;       //  Velocities
   float*  Start;     //  Start time
public:
   Hw09opengl(QWidget* parent=0);                  //  Constructor
   QSize sizeHint() const {return QSize(400,400);} //  Default size of widget
public slots:
   void setMode(int m);  //  Setmode
protected:
   void initializeGL();  //  Initialize widget
   void paintGL();       //  Draw widget
private:
  void InitPart();
  void DrawPart();
};

#endif
