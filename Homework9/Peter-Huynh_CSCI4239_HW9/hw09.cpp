/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW9 - Particle Systems and Advanced Shaders
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes:
 *    Main C++ file used to call widgets and run program
 ***************************** */

#include <QApplication>
#include "hw09viewer.h"

//
//  Main function
//
int main(int argc, char *argv[])
{
   //  Create the application
   QApplication app(argc,argv);
   //  Create and show view widget
   Hw09viewer view;
   view.show();
   //  Main loop for application
   return app.exec();
}
