/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      PTH - Final Project
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes: 
 *    Main C++ File used to initialize QT Application with Viewer
 ***************************** */

#include <QApplication>
#include "Headers/PTHviewer.h"

//  Main function
int main(int argc, char *argv[])
{
   //  Create the application
   QApplication app(argc,argv);
   //  Create and show view widget
   PTHviewer view;
   //view.show();
   view.showFullScreen();
   //  Main loop for application
   return app.exec();
}
