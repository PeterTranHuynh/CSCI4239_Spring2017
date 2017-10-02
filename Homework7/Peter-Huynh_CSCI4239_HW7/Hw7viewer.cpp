/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW7 - Image Processing
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes:
 *    Viewer Widget
 ***************************** */

#include <QComboBox>
#include <QLabel>
#include <QGridLayout>
#include "Hw7viewer.h"

//
//  Constructor
//
Hw7viewer::Hw7viewer()
{
   //  Set window title
   setWindowTitle(tr("Peter Huynh - HW7:  Image Processing"));

   //  Create new OpenGL widget
   Hw7opengl* ogl = new Hw7opengl;

   //  Select shader
   QComboBox* shader = new QComboBox();
   shader->addItem("Doge");
   shader->addItem("Fabio Doge");
   shader->addItem("Transition");
   shader->addItem("Pixelation Doge");
   shader->addItem("Pixelation Fabio");
   shader->addItem("R Swap Doge");
   shader->addItem("G Swap Doge");
   shader->addItem("B Swap Doge");
   shader->addItem("Scale Fabio");

   // Fraction
   flab = new QLabel("Fraction");
   frac = new QSlider(Qt::Horizontal);
   frac->setRange(0,100);
   flab->hide();
   frac->hide();

   //  Reset
   QPushButton* rst = new QPushButton("Reset");
   //  Quit
   QPushButton* quit = new QPushButton("Quit");

   //  Set layout of child widgets
   QGridLayout* layout = new QGridLayout;
   layout->addWidget(ogl,0,0,4,1);
   layout->addWidget(new QLabel("Shader"),0,1);
   layout->addWidget(shader,0,2);
   layout->addWidget(flab,1,1);
   layout->addWidget(frac,1,2);
   layout->addWidget(rst,3,1);
   layout->addWidget(quit,3,2);
   //  Manage resizing
   layout->setColumnStretch(0,100);
   layout->setColumnMinimumWidth(0,100);
   layout->setRowStretch(2,100);
   setLayout(layout);

   //  Connect valueChanged() signals to ogl
   connect(frac,SIGNAL(valueChanged(int))          , ogl,SLOT(setFrac(int)));
   connect(shader,SIGNAL(currentIndexChanged(int)) , ogl,SLOT(setMode(int)));
   connect(shader,SIGNAL(currentIndexChanged(int)) , this,SLOT(setShader(int)));
   //  Connect reset() and lmove() signals
   connect(rst  ,SIGNAL(pressed()),ogl,SLOT(reset()));
   //  Connect quit() signal to qApp::quit()
   connect(quit,SIGNAL(pressed()) , qApp,SLOT(quit()));
}

//
//  Shader adjust
//
void Hw7viewer::setShader(int mode)
{
   if (mode==2 || mode==3 || mode==4 || mode>=8)
   {
      flab->show();
      frac->show();
   }
   else
   {
      flab->hide();
      frac->hide();
   }
}
