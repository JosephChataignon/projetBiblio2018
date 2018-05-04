#include "palet.h"
#include <QDebug>
palet::palet(float x, float y, float z)
{
    positionX=x;
    positionY=y;
    positionZ=z;
}

void palet::displayPalet()
{
    glPushMatrix();
    glTranslatef(positionX,positionY,positionZ);
    GLfloat color[] = {0.0f,1.0f,0.2f, 1.0f};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color);
    glBegin(GL_QUADS);
    glColor3ub(0,0,255); // bleu
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(-30.0f, 0.0f, 1.0f);
    glVertex3f( 30.0f, 0.0f, 1.0f);
    glVertex3f( 30.0f, 4.0f, 1.0f);
    glVertex3f(-30.0f, 4.0f, 1.0f);


    glColor3ub(255,0,0);// rouge
    glNormal3f(1.0,0.0,0.0);
    glVertex3f(30.0f, 0.0f, 0.0f);
    glVertex3f(30.0f, 4.0f,0.0f);
    glVertex3f( 30.0f, 4.0f, 1.0f);
    glVertex3f( 30.0f, 0.0f, 1.0f);

    glColor3ub(0,255,0); // vert
    glNormal3f(0.0,0.0,-1.0);
    glVertex3f(30.0f, 4, 0.0f);
    glVertex3f(-30.0f, 4, 0.0f);
    glVertex3f( -30.0f, 0.0f,0.0f);
    glVertex3f( 30.0f,0.0f,0.0f);

    glColor3ub(0,255,255);//cyan
    glNormal3f(0.0,-1.0,0.0);
    glVertex3f(-30.0f, 0.0f, 1.0f);
    glVertex3f( -30.0f, 0.0f, 0.0f);
    glVertex3f( 30.0f, 0.0f,0.0f);
    glVertex3f(30.0f, 0.0f, 1.0f);

    glColor3ub(255,255,0);//jaune
    glNormal3f(0.0,1.0,0.0);
    glVertex3f( -30.0f, 4, 0.0f);
    glVertex3f( 30.0f, 4, 0.0f);
    glVertex3f( 30.0f, 4, 1.0f);
    glVertex3f( -30.0f, 4, 1.0f);

    glColor3ub(255,0,255);// magenta
    glNormal3f(-1.0,0.0,0.0);
    glVertex3f( -30.0f, 0.0f, 1.0f);
    glVertex3f( -30.0f, 0.0f,0.0f);
    glVertex3f( -30.0f, 4,0.0f);
    glVertex3f( -30.0f, 4, 1.0f);
    glEnd();
    glPopMatrix();
}

void palet::movePalet(float x){
    positionX+=x;
}
