/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW7 - Image Processing
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes:
 *    Main File for launching QT widgets
 ***************************** */

#include <QApplication>
#include "Hw7viewer.h"

//
//  Main function
//
int main(int argc, char *argv[])
{
   //  Create the application
   QApplication app(argc,argv);
   //  Create and show view widget
   Hw7viewer view;
   view.show();
   //  Main loop for application
   return app.exec();
}
