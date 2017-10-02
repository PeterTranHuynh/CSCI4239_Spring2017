/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW8 - Textures for Data Storage
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes:
 *    Main C++ file call qt widgets
 ***************************** */

#include <QApplication>
#include "hw08viewer.h"

//
//  Main function
//
int main(int argc, char *argv[])
{
   //  Create the application
   QApplication app(argc,argv);
   //  Create and show view widget
   Hw08viewer view;
   view.show();
   //  Main loop for application
   return app.exec();
}
