#ifndef FOND_H
#define FOND_H

#include <GL/glu.h>
#include <QColor>
#include <QtGui/qopengl.h>

class fond
{
public:
    fond(float x, float y, float z);
    void displayFond();
private:
    float positionX;
    float positionY;
    float positionZ;
};

#endif // FOND_H
