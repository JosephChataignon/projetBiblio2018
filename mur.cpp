#include "mur.h"

mur::mur(float x, float y, float z,bool sens,bool murBas)
{
    positionX=x;
    positionY=y;
    positionZ=z;
    this->sens=sens;
    if(sens){ // vertical
        this->x=10.0f;
        this->y=-150.0f;
    }else{ // horizontal

        this->x=320;
        this->y=5.0f;
    }
    destruction=murBas;
}


void mur::displayMur()
{
    glPushMatrix();
    glTranslatef(positionX,positionY,positionZ);
    if(destruction){
        GLfloat color[] = {0.9f,0.0f,0.0f, 1.0f};
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color);

    }else{
        GLfloat color[] = {0.0f,0.3f,1.0f, 1.0f};
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color);
    }
    glBegin(GL_QUADS);
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(0.0f, 0.0f, 1.0f);
    glVertex3f( x, 0.0f, 1.0f);
    glVertex3f( x, y, 1.0f);
    glVertex3f(0.0f, y, 1.0f);


    glColor3ub(255,0,0);// rouge
    glNormal3f(1.0,0.0,0.0);
    glVertex3f(x, 0.0f, 0.0f);
    glVertex3f(x, y,0.0f);
    glVertex3f( x, y, 1.0f);
    glVertex3f( x, 0.0f, 1.0f);

    glColor3ub(0,255,0); // vert
    glNormal3f(0.0,0.0,-1.0);
    glVertex3f(x, y, 0.0f);
    glVertex3f(0.0f, y, 0.0f);
    glVertex3f( 0.0f, 0.0f,0.0f);
    glVertex3f( x,0.0f,0.0f);

    glColor3ub(0,255,255);//cyan
    glNormal3f(0.0,-1.0,0.0);
    glVertex3f(0.0f, 0.0f, 1.0f);
    glVertex3f( 0.0f, 0.0f, 0.0f);
    glVertex3f( x, 0.0f,0.0f);
    glVertex3f(x, 0.0f, 1.0f);

    glColor3ub(255,255,0);//jaune
    glNormal3f(0.0,1.0,0.0);
    glVertex3f( 0.0f, y, 0.0f);
    glVertex3f( x, y, 0.0f);
    glVertex3f( x, y, 1.0f);
    glVertex3f( 0.0f, y, 1.0f);

    glColor3ub(255,0,255);// magenta
    glNormal3f(-1.0,0.0,0.0);
    glVertex3f( 0.0f, 0.0f, 1.0f);
    glVertex3f( 0.0f, 0.0f,0.0f);
    glVertex3f( 0.0f, y,0.0f);
    glVertex3f( 0.0f, y, 1.0f);
    glEnd();
    glPopMatrix();
}
