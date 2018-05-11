#ifndef JEU_H
#define JEU_H

#include <QWidget>
#include <QGLWidget>
#include <QKeyEvent>
#include <QTimer>
#include "opencv2/opencv.hpp"
#include <QDebug>
#include <QColor>
#include <cassebrique.h>
class Jeu : public QGLWidget
{
    Q_OBJECT

public:
    //constructeur
    explicit Jeu(QWidget *parent = 0);
    //getters & setters
    void setPos(cv::Point v){ vX =(float) v.x; vY = v.y;}
    cassebrique* getJeuCasseBrique(){return jeuCasseBrique;}
    //fonction de mise en pause temporaire
    void pause();
public slots:

protected:

    // Fonction d'initialisation
    void initializeGL();
    // Fonction de redimensionnement
    void resizeGL(int width, int height);
    // Fonction d'affichage
    void paintGL();



private:
    //fonction calculant le rebond du palet sur les murs latéraux s'il y a lieu
    void rebondPalet(float xPalet, float xBalle);

    float m_Time { 0.0f }; //timer d'animation
    float vX;   //coordonnée X de déplacement de la main obtenue par la caméra
    float vY;   //coordonnée Y de déplacement de la main obtenue par la caméra
    cassebrique* jeuCasseBrique;
    //labels affichant les informations de jeu
    QString m_TexteLevel = "";
    QString m_TexteScore = "";
    QString m_TexteNbBalle = "";

    QColor couleur;
    //coordonnées vers lesquelles la caméra est tournée
    float posCamX_;
    float posCamY_;
    float posCamZ_;

    //indique si le jeu est en pause temporaire ou non
    bool pause_=false;

    //coordonnées X et Y des 4 murs
    float murGauche = -165;
    float murDroite =  145;
    float murHaut   =  75;
    float murBas    = -80;

    float vitessePalet;     //vitesse du palet
    float vitesseBalleX;    //vitesse de la balle sur l'axe X
    float vitesseBalleY;    //vitesse de la balle sur l'axe Y

};
#endif // JEU_H
