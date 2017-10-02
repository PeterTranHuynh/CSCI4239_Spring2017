/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW 3 - Performance
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes:
 *    Viewer Widget Header
 ***************************** */

#ifndef HW3V_H
#define HW3V_H

#include <QWidget>
#include <QSlider>
#include <QDoubleSpinBox>
#include "hw3opengl.h"

class Hw3viewer : public QWidget
{
Q_OBJECT
private:
   QSlider*     Lpos;
   QSlider*     Zpos;
   QPushButton* light;
   Hw3opengl*  ogl;
   
   //  ADDED: Pixels and Resolution for data collection
   QLabel*      pixels;
   QLabel*      resolution;
private slots:
   void lmove();        //  Light movement
public:
    Hw3viewer();
};

#endif
