#ifndef BRIQUE_H
#define BRIQUE_H


#include <GL/glu.h>
#include <QColor>
#include <QtGui/qopengl.h>
#include <QImage>
class brique
{
public:
    brique(float x, float y, float z);
    void displayBrique();
private:
    float positionX;
    float positionY;
    float positionZ;
    QImage tex;
    // Identifiant de texture
    GLuint m_TextureID=1;
};

#endif // BRIQUE_H
