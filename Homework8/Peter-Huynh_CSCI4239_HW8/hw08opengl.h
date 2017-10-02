/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW8 - Textures for Data Storage
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes:
 *    OpenGL Widget Header
 ***************************** */

#ifndef EX17OPENGL_H
#define EX17OPENGL_H

#include "CUgl.h"

class Hw08opengl : public CUgl
{
Q_OBJECT
private:
   int mode;  // Noise type
public:
   Hw08opengl(QWidget* parent=0);                  //  Constructor
   QSize sizeHint() const {return QSize(400,400);} //  Default size of widget
public slots:
   void setMode(int m); // Set noise type
protected:
   void initializeGL(); //  Initialize widget
   void paintGL();      //  Draw widget
};

#endif
