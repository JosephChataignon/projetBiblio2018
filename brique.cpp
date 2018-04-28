#include "brique.h"
#include <QImage>
#include <QGLWidget>
brique::brique(float x, float y, float z, float xmin, float xmax, float ymin, float ymax)
{
    positionX=x;
    positionY=y;
    positionZ=z;
    xmin_=xmin;
    ymin_=ymin;
    xmax_=xmax;
    ymax_=ymax;
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
    glDisable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glTranslatef(positionX,positionY,positionZ);

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glTexCoord2f(0, 0);  glVertex3f(xmin_,ymin_, 1.0f);
    glTexCoord2f(1, 0);  glVertex3f( xmax_, ymin_, 1.0f);
    glTexCoord2f(1, 1);  glVertex3f( xmax_, ymax_, 1.0f);
    glTexCoord2f(0, 1);  glVertex3f(xmin_, ymax_, 1.0f);

    glVertex3f(xmax_, ymin_, 0.0f);
    glVertex3f(xmax_, ymax_,0.0f);
    glVertex3f( xmax_, ymax_, 1.0f);
    glVertex3f( xmax_, ymin_, 1.0f);

    glVertex3f(xmax_, ymax_, 0.0f);
    glVertex3f(xmin_, ymax_, 0.0f);
    glVertex3f( xmin_, ymin_,0.0f);
    glVertex3f( xmax_,ymin_,0.0f);

    glVertex3f(xmin_, ymin_, 1.0f);
    glVertex3f( xmin_, ymin_, 0.0f);
    glVertex3f( xmax_, ymin_,0.0f);
    glVertex3f(xmax_, ymin_, 1.0f);

    glVertex3f( xmin_, ymax_, 0.0f);
    glVertex3f( xmax_, ymax_, 0.0f);
    glVertex3f( xmax_, ymax_, 1.0f);
    glVertex3f( xmin_, ymax_, 1.0f);

    glVertex3f(xmin_,ymin_, 1.0f);
    glVertex3f(xmin_, ymin_,0.0f);
    glVertex3f( xmin_, ymax_,0.0f);
    glVertex3f( xmin_, ymax_, 1.0f);

    glEnd();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    glPopMatrix();
}
