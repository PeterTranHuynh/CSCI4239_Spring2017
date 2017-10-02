/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      PTH - Final Project
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes: 
 *    OpenGL Widget
 ***************************** */
 
#include "Headers/PTHopengl.h"
#include <QtOpenGL>
#include <QMessageBox>
#include <QGLFunctions>
#include <QStringList>
#include "Headers/Cube.h"
#include "Headers/WaveOBJ.h"
#include "Headers/Teapot.h"
#include "Headers/Sphere.h"
#include "Headers/Noise.h"
#include <math.h>
#include <iostream>

#define Cos(th) cos(3.1415926/180*(th))
#define Sin(th) sin(3.1415926/180*(th))

//  Set up array indexes for program
const int VELOCITY_ARRAY=4;
const int START_ARRAY=5;
const char* Name = ",,,,Vel,Start";

/*
 *  Random numbers with range and offset
 */
static float frand(float rng,float off)
{
   return rand()*rng/RAND_MAX+off;
}

/*
 *  Initialize particles
 */
void PTHopengl::InitPart(void)
{
   //  Array Pointers
   float* vert  = Vert;
   float* color = Color;
   float* vel   = Vel;
   float* start = Start;
   //  Loop over NxN patch
   n = mode ? 15 : N;
   for (int i=0;i<n;i++)
      for (int j=0;j<n;j++)
      {
         //  Location x,y,z
         *vert++ = (i+0.5)/n-0.75;
         *vert++ = 0;
         *vert++ = (j+0.5)/n-0.75;
         //  Color r,g,b (0.5-1.0)
         *color++ = frand(0.5,0.5);
         *color++ = frand(0.5,0.5);
         *color++ = frand(0.5,0.5);
         //  Velocity
         *vel++ = frand( 1.0,3.0);
         *vel++ = frand(10.0,0.0);
         *vel++ = frand( 1.0,3.0);
         //  Launch time
         *start++ = frand(2.0,0.0);
      }
}

/*
 *  Draw particles
 */
void PTHopengl::DrawPart(void)
{
   QGLFunctions glf(QGLContext::currentContext());
   //  Set particle size
   glPointSize(mode?50:5);
   //  Point vertex location to local array Vert
   glVertexPointer(3,GL_FLOAT,0,Vert);
   //  Point color array to local array Color
   glColorPointer(3,GL_FLOAT,0,Color);
   //  Point attribute arrays to local arrays
   glf.glVertexAttribPointer(VELOCITY_ARRAY,3,GL_FLOAT,GL_FALSE,0,Vel);
   glf.glVertexAttribPointer(START_ARRAY,1,GL_FLOAT,GL_FALSE,0,Start);
   //  Enable arrays used by DrawArrays
   glEnableClientState(GL_VERTEX_ARRAY);
   glEnableClientState(GL_COLOR_ARRAY);
   glf.glEnableVertexAttribArray(VELOCITY_ARRAY);
   glf.glEnableVertexAttribArray(START_ARRAY);
   //  Set transparent large particles
   if (mode)
   {
      glEnable(GL_POINT_SPRITE);
      glTexEnvi(GL_POINT_SPRITE,GL_COORD_REPLACE,GL_TRUE);
      glEnable(GL_BLEND);
      glBlendFunc(GL_SRC_ALPHA,GL_ONE);
      glDepthMask(0);
   }
   //  Draw arrays
   glDrawArrays(GL_POINTS,0,n*n);
   //  Reset
   if (mode)
   {
      glDisable(GL_POINT_SPRITE);
      glDisable(GL_BLEND);
      glDepthMask(1);
   }
   //  Disable arrays
   glDisableClientState(GL_VERTEX_ARRAY);
   glDisableClientState(GL_COLOR_ARRAY);
   glf.glDisableVertexAttribArray(VELOCITY_ARRAY);
   glf.glDisableVertexAttribArray(START_ARRAY);
}

/*
 *  Initialize Scene
 */
void PTHopengl::InitScene(void)
{
    // Teapot
    pot = new Teapot(8);
    pot->setScale(1.2);
    pot->setTranslate(19.0, -4.8, -2.2);
    pot->setRotate(135.0,0.0,1.0,0.0);
    pot->setColor(0,1,1);
    objects.push_back(pot);

    // Objects
    try
    {
       world[0] = new WaveOBJ("torus.obj",":/Assets/");
       world[1] = new WaveOBJ("stove_top.obj",":/Assets/");
       world[2] = new WaveOBJ("oven.obj",":/Assets/");
       world[3] = new WaveOBJ("torus.obj",":/Assets/");
       world[4] = new WaveOBJ("torus.obj",":/Assets/");
       world[5] = new WaveOBJ("torus.obj",":/Assets/");
       world[6] = new WaveOBJ("plate.obj",":/Assets/");
       distort  = new WaveOBJ("cylinder.obj",":/Assets/");
    }
    catch (QString err)
    {
       Fatal("Error loading one of the objects.\n"+err);
    }

    world[0]->setColor(1,1,0);
    objects.push_back(world[0]);
    world[0]->setScale(2.0);
    world[0]->setTranslate(0.0,0.0,-0.5);

    world[1]->setColor(1,1,0);
    objects.push_back(world[1]);
    world[1]->setScale(2.0);
    world[1]->setTranslate(0.0,-3.0,-0.5);

    world[2]->setColor(1,1,0);
    objects.push_back(world[2]);
    world[2]->setScale(1.5);
    world[2]->setTranslate(0.18,-14.5,-1.4);
    world[2]->setRotate(-90.0,0.0,1.0,0.0);

    world[3]->setColor(1,1,0);
    objects.push_back(world[3]);
    world[3]->setScale(1.3);
    world[3]->setTranslate(12.0,-5.5,0.5);

    world[4]->setColor(1,1,0);
    objects.push_back(world[4]);
    world[4]->setScale(1.0);
    world[4]->setRotate(45.0,1.0,0.0,0.0);
    world[4]->setTranslate(12.0,-4.5, 1.9);

    world[5]->setColor(1,1,0);
    objects.push_back(world[5]);
    world[5]->setScale(1.0);
    world[5]->setRotate(30.0,0.0,0.0,1.0);
    world[5]->setTranslate(10.0,-4.5, 0.5);

    world[6]->setColor(1,1,0);
    objects.push_back(world[6]);
    world[6]->setScale(2.5);
    world[6]->setTranslate(12.0,-6.0, 0.5);

    // Cube for cube things
    for(int i = 0; i < 6; i++)
    {
        background[i] = new Cube();
        objects.push_back(background[i]);
    }
    background[0]->setScale(40.0,1.0,40.0);
    background[0]->setTranslate(0.0,-40.0,0.0);
    background[1]->setScale(40.0,40.0,1.0);
    background[1]->setTranslate(0.0,0.0,40.0);
    background[2]->setScale(1.0,40.0,40.0);
    background[2]->setTranslate(-40.0,0.0,0.0);
    background[3]->setScale(40.0,40.0,1.0);
    background[3]->setTranslate(0.0,0.0,-40.0);
    background[4]->setScale(1.0,40.0,40.0);
    background[4]->setTranslate(40.0,0.0,0.0);
    background[5]->setScale(40.0,1.0,40.0);
    background[5]->setTranslate(0.0,40.0,0.0);

    //distort = new Cube();
    objects.push_back(distort);
    //distort->setScale(2.0,3.0,2.0);
    distort->setScale(2.5);
    distort->setTranslate(0.0,0.5,-0.5);

    for(int i = 0; i < 5; i++)
    {
        table[i] = new Cube();
        objects.push_back(table[i]);
    }
    table[0]->setScale(7.0, 0.2, 5.0);
    table[1]->setScale(0.2, 4.0, 0.2);
    table[2]->setScale(0.2, 4.0, 0.2);
    table[3]->setScale(0.2, 4.0, 0.2);
    table[4]->setScale(0.2, 4.0, 0.2);
    table[0]->setTranslate(15.0, -6.0, -0.5);
    table[1]->setTranslate(21.5, -10.0, 4.0);
    table[2]->setTranslate(21.5, -10.0, -5.0);
    table[3]->setTranslate(8.5, -10.0, 4.0);
    table[4]->setTranslate(8.5, -10.0, -5.0);

    //setShader(1);
    //setPerspective(1);
}

/*
 *  Draws Scene
 */
void PTHopengl::DrawScene(float t)
{
    QPixmap pinkDonut(":/Assets/donut_pink.bmp");
    QPixmap sugarDonut(":/Assets/donut_sugar.bmp");
    QPixmap chocoDonut(":/Assets/donut_chocolate.bmp");
    QPixmap planeDonut(":/Assets/donut_plane.bmp");
    QPixmap stove(":/Assets/stove_metal.bmp");
    QPixmap stove2(":/Assets/brushed_metal.png");
    QPixmap tableWood(":/Assets/wood.bmp");
    QPixmap floor(":/Assets/floor.bmp");
    QPixmap wall1(":/Assets/wall1.bmp");
    QPixmap wall2(":/Assets/wall2.bmp");
    QPixmap wall3(":/Assets/wall3.bmp");
    QPixmap wall4(":/Assets/wall4.bmp");
    QPixmap poc(":/Assets/platePot.bmp");

    //  Apply shader
    shader[2]->bind();
    shader[2]->setUniformValue("time",t);
    shader[2]->setUniformValue("img",0);
    shader[2]->setUniformValue("Noise3D",1);

    //  Draw
    bindTexture(pinkDonut, GL_TEXTURE_2D);
    world[0]->display();
    bindTexture(stove, GL_TEXTURE_2D);
    world[1]->display();
    bindTexture(stove2, GL_TEXTURE_2D);
    world[2]->display();
    bindTexture(poc, GL_TEXTURE_2D);
    pot->display();
    world[6]->display();
    bindTexture(pinkDonut, GL_TEXTURE_2D);
    world[3]->display();
    bindTexture(chocoDonut, GL_TEXTURE_2D);
    world[4]->display();
    bindTexture(sugarDonut, GL_TEXTURE_2D);
    world[5]->display();
    bindTexture(tableWood, GL_TEXTURE_2D);
    table[0]->display();
    table[1]->display();
    table[2]->display();
    table[3]->display();
    table[4]->display();

    //  Release shader
    shader[2]->release();

    /* ************************** */

    //  Apply shader
    shader[3]->bind();
    shader[3]->setUniformValue("time",t);
    shader[3]->setUniformValue("img",0);
    shader[3]->setUniformValue("Noise3D",1);

    bindTexture(floor, GL_TEXTURE_2D);
    background[0]->display();
    bindTexture(wall1, GL_TEXTURE_2D);
    background[1]->display();
    bindTexture(wall2, GL_TEXTURE_2D);
    background[2]->display();
    bindTexture(wall3, GL_TEXTURE_2D);
    background[3]->display();
    bindTexture(wall4, GL_TEXTURE_2D);
    background[4]->display();
    bindTexture(floor, GL_TEXTURE_2D);
    background[5]->display();

    //  Release shader
    shader[3]->release();

    //  Apply shader Distortion for flame
    //glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthMask(GL_FALSE);
    shader[4]->bind();
    shader[4]->setUniformValue("mode",mode);
    shader[4]->setUniformValue("time",t);
    shader[4]->setUniformValue("SimpTex",1);
    shader[4]->setUniformValue("PermTex",2);
    shader[4]->setUniformValue("GradTex",3);

    distort->display();

    //  Release shader
    shader[4]->release();
    glDisable(GL_BLEND);
    //glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);

    /* ************************** */

    world[0]->setNX(0.0f);
    world[0]->setNY(1.0f);
    world[0]->setTH(1.0f);
    //distort->setNX(0.0f);
    //distort->setNY(1.0f);
    //distort->setTH(0.5f);
}

//  Constructor
PTHopengl::PTHopengl(QWidget* parent)
    : CUgl(parent,false)
{
   mode = 0;
   mouse = false;
   asp = 1;
   dim = 5;
   fov = 80;
   th = 0;
   ph = 25;
   world[0] = 0;

   //  Particles
   N = 15;
   Vert  = new float[3*N*N];
   Color = new float[3*N*N];
   Vel   = new float[3*N*N];
   Start = new float[N*N];
   InitPart();
}

//
//  Set mode
//
void PTHopengl::setMode(int m)
{
   setShader(m);
   InitPart();
}

void PTHopengl::initializeGL()
{
   glEnable(GL_DEPTH_TEST);
   // Load Texture
   /*
   tex[0] = loadImage(":/Assets/donut_pink.bmp");
   tex[1] = loadImage(":/Assets/donut_plane.bmp");
   tex[2] = loadImage(":/Assets/donut_sugar.bmp");
   tex[3] = loadImage(":/Assets/donut_chocolate.bmp");
   glActiveTexture(GL_TEXTURE0);
   //  Load first image to texture unit 0
   glBindTexture(GL_TEXTURE_2D,tex[0]);

   //  Build shader
   if (!shader.addShaderFromSourceFile(QGLShader::Vertex,":/Shaders/PTH.vert"))
      Fatal("Error compiling PTH.vert\n"+shader.log());
   if (!shader.addShaderFromSourceFile(QGLShader::Fragment,":/Shaders/PTH.frag"))
      Fatal("Error compiling PTH.frag\n"+shader.log());
   if (!shader.link())
      Fatal("Error linking shader\n"+shader.log());
   */

   QGLFunctions glf(QGLContext::currentContext());
   //  Load shaders
   addShader(":/Shaders/smoke.vert","",Name);
   addShader(":/Shaders/stove_flame.vert",":/Shaders/stove_flame.frag",Name);
   addShader(":/Shaders/object_lighting.vert", ":/Shaders/object_lighting.frag", Name);
   addShader("", ":/Shaders/background.frag", Name);
   addShader(":/Shaders/distort.vert", ":/Shaders/distort.frag", Name);

   InitScene();

   //  Load random texture
   CreateNoise3D(GL_TEXTURE1);
}

//
//  Draw the window
//
void PTHopengl::paintGL()
{
    //  Wall time (seconds)
    float t = 0.001*time.elapsed();
    zh = fmod(90*t,360);
    QPixmap flame(":/Assets/ember_particle.png");

    //  Clear screen and Z-buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glEnable(GL_BLEND);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST);

    //  Set view
    doView();

    setMode(0);
    shader[0]->bind();
    shader[0]->setUniformValue("time",t);
    shader[0]->setUniformValue("img",0);
    shader[0]->setUniformValue("Noise3D",1);

    //  Draw scene
    DrawPart();

    //  Release shader
    shader[0]->release();

    //  Draw scene
    DrawScene(t);

    //  Apply shader
    setMode(1);
    shader[mode]->bind();
    shader[mode]->setUniformValue("time",t);
    shader[mode]->setUniformValue("img",0);
    shader[mode]->setUniformValue("Noise3D",1);

    //  Draw scene
    bindTexture(flame,GL_TEXTURE_2D);
    DrawPart();

    //  Release shader
    shader[mode]->release();

    if(ph > 85) ph = 85;
    if(ph < -60) ph = -60;
    /*
    //  Draw axes
    glBegin(GL_LINES);
    glVertex3d(0,0,0);
    glVertex3d(1,0,0);
    glVertex3d(0,0,0);
    glVertex3d(0,1,0);
    glVertex3d(0,0,0);
    glVertex3d(0,0,1);
    glEnd();

    //  Label axes
    renderText(1,0,0,"X");
    renderText(0,1,0,"Y");
    renderText(0,0,1,"Z");
    */
}
