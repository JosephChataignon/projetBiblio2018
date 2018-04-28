#include "fond.h"

fond::fond(float x, float y, float z, float xmin, float xmax, float ymin, float ymax)
{
    positionX=x;
    positionY=y;
    positionZ=z;
    xmin_=xmin;
    ymin_=ymin;
    xmax_=xmax;
    ymax_=ymax;
}

void fond::displayFond()
{
    glPushMatrix();
    glTranslatef(positionX,positionY,positionZ);

    GLfloat color[] = {0.0f,1.0f,1.0f, 1.0f};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color);
    glBegin(GL_QUADS);

    //glColor3ub(0,0,0); // blanc
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(xmin_, ymax_, 0.0f);
    glVertex3f( xmax_, ymax_, 0.0f);
    glVertex3f(xmax_, ymin_, 0.0f);
    glVertex3f(xmin_, ymin_, 0.0f);

    glEnd();
    glPopMatrix();
}
