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
    // constructeur
    cassebrique();
    // appelle les fonctions d'affichage de chaque composant
    void affichage();
    // calcule le nouvel état du jeu à chaque tick (vX est la vitesse horizontale détectée par la caméra)
    void animation(float vX, float vY);
    // met une nouvelle balle en jeu
    void nouvelleBalle();
    // réinitialise les briques pour un nouveau niveau
    void nouveauNiveau();
    // vérifie le rebond de la balle sur une brique en fonction des coordonnées de la balle
    bool rebondBrique(brique* b, float xBalle, float yBalle);

    // getters & setters
    bool getNewBall(){return newBall;}
    void setNewBall(bool x){newBall=x;}
    int getNbBalle(){return nbBalle;}
    void setNbBalle(int x){nbBalle = x;}
    int getScore(){return score_;}
    void setScore(int x){score_ = x;}
    int getNiveau(){return niveau_;}
    void setNiveau(int x){niveau_ = x;}

private:
    float murGauche = -165; //coordonnée X du mur de gauche
    float murDroite =  145; //coordonnée X du mur de droite
    float murHaut   =  75;  //coordonnée Y du mur du haut
    float murBas=-80;       //coordonnée Y du mur du bas
    std::vector<brique*> tabBrique; //tableau contenant les briques du niveau
    palet* barre;           //le palet du jeu
    fond* fond_;            //représente le "sol" sur lequel les autres éléments sont placés
    balle* current_balle;   //la balle
    std::vector<mur*> tabMur;   //tableau contenant les objets murs

    int nbBalle;            //nombre de balles restantes dans cette partie
    int score_;             //score de la partie
    int niveau_;            //niveau auquel se trouve le joueur
    bool newBall = false;   //variable utilisée pour le délai à chaque nouvelle balle
    float vitessePalet;     //vitesse du palet
    float vitesseBalleY;    //vitesse de la balle sur l'axe Y
    float vitesseBalleX;    //vitesse de la balle sur l'axe X


};

#endif // CASSEBRIQUE_H
