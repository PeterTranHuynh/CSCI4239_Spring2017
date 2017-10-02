/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW 3 - Performance
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes:
 *    OpenGL Widget Header
 ***************************** */
#ifndef HW3OPENGL_H
#define HW3OPENGL_H

#include "CUgl.h"

class Hw3opengl : public CUgl
{
Q_OBJECT
private:
   int frame; //  Frame counter
   int t0;    //  Frame seconds
public:
   Hw3opengl(QWidget* parent=0);                   // Constructor
   QSize sizeHint() const {return QSize(400,400);}  // Default size of widget
protected:
    void initializeGL();  // Initialize widget
    void paintGL();       // Draw widget
signals:
    void fps(QString);    // Frames per second
};

#endif
