/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW 4 - OpenGL 3 & 4
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes:
 *    Viewer Widget Header
 ***************************** */
#ifndef HW4V_H
#define HW4V_H

#include <QWidget>
#include <QSlider>
#include <QDoubleSpinBox>
#include "hw4opengl.h"

class Hw4viewer : public QWidget
{
Q_OBJECT
private:
   QSlider*     Lpos;
   QSlider*     Zpos;
   QPushButton* light;
   Hw4opengl*  ogl;
private slots:
   void lmove();        //  Light movement
public:
    Hw4viewer();
};

#endif
