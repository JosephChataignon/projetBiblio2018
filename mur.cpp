#include "mur.h"

mur::mur(float x, float y, float z,bool sens)
{
    positionX=x;
    positionY=y;
    positionZ=z;
    this->sens=sens;
    if(sens){ // horizontale
        this->x=10.0f;
        this->y=-140.0f;
    }else{ // vertical
        this->x=331;
        this->y=5.0f;
    }
}


void mur::displayMur()
{
    glPushMatrix();
    glTranslatef(positionX,positionY,positionZ);
    glBegin(GL_QUADS);
    glColor3ub(0,0,255); // bleu
    glVertex3f(0.0f, 0.0f, 1.0f);
    glVertex3f( x, 0.0f, 1.0f);
    glVertex3f( x, y, 1.0f);
    glVertex3f(0.0f, y, 1.0f);


    glColor3ub(255,0,0);// rouge
    glVertex3f(x, 0.0f, 0.0f);
    glVertex3f(x, y,0.0f);
    glVertex3f( x, y, 1.0f);
    glVertex3f( x, 0.0f, 1.0f);

    glColor3ub(0,255,0); // vert
    glVertex3f(x, y, 0.0f);
    glVertex3f(0.0f, y, 0.0f);
    glVertex3f( 0.0f, 0.0f,0.0f);
    glVertex3f( x,0.0f,0.0f);

    glColor3ub(0,255,255);//cyan
    glVertex3f(0.0f, 0.0f, 1.0f);
    glVertex3f( 0.0f, 0.0f, 0.0f);
    glVertex3f( x, 0.0f,0.0f);
    glVertex3f(x, 0.0f, 1.0f);

    glColor3ub(255,255,0);//jaune
    glVertex3f( 0.0f, y, 0.0f);
    glVertex3f( x, y, 0.0f);
    glVertex3f( x, y, 1.0f);
    glVertex3f( 0.0f, y, 1.0f);

    glColor3ub(255,0,255);// magenta
    glVertex3f( 0.0f, 0.0f, 1.0f);
    glVertex3f( 0.0f, 0.0f,0.0f);
    glVertex3f( 0.0f, y,0.0f);
    glVertex3f( 0.0f, y, 1.0f);
    glEnd();
    glPopMatrix();
}
