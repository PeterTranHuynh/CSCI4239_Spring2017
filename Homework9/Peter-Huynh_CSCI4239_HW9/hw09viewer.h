/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW9 - Particle Systems and Advanced Shaders
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes:
 *    Viewer Widget Header
 ***************************** */

#ifndef HW09V_H
#define HW09V_H

#include <QWidget>
#include <QSlider>
#include <QDoubleSpinBox>
#include "hw09opengl.h"

class Hw09viewer : public QWidget
{
Q_OBJECT
private:
   Hw09opengl*  ogl;
public:
    Hw09viewer();
};

#endif
