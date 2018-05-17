#ifndef MUR_H
#define MUR_H

#include <GL/glu.h>
#include <QColor>
#include <QtGui/qopengl.h>
#include <QImage>

class mur
{
public:
    //constructeur
    mur(float x, float y, float z, bool sens, bool murBas=false);
    //affichage du mur
    void displayMur();
private:
    //coordonnées du mur
    float positionX;
    float positionY;
    float positionZ;
    //sens du mur (allongé suivant X ou suivant Y)
    bool sens;
    //indique si c'est un mur qui détruit la balle (uniquement le mur du bas normalement)
    bool destruction;
    //dimensions du mur
    float x,y;

    // Image de la texture
    QImage tex;
    // Identifiant de texture
    GLuint m_TextureID=0;
};

#endif // MUR_H
