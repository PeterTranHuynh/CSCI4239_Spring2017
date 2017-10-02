/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW 3 - Performance
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes:
 *    Main C++ File used to initialize QT Application with Viewer
 ***************************** */

#include <QApplication>
#include "hw3viewer.h"

//
//  Main function
//
int main(int argc, char *argv[])
{
   //  Create the application
   QApplication app(argc,argv);
   //  Create and show view widget
   Hw3viewer view;
   view.show();
   //  Main loop for application
   return app.exec();
}
