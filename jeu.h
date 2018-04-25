#ifndef JEU_H
#define JEU_H

#include <QWidget>
#include <QGLWidget>
#include <QKeyEvent>
#include <QTimer>
#include "opencv2/opencv.hpp"
#include <QDebug>
#include <QColor>
#include "brique.h"
#include "mur.h"
#include "palet.h"
#include "balle.h"
#include "fond.h"
class Jeu : public QGLWidget
{
    Q_OBJECT

public:
    explicit Jeu(QWidget *parent = 0);
    void setPos(cv::Point v){ vX =(float) v.x; vY = v.y;}

    void animation();
public slots:

protected:

    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

private:
    void rebondPalet(float xPalet, float xBalle);
    // Timer d'animation
    float m_Time { 0.0f };
    float vX;
    float vY;

    std::vector<brique*> tabBrique;
    palet* barre;
    fond* fond_;
    balle* current_balle;
    std::vector<mur*> tabMur;
    QColor couleur;
    float posCamX_;
    float posCamY_;
    float posCamZ_;

    float murGauche = -166;
    float murDroite =  155;
    float murHaut   =  142;
    float murBas=-10;
    float vitessePalet;
    float vitesseBalleX;
    float vitesseBalleY;

};
#endif // JEU_H
