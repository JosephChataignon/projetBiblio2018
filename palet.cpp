#include "palet.h"
#include <QDebug>
palet::palet(float x, float y, float z)
{
    positionX=x;
    positionY=y;
    positionZ=z;
}

void palet::displayPalet(float x, float y, float z)
{
    positionX+=x;
    positionY=y;
    positionZ=z;
    qInfo() << "position X du palet : "<<positionX;
    glPushMatrix();
    glTranslatef(positionX,positionY,positionZ);
    glBegin(GL_QUADS);
    glColor3ub(0,0,255); // bleu
    glVertex3f(-30.0f, 0.0f, 1.0f);
    glVertex3f( 30.0f, 0.0f, 1.0f);
    glVertex3f( 30.0f, 4.0f, 1.0f);
    glVertex3f(-30.0f, 4.0f, 1.0f);


    glColor3ub(255,0,0);// rouge
    glVertex3f(30.0f, 0.0f, 0.0f);
    glVertex3f(30.0f, 4.0f,0.0f);
    glVertex3f( 30.0f, 4.0f, 1.0f);
    glVertex3f( 30.0f, 0.0f, 1.0f);

    glColor3ub(0,255,0); // vert
    glVertex3f(30.0f, 4, 0.0f);
    glVertex3f(-30.0f, 4, 0.0f);
    glVertex3f( -30.0f, 0.0f,0.0f);
    glVertex3f( 30.0f,0.0f,0.0f);

    glColor3ub(0,255,255);//cyan
    glVertex3f(-30.0f, 0.0f, 1.0f);
    glVertex3f( -30.0f, 0.0f, 0.0f);
    glVertex3f( 30.0f, 0.0f,0.0f);
    glVertex3f(30.0f, 0.0f, 1.0f);

    glColor3ub(255,255,0);//jaune
    glVertex3f( -30.0f, 4, 0.0f);
    glVertex3f( 30.0f, 4, 0.0f);
    glVertex3f( 30.0f, 4, 1.0f);
    glVertex3f( -30.0f, 4, 1.0f);

    glColor3ub(255,0,255);// magenta
    glVertex3f( -30.0f, 0.0f, 1.0f);
    glVertex3f( -30.0f, 0.0f,0.0f);
    glVertex3f( -30.0f, 4,0.0f);
    glVertex3f( -30.0f, 4, 1.0f);
    glEnd();
    glPopMatrix();
}
