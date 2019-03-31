#include "planet.h"
#include <QWidget>
#define PI 3.1415926

Planet::Planet(QWidget *parent):QOpenGLWidget (parent)
{

}

Planet::~Planet()
{

}

void Planet::initializeGL()
{
    initializeOpenGLFunctions();
    QImage tex[9],buf;
        QString Picture[9]={
            "E:/QWidget/planet/sun.png","E:/QWidget/planet/Mercury.png","E:/QWidget/planet/Venus.png",
            "E:/QWidget/planet/earth.png","E:/QWidget/planet/Mars.png","E:/QWidget/planet/Jupiter.png",
           "E:/QWidget/planet/Saturn.png","E:/QWidget/planet/Uranus.png","E:/QWidget/planet/Neptune.png"
        };
        for(int i=0;i<9;i++){
            buf.load(Picture[i]);
            tex[i]=QGLWidget::convertToGLFormat(buf);
            glGenTextures(1,&texture[i]);
            glBindTexture(GL_TEXTURE_2D,texture[i]);
            glTexImage2D( GL_TEXTURE_2D, 0, 3, tex[i].width(), tex[i].height(), 0,
                          GL_RGBA, GL_UNSIGNED_BYTE, tex[i].bits() );
            glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
            glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        }
    loadGLTextures();
    glEnable( GL_TEXTURE_2D );
   /* glShadeModel( GL_SMOOTH );
      glClearColor( 0.0, 0.0, 0.0, 0.5 );
      glClearDepth( 1.0 );
      glEnable( GL_DEPTH_TEST );
      glDepthFunc( GL_LEQUAL );
      glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );*/
}
void Planet::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);    
}
void Planet::paintGL()
{
    update();
    glEnable(GL_LINE_STIPPLE);//启动虚线模式，使用glDisable(GL_LINE_STIPPLE)可以关闭
    glLineStipple(1, 0x0F0F);//设置虚线的样式
    glLineWidth(1.0f);//指定线宽

    glColor3f(0.5f,0.5f,0.5f);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<n; ++i)
        glVertex2f(rMer*cos(2*PI/n*i), rMer*sin(2*PI/n*i));
    for(int i=0; i<n; ++i)
        glVertex2f(rVen*cos(2*PI/n*i), rVen*sin(2*PI/n*i));
    for(int i=0; i<n; ++i)
        glVertex2f(rEar*cos(2*PI/n*i), rEar*sin(2*PI/n*i));
    for(int i=0; i<n; ++i)
        glVertex2f(rMar*cos(2*PI/n*i), rMar*sin(2*PI/n*i));
    for(int i=0; i<n; ++i)
        glVertex2f(rJup*cos(2*PI/n*i), rJup*sin(2*PI/n*i));
    for(int i=0; i<n; ++i)
        glVertex2f(rSat*cos(2*PI/n*i), rSat*sin(2*PI/n*i));
    for(int i=0; i<n; ++i)
        glVertex2f(rUra*cos(2*PI/n*i), rUra*sin(2*PI/n*i));
    for(int i=0; i<n; ++i)
        glVertex2f(rNep*cos(2*PI/n*i), rNep*sin(2*PI/n*i));
    glEnd();
    PaintSun();    
    PaintMercury();
    PaintVenus();
    PaintEarth();
    PaintMars();
    PaintJupiter();
    PaintSaturn();
    PaintUranus();
    PaintNeptune();
}

void Planet::PaintSun()
{
   // update();
    glClearDepth(1.0);
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    glLoadIdentity();
    loadGLTextures();
    glTranslated(0.0,0.0,0.0);
    glColor3f(1.0,1.0,1.0);
    glRotatef( rsun,  0.0,  1.0,  0.0);
    glScalef(0.03,0.03,0.03);
    GLUquadricObj *qobj=gluNewQuadric();
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glRotatef(90,1,0,0);
    glColor4f(1,1,1,1);
    gluQuadricTexture(qobj,GL_TRUE);
    gluSphere(qobj,3,40,40);
    glPopMatrix();
    rsun += 0.05;
}

void Planet::loadGLTextures()
{
}

void Planet::PaintMercury()
{
    update();
    glPushMatrix();
    glLoadIdentity();
    loadGLTextures();
    glColor3f(1.0,1.0,1.0);
    glTranslated(rMer*cos(2*PI/n*tMer), rMer*sin(2*PI/n*tMer),0);
    glRotatef( oMer,  0.0,  1.0,  0.0);
    glScalef(0.006,0.006,0.006);
    GLUquadricObj *qobj=gluNewQuadric();
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glRotatef(90,1,0,0);
    glColor4f(1,1,1,1);
    gluQuadricTexture(qobj,GL_TRUE);
    gluSphere(qobj,3,40,40);
    glPopMatrix();
    oMer += 0.017;
    tMer += 31.4;
}
void Planet::PaintVenus()
{
    update();
    glPushMatrix();
    glLoadIdentity();
    loadGLTextures();
    glColor3f(1.0,1.0,1.0);
    glTranslated(rVen*cos(2*PI/n*tVen), rVen*sin(2*PI/n*tVen),0);
    glRotatef( oVen,  0.0,  1.0,  0.0);
    glScalef(0.008,0.008,0.008);
    GLUquadricObj *qobj=gluNewQuadric();
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[2]);
    glRotatef(90,1,0,0);
    glColor4f(1,1,1,1);
    gluQuadricTexture(qobj,GL_TRUE);
    gluSphere(qobj,2,30,30);
    glPopMatrix();
    oVen+=0.005;
    tVen += 12.2;
}
void Planet::PaintEarth()
{
    glLoadIdentity();
    loadGLTextures();
    glPushMatrix();
    glTranslated(rEar*cos(2*PI/n*tEar), rEar*sin(2*PI/n*tEar),0);
    glRotatef( oEar , 0.0,  1.0,  0.0);
    glScalef(0.01,0.01,0.01);
    GLUquadricObj *qobj=gluNewQuadric();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[3]);
    glRotatef(90,1,0,0);
    glColor4f(1,1,1,1);
    gluQuadricTexture(qobj,GL_TRUE);
    gluSphere(qobj,2,30,30);
    glPopMatrix();
    oEar += 1;
    tEar+=7.5;
}
void Planet::PaintMars()
{
    update();
    glPushMatrix();
    glLoadIdentity();
    loadGLTextures();
    glTranslated(rMar*cos(2*PI/n*tMar), rMar*sin(2*PI/n*tMar),0);
    glRotatef( oMar,  0.0,  1.0,  0.0);
    glScalef(0.01,0.01,0.01);
    GLUquadricObj *qobj=gluNewQuadric();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[4]);
    glRotatef(90,1,0,0);
    glColor4f(1,1,1,1);
    gluQuadricTexture(qobj,GL_TRUE);
    gluSphere(qobj,2,30,30);
    glPopMatrix();
    glEnd();
    oMar += 1;
    tMar += 3.99;
}

void Planet::PaintJupiter()
{
    update();
    glPushMatrix();
    glLoadIdentity();
    loadGLTextures();
    glTranslated(rJup*cos(2*PI/n*tJup), rJup*sin(2*PI/n*tJup),0);
    glRotatef( oJup,  0.0,  1.0,  0.0);
    glScalef(0.03,0.03,0.03);
    GLUquadricObj *qobj=gluNewQuadric();
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[5]);
    glRotatef(90,1,0,0);
    glColor4f(1,1,1,1);
    gluQuadricTexture(qobj,GL_TRUE);
    gluSphere(qobj,2,30,30);
    glPopMatrix();
    oJup += 2.5;
    tJup += 0.63;
}
void Planet::PaintSaturn()
{
    update();
    glPushMatrix();
    glLoadIdentity();
    loadGLTextures();
    glTranslated(rSat*cos(2*PI/n*tSat), rSat*sin(2*PI/n*tSat),0);
    glRotatef( oSat,  0.0,  1.0,  0.0);
    glScalef(0.025,0.025,0.025);
    GLUquadricObj *qobj=gluNewQuadric();
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[6]);
    glRotatef(90,1,0,0);
    glColor4f(1,1,1,1);
    gluQuadricTexture(qobj,GL_TRUE);
    gluSphere(qobj,2,30,30);
    glPopMatrix();
    oSat += 2.5;
    tSat+=0.254;
}
void Planet::PaintUranus()
{
    update();
    glPushMatrix();
    glLoadIdentity();
    loadGLTextures();
    glTranslated(rUra*cos(2*PI/n*tUra), rUra*sin(2*PI/n*tUra),0);
    glRotatef( oUra ,  0.0,  1.0,  0.0);
    glScalef(0.02,0.02,0.02);
    GLUquadricObj *qobj=gluNewQuadric();
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[7]);
    glRotatef(90,1,0,0);
    glColor4f(1,1,1,1);
    gluQuadricTexture(qobj,GL_TRUE);
    gluSphere(qobj,2,30,30);
    glPopMatrix();
    oUra += 2.3;
    tUra += 0.089;
}
void Planet::PaintNeptune()
{
    update();
    glPushMatrix();
    glLoadIdentity();
    loadGLTextures();
    glTranslated(rNep*cos(2*PI/n*tNep), rNep*sin(2*PI/n*tNep),0);
    glRotatef( oNep,  0.0,  1.0,  0.0);
    glScalef(0.02,0.02,0.02);
    GLUquadricObj *qobj=gluNewQuadric();
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    glRotatef(90,1,0,0);
    gluQuadricTexture(qobj,GL_TRUE);
    gluSphere(qobj,2,30,30);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    oNep += 2.2;
    tNep += 0.045;
}
