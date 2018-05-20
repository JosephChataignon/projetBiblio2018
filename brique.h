#ifndef BRIQUE_H
#define BRIQUE_H


#include <GL/glu.h>
#include <QColor>
#include <QtGui/qopengl.h>
#include <QImage>
class brique
{
public:
    //constructeur
    brique(float x, float y, float z, float xmin, float xmax, float ymin, float ymax, int type);
    //getters & setters
    float getxmin(){return xmin_;}
    float getxmax(){return xmax_;}
    float getymin(){return ymin_;}
    float getymax(){return ymax_;}
    float getX(){return positionX;}
    float getY(){return positionY;}
    bool isPresente(){ return presente; }
    void setPresente(bool b){ presente=b; }

    //affichage de la brique
    void displayBrique();

private:
    float positionX;    //coordonnée de la brique sur l'axe X
    float positionY;    //coordonnée de la brique sur l'axe Y
    float positionZ;    //coordonnée de la brique sur l'axe Z
    int type_; //type de brique: 0 = normale, 1 = extraballe, 2 = or, 3 = TNT

    bool presente;      //indique si la brique a déjà été détruite ou non

    float xmin_, xmax_, ymin_, ymax_; //dimensions de la brique

    // Image de la texture
    QImage tex;
    // Identifiant de texture
    GLuint m_TextureID/*=1*/;
};

#endif // BRIQUE_H
