/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW 4 - OpenGL 3 & 4
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes:
 *    OpenGL Widget Header
 ***************************** */

#ifndef HW4OPENGL_H
#define HW4OPENGL_H

#include "CUgl.h"
#include <QMatrix4x4>

class Hw4opengl : public CUgl
{
Q_OBJECT
private:
   unsigned int tex;       //  Textures
   QGLBuffer cube_buffer;  //  Vertex buffer
   QMatrix4x4       proj;  //  Projection matrix
public:
   Hw4opengl(QWidget* parent=0);                  //  Constructor
   QSize sizeHint() const {return QSize(400,400);} //  Default size of widget
protected:
   void initializeGL();  //  Initialize widget
   void paintGL();       //  Draw widget
   void doProjection();  //  Projection
};

#endif
