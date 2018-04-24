#include "balle.h"
#include <QGLWidget>
balle::balle(float x, float y, float z)
{
    positionX=x;
    positionY=y;
    positionZ=z;

    m_balle = gluNewQuadric();
}
balle::~balle()
{
    // Destruction des quadriques
    gluDeleteQuadric(m_balle);
}
void balle::displayBalle()
{
    glPushMatrix();
    glTranslatef(positionX,positionY,positionZ);
    //glRotatef(time*360,0.0f,1.0f,0.0f);
    glColor3f(1,0,0);
    gluSphere(m_balle,5,50,50);
    glPopMatrix();
}
