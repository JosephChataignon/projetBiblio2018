#include "jeu.h"
#include <QApplication>
#include <QDesktopWidget>


// Constructeur
Jeu::Jeu(QWidget *parent) : QGLWidget(parent) {

    // Reglage de la taille/position
    setFixedSize(700, 300);
    move(QApplication::desktop()->screen()->rect().center() - rect().center());

    qInfo() << "posX: "<<posX<<" , posY: "<<posY;
}

// Fonction d'initialisation
void Jeu::initializeGL()
{
    couleur.setRgb(200, 150, 50);
}


// Fonction de redimensionnement
void Jeu::resizeGL(int width, int height)
{
    // Definition du viewport
    glViewport(0,0,700,300);

    // Definition de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0f * (16/9), 50.0f * (16/9), -50.0f, 50.0f, -2.0f * 50.0f, 2.0f * 50.0f);

    // Definition de la matrice de modele
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Fonction d'affichage
void Jeu::paintGL()
{
    glClearColor(150.0,100.0,100.0,1.0); // Couleur à utiliser lorsqu’on va nettoyer la fenetre ( = le fond)

    // Reinitialisation du tampon de couleur
    glClear(GL_COLOR_BUFFER_BIT);
    // Reinitialisation de la matrice courante

    // Reglage de la couleur
    glColor3f(couleur.redF(),couleur.greenF(),couleur.blueF());
    // Debut de l'affichage
    glBegin(GL_QUADS); // Primitive à afficher et début de la déclaration des vertices de cette primitive
    glVertex2f(0, 0);  // Déclaration des coordonnées des sommets (en 2D, z=0)
    glVertex2f(0, 25);
    glVertex2f(25+posX, 25+posY);
    glVertex2f(25, 0);
    glEnd();
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
