#include "jeu.h"
#include <QApplication>
#include <QDesktopWidget>


// Constructeur
Jeu::Jeu(QWidget *parent) : QGLWidget(parent) {

    // Reglage de la taille/position
    setFixedSize(700, 300);
    move(QApplication::desktop()->screen()->rect().center() - rect().center());
    for(int j=0;j<8;j++){
        for(int i=0;i<10;i++){
           tabBrique.push_back(new brique(-155+31*i,130-j*11,0));
        }
    }
    tabMur.push_back(new mur(-166,140,0,true));
    tabMur.push_back(new mur(155,140,0,true));
    tabMur.push_back(new mur(-166,142,0,false));
    barre =new palet(0,0,0);
    current_balle=new balle(0,-10,0);
    posCamX_=0;
    posCamY_=0;
    posCamZ_=1.1f;

    // Connexion du timer
    connect(&m_AnimationTimer,  &QTimer::timeout, [&] {
        m_Time += 1.0f / 24.0f;
        updateGL();
    });

    m_AnimationTimer.setInterval(10);
    m_AnimationTimer.start();
}

// Fonction d'initialisation
void Jeu::initializeGL()
{
    couleur.setRgb(200, 150, 50);
    glClearColor(0.5,0.5,0.5,1);
    glEnable(GL_DEPTH_TEST);
}


// Fonction de redimensionnement
void Jeu::resizeGL(int width, int height)
{
    // Definition du viewport
    glViewport(0,0,700,300);

    // Definition de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-350.0f * (16/9), 350.0f * (16/9), -150.0f, 150.0f, -50.0f,50.0f);

}

// Fonction d'affichage
void Jeu::paintGL()
{
    glClearColor(0.5,0.5,0.5,1); // Couleur à utiliser lorsqu’on va nettoyer la fenetre ( = le fond)

    // Reinitialisation du tampon de couleur
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    // Reinitialisation de la matrice courante
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(posCamX_,posCamY_,posCamZ_,0,0,0,0,1,0);

    for(int i=0;i<tabBrique.size();i++){
       tabBrique[i]->displayBrique();
    }
    for(int i=0;i<tabMur.size();i++){
       tabMur[i]->displayMur();
    }
    barre->displayPalet(posX,0,0);
    current_balle->displayBalle(m_Time);
}

