/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW 2 - Procedural Textures
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes:
 *    OpenGL Widget Header
 ***************************** */

#ifndef EX03OPENGL_H
#define EX03OPENGL_H

#include "CUgl.h"

class Hw2opengl : public CUgl
{
Q_OBJECT
private:
   float x0,y0; // Model center
   float z0;    // Zoom level
   bool loaded;   // Initialization Check
public:
   Hw2opengl(QWidget* parent=0);                  // Constructor
   QSize sizeHint() const {return QSize(400,400);} // Default size of widget
public slots:
    void setX(int X);     // Set Model X position
    void setY(int Y);     // Set Model Y position
    void setZoom(int Z);  // Set Zoom level
signals:
    void zoom(QString text); // Zoom level
protected:
    void initializeGL();     // Initialize widget
    void paintGL();          // Draw widget
};

#endif
