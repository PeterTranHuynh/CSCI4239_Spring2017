/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      PTH - Final Project
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes: 
 *    GUI Viewer Widget
 ***************************** */

#include <QSlider>
#include <QComboBox>
#include <QLabel>
#include <QGridLayout>
#include "Headers/PTHviewer.h"
#include "Headers/PTHopengl.h"

//  Constructor
PTHviewer::PTHviewer()
{
   //  Set window title
   setWindowTitle(tr("Peter Huynh PTH - Final Project"));

   //  Create new OpenGL widget
   ogl = new PTHopengl;

   //  Select shader
   /*
   QComboBox* shader = new QComboBox();
   shader->addItem("1");
   shader->addItem("2");
   shader->addItem("3");
   shader->addItem("4");
   shader->addItem("5");
   shader->addItem("6");
   */

   //  View angle and zoom
   QLabel* angles = new QLabel();

   //  Reset
   QPushButton* rst = new QPushButton("Reset");
   //  Quit
   QPushButton* quit = new QPushButton("Quit");

   //  Set layout of child widgets
   QGridLayout* layout = new QGridLayout;
   layout->addWidget(ogl,0,0,5,1);
   //layout->addWidget(new QLabel("Shader"),0,1);
   //layout->addWidget(shader,0,2);
   layout->addWidget(new QLabel("Angles"),2,1);
   layout->addWidget(angles,2,2);
   layout->addWidget(rst,4,1);
   layout->addWidget(quit,4,2);
   //  Manage resizing
   layout->setColumnStretch(0,100);
   layout->setColumnMinimumWidth(0,100);
   layout->setRowStretch(3,100);
   setLayout(layout);

   //  Connect valueChanged() signals to ogl
   //connect(shader,SIGNAL(currentIndexChanged(int))     , ogl,SLOT(setMode(int)));
   //  Connect angles() and zoom() signal to labels
   connect(ogl,SIGNAL(angles(QString)) , angles,SLOT(setText(QString)));
   //  Connect reset() and lmove() signals
   connect(rst  ,SIGNAL(pressed()),ogl,SLOT(reset()));
   //  Connect quit() signal to qApp::quit()
   connect(quit,SIGNAL(pressed()) , qApp,SLOT(quit()));
}

