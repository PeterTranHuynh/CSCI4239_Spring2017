/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW 2 - Procedural Textures
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes:
 *    Window Display Widget Header
 ***************************** */

#ifndef EX03V_H
#define EX03V_H

#include <QWidget>
#include <QSlider>
#include <QDoubleSpinBox>
#include "hw2opengl.h"

class Hw2viewer : public QWidget
{
Q_OBJECT
private:
   //QDoubleSpinBox* Xpos;
   //QDoubleSpinBox* Ypos;
   QSlider*        Xpos;
   QSlider*        Ypos;
   QSlider*        Zpos;
   QPushButton*    light;
   Hw2opengl*     ogl;
private slots:
   void reset();        //  Reset angles
   void lmove();        //  Pause/animate light
   void izoom(int iz);  //  Zoom level (percent)
public:
    Hw2viewer();
};

#endif
