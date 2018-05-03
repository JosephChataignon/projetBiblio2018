#ifndef CASSEBRIQUE_H
#define CASSEBRIQUE_H
#include <GL/glu.h>
#include <QColor>
#include <QtGui/qopengl.h>
#include <balle.h>
#include <brique.h>
#include <fond.h>
#include <mur.h>
#include <palet.h>

class cassebrique
{
public:
    cassebrique();
    void affichage();
    void animation(float vX);
    int getNbBalle(){return nbBalle;}
    void setNbBalle(int x){nbBalle = x;}
    int getScore(){return score_;}
    void setScore(int x){score_ = x;}
    int getNiveau(){return niveau_;}
    void setNiveau(int x){niveau_ = x;}

private:
    float murGauche = -166;
    float murDroite =  145;
    float murHaut   =  77;
    float murBas=-80;
    std::vector<brique*> tabBrique;
    palet* barre;
    fond* fond_;
    balle* current_balle;
    std::vector<mur*> tabMur;
    int nbBalle;
    int score_;
    int niveau_;
    float vitessePalet;

    float vitesseBalleY;
    float vitesseBalleX;


};

#endif // CASSEBRIQUE_H
