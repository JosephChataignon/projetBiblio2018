#ifndef BALLE_H
#define BALLE_H


#include <GL/glu.h>
#include <QColor>
#include <QtGui/qopengl.h>
class balle
{
public:
    balle(float x, float y, float z);
    void displayBalle(const float time);

    // Destructeur
    virtual ~balle();
private:
    float positionX;
    float positionY;
    float positionZ;

    GLUquadric * m_balle = nullptr;
};

#endif // BALLE_H
