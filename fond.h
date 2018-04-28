#ifndef FOND_H
#define FOND_H

#include <GL/glu.h>
#include <QColor>
#include <QtGui/qopengl.h>

class fond
{
public:
    fond(float x, float y, float z,float xmin, float xmax,float ymin,float ymax);
    float getxmin(){return xmin_;}
    float getxmax(){return xmax_;}
    float getymin(){return ymin_;}
    float getymax(){return ymax_;}
    void displayFond();
private:
    float positionX;
    float positionY;
    float positionZ;
    float xmin_, xmax_,ymin_,ymax_;
};

#endif // FOND_H
