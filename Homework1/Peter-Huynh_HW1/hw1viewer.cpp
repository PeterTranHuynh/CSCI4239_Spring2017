/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW1 - NDC to RGB Shader
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes: 
 *    GUI Viewer Widget
 ***************************** */

#include <QSlider>
#include <QComboBox>
#include <QLabel>
#include <QGridLayout>
#include "hw1viewer.h"
#include "hw1opengl.h"

// Slider Constants of objects
#define MAX_POS   10
#define START_POS 0
#define STEP      1

//  Constructor
Hw1viewer::Hw1viewer()
{
   int maxP = MAX_POS;
   int sP = START_POS;
   int st = STEP;

   //  Set window title
   setWindowTitle(tr("Peter Huynh HW1 - NDC to RGB Shader"));

   //  Create new OpenGL widget
   Hw1opengl* hw1opengl = new Hw1opengl;

   //  Select shader
   QComboBox* shader = new QComboBox();
   shader->addItem("No Shader");
   shader->addItem("NDC to RGB Shader");

   //  Select projection
   QComboBox* projection = new QComboBox();
   projection->addItem("Orthogonal");
   projection->addItem("Perspective");

   //  Select object
   QComboBox* object = new QComboBox();
   object->addItem("Cube");
   object->addItem("Teapot");
   object->addItem("Object");
   
   // User control of position
   QSlider* x = new QSlider();
   x->setMinimum(-maxP);
   x->setMaximum(maxP);
   x->setSliderPosition(sP);
   x->setSingleStep(st);
   x->setOrientation(Qt::Horizontal);
   QSlider* y = new QSlider();
   y->setMinimum(-maxP);
   y->setMaximum(maxP);
   y->setSliderPosition(sP);
   y->setSingleStep(st);
   QSlider* z = new QSlider();
   z->setMinimum(-maxP);
   z->setMaximum(maxP);
   z->setSliderPosition(sP);
   z->setSingleStep(st);
   z->setOrientation(Qt::Horizontal);
   
   //  Lighting
   QCheckBox* lighting = new QCheckBox("");

   //  View angle
   QLabel* angles = new QLabel();

   //  Quit
   QPushButton* quit = new QPushButton("Quit");

   //  Set layout of child widgets
   QGridLayout* layout = new QGridLayout;
   layout->addWidget(hw1opengl,0,0,9,1);
   layout->addWidget(new QLabel("Shader"),0,1);
   layout->addWidget(shader,0,2);
   layout->addWidget(new QLabel("Projection"),1,1);
   layout->addWidget(projection,1,2);
   layout->addWidget(new QLabel("Object"),2,1);
   layout->addWidget(object,2,2);
   layout->addWidget(new QLabel("X"),3,1);
   layout->addWidget(x,3,2);
   layout->addWidget(new QLabel("Y"),4,2);
   layout->addWidget(y,4,3);
   layout->addWidget(new QLabel("Z"),5,1);
   layout->addWidget(z,5,2);
   layout->addWidget(new QLabel("Angles"),6,1);
   layout->addWidget(angles,6,2);
   layout->addWidget(quit,8,2);
   //  Manage resizing
   layout->setColumnStretch(0,100);
   layout->setColumnMinimumWidth(0,100);
   layout->setRowStretch(5,100);
   setLayout(layout);

   //  Connect valueChanged() signals to hw1opengl
   connect(shader,SIGNAL(currentIndexChanged(int))     , hw1opengl,SLOT(setShader(int)));
   connect(object,SIGNAL(currentIndexChanged(int))     , hw1opengl,SLOT(setObject(int)));
   connect(projection,SIGNAL(currentIndexChanged(int)) , hw1opengl,SLOT(setPerspective(int)));
   connect(lighting,SIGNAL(stateChanged(int))          , hw1opengl,SLOT(setLighting(int)));
   connect(x, SIGNAL(valueChanged(int))         ,  hw1opengl,SLOT(setX(int)));
   connect(y, SIGNAL(valueChanged(int))         ,  hw1opengl,SLOT(setY(int)));
   connect(z, SIGNAL(valueChanged(int))         ,  hw1opengl,SLOT(setZ(int)));
   //  Connect angles() signal to label
   connect(hw1opengl,SIGNAL(angles(QString)) , angles,SLOT(setText(QString)));
   //  Connect quit() signal to qApp::quit()
   connect(quit,SIGNAL(pressed()) , qApp,SLOT(quit()));
}
