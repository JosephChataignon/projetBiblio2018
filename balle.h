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
    float positionX;    //coordonnée X de la balle
    float positionY;    //coordonnée Y de la balle
    float positionZ;    //coordonnée Z de la balle
    GLdouble radius;    //rayon de la balle
    GLUquadric * m_balle = nullptr; //quadrique associée à la balle
};

#endif // BALLE_H
