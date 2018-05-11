#ifndef WIDGET_H
#define WIDGET_H

#include "opencv2/opencv.hpp"
#include <QWidget>
#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <QTimer>
#include "gestioncam.h"

using namespace std;
using namespace cv;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    //constructeur
    explicit Widget(QWidget *parent = 0);
    //getters & setters
    void setVect(Point v){ vect = v; }
    cv::Point getVect(){ return vect; }
    //détection de l'appui sur les touches du clavier
    void keyPressEvent(QKeyEvent * event);
    //destructeur
    ~Widget();


private:
    Ui::Widget *ui;     //modèle de l'interface graphique
    Mat frame;          //objet Mat contenant 1 image à analyser
    QTimer* time;       //timer de capture d'image
    gestionCam *cam;    //objet représentant la caméra
    cv::Point vect;     //vecteur contenant les coordonnées de déplacement de la main
    QTimer* timeAnimation;  //timer d'animation du jeu

private slots:
    void animation();   //animation du jeu (appelée à chaque tick du timer)
    void video();       //capture et analyse d'une image, et affichage dans la fenêtre
};

#endif // WIDGET_H
