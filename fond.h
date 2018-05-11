#ifndef FOND_H
#define FOND_H

#include <GL/glu.h>
#include <QColor>
#include <QtGui/qopengl.h>

class fond
{
public:
    //constructeur
    fond(float x, float y, float z,float xmin, float xmax,float ymin,float ymax);
    //getters & setters
    float getxmin(){return xmin_;}
    float getxmax(){return xmax_;}
    float getymin(){return ymin_;}
    float getymax(){return ymax_;}

    //affichage du fond
    void displayFond();
private:
    float positionX;    //coordonnée du fond sur l'axe X
    float positionY;    //coordonnée du fond sur l'axe Y
    float positionZ;    //coordonnée du fond sur l'axe Z
    float xmin_, xmax_,ymin_,ymax_; //dimensions du fond
};

#endif // FOND_H
