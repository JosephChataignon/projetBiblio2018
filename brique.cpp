#include "brique.h"

#include <QGLWidget>
brique::brique(float x, float y, float z)
{
    positionX=x;
    positionY=y;
    positionZ=z;
}

void brique::displayBrique()
{
    glTranslatef(positionX,positionY,positionZ);
    glBegin(GL_QUADS);
    glColor3ub(0,0,255); // bleu
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f( 2.0f, -1.0f, 1.0f);
    glVertex3f( 2.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);


    glColor3ub(255,0,0);// rouge
    glVertex3f(2.0f, -1.0f, -1.0f);
    glVertex3f(2.0f, 1.0f,- 1.0f);
    glVertex3f( 2.0f, 1.0f, 1.0f);
    glVertex3f( 2.0f, -1.0f, 1.0f);

    glColor3ub(0,255,0); // vert
    glVertex3f(2.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f( -1.0f, -1.0f,- 1.0f);
    glVertex3f( 2.0f,- 1.0f,- 1.0f);

    glColor3ub(0,255,255);//cyan
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f( -1.0f, 1.0f, -1.0f);
    glVertex3f( 2.0f, 1.0f,- 1.0f);
    glVertex3f(2.0f, 1.0f, 1.0f);

    glColor3ub(255,255,0);//jaune
    glVertex3f( 2.0f, 1.0f, 1.0f);
    glVertex3f( 2.0f, 1.0f, 1.0f);
    glVertex3f( 2.0f, 1.0f, 1.0f);
    glVertex3f( 2.0f, 1.0f, 1.0f);

    glColor3ub(255,0,255);// magenta
    glVertex3f( -1.0f, -1.0f, 1.0f);
    glVertex3f( -1.0f, -1.0f,- 1.0f);
    glVertex3f( 2.0f, -1.0f,- 1.0f);
    glVertex3f( 2.0f, -1.0f, 1.0f);
    glEnd();
}
