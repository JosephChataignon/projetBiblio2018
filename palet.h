#ifndef PALET_H
#define PALET_H


#include <GL/glu.h>
#include <QColor>
#include <QtGui/qopengl.h>
class palet{

public:
    //constructeur
    palet(float x, float y, float z);
    //fonction d'affichage
    void displayPalet();
    //déplacement latéral du palet
    void movePalet(float x);
    //getters & setters
    float getXPalet(){return positionX;}
    void setXPalet(float x){positionX=x;}

private:
    //coordonnées du palet
    float positionX;
    float positionY;
    float positionZ;
};

#endif // PALET_H
