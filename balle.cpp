#include "balle.h"
#include <QGLWidget>
balle::balle(float x, float y, float z,GLdouble rayon)
{
    positionX=x;
    positionY=y;
    positionZ=z;
    radius=rayon;
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
    glColor3f(1,0,0);
    GLfloat color[] = {0.67f,0.92f,0.0f, 1.0f};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color);
    gluSphere(m_balle,radius,50,50);
    glPopMatrix();
}
