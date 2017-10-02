/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      PTH - Final Project
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes: 
 *    OpenGL Widget Header
 ***************************** */

#ifndef PTHOPENGL_H
#define PTHOPENGL_H

#include "CUgl.h"
#include <QtOpenGL>
#include <QString>
#include <QVector>
#include <QTimer>
#include <QElapsedTimer>
#include "Object.h"
#include "WaveOBJ.h"
#include "Cube.h"
#include "Teapot.h"

//#define NUMBER_OF_TEXTURES 4
#define NUMBER_OF_OBJECTS  7

class PTHopengl : public CUgl
{
Q_OBJECT
private:
   // Particles
   int     N;         //  Particle count
   float   zh;        //  Light position
   int     n;         //  Particle count
   float*  Vert;      //  Vertices
   float*  Color;     //  Colors
   float*  Vel;       //  Velocities
   float*  Start;     //  Start time
   // Imported Objects & Drawn things
   //unsigned int tex[NUMBER_OF_TEXTURES];  //  Textures
   WaveOBJ* world[NUMBER_OF_OBJECTS];     //  WaveOBJs
   Cube* background[6];                   //  Skybox
   WaveOBJ* distort;
   Cube* table[5];
   Teapot* pot;
public:
   PTHopengl(QWidget* parent=0);          //  Constructor
   QSize sizeHint() const {return QSize(1000,1000);} //  Default size of widget
public slots:
   void setMode(int m);                   //  Setmode
protected:
   void initializeGL();                   //  Initialize widget
   void paintGL();                        //  Draw widget
private:
   void InitPart();
   void DrawPart();
   void InitScene();
   void DrawScene(float t);
};

#endif
