#ifndef PLANET_H
#define PLANET_H
#include <QtOpenGL>
#include <QGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QDebug>
#include <QOpenGLFunctions_3_3_Compatibility>
#include <QImage>
#include <qgl.h>
#include <gl/GLU.h>

class Planet:public QOpenGLWidget,protected QOpenGLFunctions_3_3_Compatibility{
    Q_OBJECT
public:
    explicit Planet(QWidget *parent=nullptr);
    ~Planet();
    void PaintSun();
    void PaintMercury();
    void PaintVenus();
    void PaintEarth();
    void PaintMars();
    void PaintJupiter();
    void PaintSaturn();
    void PaintUranus();
    void PaintNeptune(); 
protected:
    void initializeGL()  ;
    void paintGL() ;
    void resizeGL(int w,int h)  ;
    float rsun=0.0f;
    float rMer=0.1f;
    float rVen=0.16f;
    float rEar=0.25f;
    float rMar=0.36f;
    float rJup=0.50f;
    float rSat=0.64f;
    float rUra=0.79f;
    float rNep=0.93f;

    float tsun=0.0;
    float tMer=0.0;
    float tVen=0.0;
    float tEar=0.0;
    float tMar=0.0;
    float tJup=0.0;
    float tSat=0.0;
    float tUra=0.0;
    float tNep=0.0;

    float osun=0.0;
    float oMer=0.0;
    float oVen=0.0;
    float oEar=0.0;
    float oMar=0.0;
    float oJup=0.0;
    float oSat=0.0;
    float oUra=0.0;
    float oNep=0.0;
    void loadGLTextures();
    GLuint texture[10];
private:
    int n=3600;
    float PI=3.1415926f;
    float R=0.25f;
};

#endif // PLANET_H
