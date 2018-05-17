#include "mur.h"
#include <QGLWidget>

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

    tex = QGLWidget::convertToGLFormat(QImage(QString(":/image/murbleu.jpg")));
    glGenTextures(2, &m_TextureID);
    glBindTexture(GL_TEXTURE_2D, m_TextureID);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, tex.width(), tex.height(), 0, GL_RGBA , GL_UNSIGNED_BYTE, tex.bits());
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}


void mur::displayMur()
{
    glPushMatrix();

    glTranslatef(positionX,positionY,positionZ);
    if(destruction){
        GLfloat color[] = {0.9f,0.0f,0.0f, 1.0f};
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color);

    }else{
        glDisable(GL_LIGHTING);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, m_TextureID);
    }
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glNormal3f(0.0,0.0,1.0);
    glTexCoord2f(0, 0);glVertex3f(0.0f, 0.0f, 10.0f);
    glTexCoord2f(1, 0);glVertex3f( x, 0.0f, 10.0f);
    glTexCoord2f(1, 1);glVertex3f( x, y, 10.0f);
    glTexCoord2f(0, 1);glVertex3f(0.0f, y, 10.0f);


    glNormal3f(1.0,0.0,0.0);
    glTexCoord2f(0, 0);glVertex3f(x, 0.0f, 0.0f);
    glTexCoord2f(1, 0);glVertex3f(x, y,0.0f);
    glTexCoord2f(1, 1);glVertex3f( x, y, 10.0f);
    glTexCoord2f(0, 1);glVertex3f( x, 0.0f, 10.0f);

    glNormal3f(0.0,0.0,-1.0);
    glTexCoord2f(0, 0);glVertex3f(x, y, 0.0f);
    glTexCoord2f(1, 0);glVertex3f(0.0f, y, 0.0f);
    glTexCoord2f(1, 1);glVertex3f( 0.0f, 0.0f,0.0f);
    glTexCoord2f(0, 1);glVertex3f( x,0.0f,0.0f);

    glNormal3f(0.0,-1.0,0.0);
    glTexCoord2f(0, 0);glVertex3f(0.0f, 0.0f, 10.0f);
    glTexCoord2f(1, 0);glVertex3f( 0.0f, 0.0f, 0.0f);
    glTexCoord2f(1, 1);glVertex3f( x, 0.0f,0.0f);
    glTexCoord2f(0, 1);glVertex3f(x, 0.0f, 10.0f);

    glNormal3f(0.0,1.0,0.0);
    glTexCoord2f(0, 0);glVertex3f( 0.0f, y, 0.0f);
    glTexCoord2f(1, 0);glVertex3f( x, y, 0.0f);
    glTexCoord2f(1, 1);glVertex3f( x, y, 10.0f);
    glTexCoord2f(0, 1);glVertex3f( 0.0f, y, 10.0f);


    glNormal3f(-1.0,0.0,0.0);
    glTexCoord2f(0, 0);glVertex3f( 0.0f, 0.0f, 10.0f);
    glTexCoord2f(1, 0);glVertex3f( 0.0f, 0.0f,0.0f);
    glTexCoord2f(1, 1);glVertex3f( 0.0f, y,0.0f);
    glTexCoord2f(0, 1);glVertex3f( 0.0f, y, 10.0f);
    glEnd();
    if(!destruction){
        glDisable(GL_TEXTURE_2D);
        glEnable(GL_LIGHTING);
    }

    glPopMatrix();
}
