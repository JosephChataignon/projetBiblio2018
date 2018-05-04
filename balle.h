#ifndef BALLE_H
#define BALLE_H


#include <GL/glu.h>
#include <QColor>
#include <QtGui/qopengl.h>
class balle
{
public:
    balle(float x, float y, float z, GLdouble rayon);
    void displayBalle();

    // Destructeur
    virtual ~balle();
    // Getters & setters
    float getXBalle(){return positionX;}
    float getYBalle(){return positionY;}
    GLdouble getRadius(){return radius;}
    void setRadiusBalle(GLdouble x){radius = x;}
    void setXBalle(float x){positionX = x;}
    void setYBalle(float y){positionY = y;}
private:
    float positionX;
    float positionY;
    float positionZ;
    GLdouble radius;
    GLUquadric * m_balle = nullptr;
};

#endif // BALLE_H
