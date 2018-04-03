#ifndef MUR_H
#define MUR_H

#include <GL/glu.h>
#include <QColor>
#include <QtGui/qopengl.h>

class mur
{
public:
    mur(float x, float y, float z, bool sens);
    void displayMur();
private:
    float positionX;
    float positionY;
    float positionZ;
    bool sens;
    float x,y;
};

#endif // MUR_H
