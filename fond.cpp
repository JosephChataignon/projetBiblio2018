#include "fond.h"

fond::fond(float x, float y, float z)
{
    positionX=x;
    positionY=y;
    positionZ=z;
}

void fond::displayFond()
{
    glPushMatrix();
    glTranslatef(positionX,positionY,positionZ);
    glBegin(GL_QUADS);
    glColor3ub(0,0,0); // blanc
    glVertex3f(-166.0f, 147.0f, 0.0f);
    glVertex3f( 166.0f, 147.0f, 0.0f);
    glVertex3f( 166.0f, -10, 0.0f);
    glVertex3f(-166.0f, -10, 0.0f);

    glEnd();
    glPopMatrix();
}
