#include "brique.h"
#include <QImage>
#include <QGLWidget>
brique::brique(float x, float y, float z)
{
    positionX=x;
    positionY=y;
    positionZ=z;
    tex = QGLWidget::convertToGLFormat(QImage(QString(":/image/brique.jpg")));
    glGenTextures(1, &m_TextureID);
    glBindTexture(GL_TEXTURE_2D, m_TextureID);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, tex.width(), tex.height(), 0, GL_RGBA , GL_UNSIGNED_BYTE, tex.bits());
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

}

void brique::displayBrique()
{

    glPushMatrix();
    glTranslatef(positionX,positionY,positionZ);

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glTexCoord2f(0, 0);  glVertex3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(1, 0);  glVertex3f( 30, 0.0f, 1.0f);
    glTexCoord2f(1, 1);  glVertex3f( 30, 10, 1.0f);
    glTexCoord2f(0, 1);  glVertex3f(0.0f, 10, 1.0f);

    glVertex3f(30, 0.0f, 0.0f);
    glVertex3f(30, 10,0.0f);
    glVertex3f( 30, 10, 1.0f);
    glVertex3f( 30, 0.0f, 1.0f);

    glVertex3f(30, 10, 0.0f);
    glVertex3f(0.0f, 10, 0.0f);
    glVertex3f( 0.0f, 0.0f,0.0f);
    glVertex3f( 30,0.0f,0.0f);

    glVertex3f(0.0f, 0.0f, 1.0f);
    glVertex3f( 0.0f, 0.0f, 0.0f);
    glVertex3f( 30, 0.0f,0.0f);
    glVertex3f(30, 0.0f, 1.0f);

    glVertex3f( 0.0f, 10, 0.0f);
    glVertex3f( 30, 10, 0.0f);
    glVertex3f( 30, 10, 1.0f);
    glVertex3f( 0.0f, 10, 1.0f);

    glVertex3f( 0.0f, 0.0f, 1.0f);
    glVertex3f( 0.0f, 0.0f,0.0f);
    glVertex3f( 0.0f, 10,0.0f);
    glVertex3f( 0.0f, 10, 1.0f);
    glEnd();
    glPopMatrix();
}
