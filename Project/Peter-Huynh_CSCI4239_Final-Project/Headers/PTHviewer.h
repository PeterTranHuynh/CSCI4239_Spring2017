/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      PTH - Final Project
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes: 
 *    GUI Viewer Header
 ***************************** */

#ifndef PTHV_H
#define PTHV_H

#include <QWidget>
#include <QSlider>
#include <QDoubleSpinBox>
#include "Headers/PTHopengl.h"

class PTHviewer : public QWidget
{
Q_OBJECT
private:
   PTHopengl*  ogl;
public:
    PTHviewer();
};

#endif
