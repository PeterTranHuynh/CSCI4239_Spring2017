//
//  CU OpenGL Widget
//

#ifndef CUGL_H
#define CUGL_H

#include <QtOpenGL>
#include <QString>
#include <QVector>
#include "Object.h"

class CUgl : public QGLWidget
{
Q_OBJECT
private:
   QTimer           timer;    // Timer for animations
   QElapsedTimer    time;     // Track elapsed time
   float            La,Ld,Ls; // Light intensity
   float            Lr;       // Light radius
   float            zh;       // Light angle
   float            ylight;   // Light elevation
   bool             move;     // Moving light
   int              obj;      // Selected Object
   QVector<Object*> objects;  // Objects
protected:  //  Mouse movement
   bool             mouse;    // Mouse pressed
   QPoint           pos;      // Mouse position
protected:  //  Projection
   int              fov;      // Field of view
   float            dim;      // Display size
   float            asp;      // Sceen aspect ratio
   int              th,ph;    // Display angles
protected:  //  Shaders
   int                        mode;   // Selected shader
   QVector<QGLShaderProgram*> shader; // Shaders
public:
   CUgl(QWidget* parent=0,bool fixed=true);        // Constructor
   QSize sizeHint() const {return QSize(400,400);} // Default size of widget
public slots:
   Object* getObj();
   void reset();
   void setPerspective(int on);                     // Set perspective
   void setShader(int sel);                         // Set shader
   void addShader(QString vert,QString frag);       // Add shader
   void setObject(int type);                        // Set displayed object
   void addObject(Object* obj);                     // Add object
   void doScene();                                  // Draw scene
   void setLightMove(bool on);                      // Set light animation
   void setLightAngle(int th);                      // Set light angle
   void setLightElevation(int pct);                 // Set light elevation (percent)
   void setLightIntensity(float a,float d,float s); // Set light intensity
protected:
   void initializeGL();                             // Initialization
   void resizeGL(int,int);                          // Window resize
   void mousePressEvent(QMouseEvent*);              // Mouse pressed
   void mouseReleaseEvent(QMouseEvent*);            // Mouse released
   void mouseMoveEvent(QMouseEvent*);               // Mouse moved
   void wheelEvent(QWheelEvent*);                   // Mouse wheel
   void Fatal(QString message);                     // Error handler
   void doView();                                   // Apply modelview
   QVector3D doLight();                             // Enable light
   void doProjection();                             // Update projection
   float getTime() {return 0.001*time.elapsed();}   // Elapsed time in seconds
   unsigned int loadImage(const QString file);      // Method to load texture
private slots:
   void tick();                                     // Method to capture timer ticks
signals:
   void light(int angle);                           // Signal for light angle
   void angles(QString text);                       // Signal for view angles
};

#endif
