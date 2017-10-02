/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW 4 - OpenGL 3 & 4
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes:
 *    Main File to initialize program
 ***************************** */
//
//  BASE OFF OF Ex06:  OpenGL 4
//  Willem A. (Vlakkies) Schreuder
//  CSCI 4239/5239 Spring 2017
//


#include <QApplication>
#include "hw4viewer.h"

//
//  Main function
//
int main(int argc, char *argv[])
{
   //  Create the application
   QApplication app(argc,argv);

   QSurfaceFormat fmt;
   fmt.setVersion( 3, 3 );
   fmt.setProfile( QSurfaceFormat::CoreProfile );
   QSurfaceFormat::setDefaultFormat( fmt );

   //  Create and show view widget
   Hw4viewer view;
   view.show();
   //  Main loop for application
   return app.exec();
}
