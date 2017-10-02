/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW9 - Particle Systems and Advanced Shaders
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes:
 *    Viewer Widget
 ***************************** */

#include <QComboBox>
#include <QLabel>
#include <QGridLayout>
#include "hw09viewer.h"

//
//  Constructor
//
Hw09viewer::Hw09viewer()
{
   //  Set window title
   setWindowTitle(tr("Peter Huynh - HW09: Particle System"));

   //  Create new OpenGL widget
   ogl = new Hw09opengl;

   //  Select shader
   QComboBox* shader = new QComboBox();
   shader->addItem("Particle Rain");
   shader->addItem("Colorful Comet");

   //  Select projection
   QComboBox* projection = new QComboBox();
   projection->addItem("Orthogonal");
   projection->addItem("Perspective");

   //  View angle and zoom
   QLabel* angles = new QLabel();

   //  Reset
   QPushButton* rst = new QPushButton("Reset");
   //  Quit
   QPushButton* quit = new QPushButton("Quit");

   //  Set layout of child widgets
   QGridLayout* layout = new QGridLayout;
   layout->addWidget(ogl,0,0,5,1);
   layout->addWidget(new QLabel("Shader"),0,1);
   layout->addWidget(shader,0,2);
   layout->addWidget(new QLabel("Projection"),1,1);
   layout->addWidget(projection,1,2);
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
   connect(shader,SIGNAL(currentIndexChanged(int))     , ogl,SLOT(setMode(int)));
   connect(projection,SIGNAL(currentIndexChanged(int)) , ogl,SLOT(setPerspective(int)));
   //  Connect angles() and zoom() signal to labels
   connect(ogl,SIGNAL(angles(QString)) , angles,SLOT(setText(QString)));
   //  Connect reset() and lmove() signals
   connect(rst  ,SIGNAL(pressed()),ogl,SLOT(reset()));
   //  Connect quit() signal to qApp::quit()
   connect(quit,SIGNAL(pressed()) , qApp,SLOT(quit()));
}
