/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW8 - Textures for Data Storage
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes:
 *    View GUI Widget Header
 ***************************** */

#ifndef EX17V_H
#define EX17V_H

#include <QWidget>
#include <QSlider>
#include <QDoubleSpinBox>
#include "hw08opengl.h"

class Hw08viewer : public QWidget
{
Q_OBJECT
private:
   QSlider*     Lpos;
   QSlider*     Zpos;
   QPushButton* light;
   Hw08opengl*  ogl;
private slots:
   void lmove();        //  Light movement
public:
    Hw08viewer();
};

#endif
