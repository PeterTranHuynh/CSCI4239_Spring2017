/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW1 - NDC to RGB Shader
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes: 
 *    Main C++ File used to initialize QT Application with Viewer
 ***************************** */

#include <QApplication>
#include "hw1viewer.h"

//  Main function
int main(int argc, char *argv[])
{
   //  Create the application
   QApplication app(argc,argv);
   //  Create and show view widget
   Hw1viewer view;
   view.show();
   //  Main loop for application
   return app.exec();
}
