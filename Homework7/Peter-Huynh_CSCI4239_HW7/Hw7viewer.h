/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW7 - Image Processing
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes:
 *    Viewer Widget Header
 ***************************** */

#ifndef HW7V_H
#define HW7V_H

#include <QWidget>
#include <QSlider>
#include <QDoubleSpinBox>
#include "Hw7opengl.h"

class Hw7viewer : public QWidget
{
Q_OBJECT
public:
    Hw7viewer();
    QLabel*  flab;
    QSlider* frac;
private slots:
    void setShader(int mode);
};

#endif
