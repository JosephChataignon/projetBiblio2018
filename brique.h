#ifndef BRIQUE_H
#define BRIQUE_H


#include <GL/glu.h>
#include <QColor>
#include <QtGui/qopengl.h>
#include <QImage>
class brique
{
public:
    brique(float x, float y, float z, float xmin, float xmax, float ymin, float ymax);
    float getxmin(){return xmin_;}
    float getxmax(){return xmax_;}
    float getymin(){return ymin_;}
    float getymax(){return ymax_;}
    float getX(){return positionX;}
    float getY(){return positionY;}
    void displayBrique();
    bool isPresente(){ return presente; }
    void setPresente(bool b){ presente=b; }
private:
    float positionX;
    float positionY;
    float positionZ;

    bool presente;

    float xmin_, xmax_,ymin_,ymax_;

    QImage tex;
    // Identifiant de texture
    GLuint m_TextureID=1;
};

#endif // BRIQUE_H
