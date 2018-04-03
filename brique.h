#ifndef BRIQUE_H
#define BRIQUE_H


#include <GL/glu.h>
#include <QColor>
#include <QtGui/qopengl.h>
class brique
{
public:
    brique(float x, float y, float z);
    void displayBrique();
private:
    float positionX;
    float positionY;
    float positionZ;
};

#endif // BRIQUE_H
