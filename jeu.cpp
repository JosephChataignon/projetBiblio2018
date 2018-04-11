#include "jeu.h"
#include <QApplication>
#include <QDesktopWidget>


// Constructeur
Jeu::Jeu(QWidget *parent) : QGLWidget(parent) {

    // Reglage de la taille/position
    setFixedSize(700, 300);
    move(QApplication::desktop()->screen()->rect().center() - rect().center());
    for(int j=0;j<12;j++){
        for(int i=0;i<10;i++){
           tabBrique.push_back(new brique(-35.1f+7*i,40-j*3,0));
        }
    }
    tabMur.push_back(new mur(-37,42,0,true));
    tabMur.push_back(new mur(35,42,0,true));
    tabMur.push_back(new mur(-37,45,0,false));
    barre =new palet(0,0,0);
    posCamX_=0;
    posCamY_=0;
    posCamZ_=1.1f;
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
    glOrtho(-50.0f * (16/9), 50.0f * (16/9), -50.0f, 50.0f, -50.0f,50.0f);

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
}


// Fonction de gestion d'interactions clavier
void Jeu::keyPressEvent(QKeyEvent * event){
    switch(event->key())    {
        // Sortie de l'application


        case Qt::Key_Escape:
        {
            close();
            break;
        }
        // Cas par defaut
        default:
        {
            event->ignore();
            return;
        }
    }
    // Acceptation de l'evenement et mise a jour de la scene
    event->accept();
    updateGL();
}
