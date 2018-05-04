#include "jeu.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QFont>


// Constructeur
Jeu::Jeu(QWidget *parent) : QGLWidget(parent) {

    // Reglage de la taille/position
    setFixedSize(700, 300);
    move(QApplication::desktop()->screen()->rect().center() - rect().center());


    posCamX_=0.0f;
    posCamY_=0.7f;
    posCamZ_=10.1f;

    vitessePalet = 0;

}

// Fonction d'initialisation
void Jeu::initializeGL()
{
    couleur.setRgb(200, 150, 50);
    glClearColor(0.5,0.5,0.5,1);
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_TEXTURE_2D);
    // Réglage de la lampe (en position 0,0,0, emettant dans toutes les directions, avec une couleur ambiante et diffuse blanche)
    GLfloat Light[] = {1.0f, 1.0f, 1.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_AMBIENT_AND_DIFFUSE, Light);
    GLfloat positionLight[] = {0.0f, 0.0f, 1.0f, 0.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, positionLight);

    //Activation de la lumiere dans OpenGL et de la lampe
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    jeuCasseBrique=new cassebrique();
    vitesseBalleY = 5;
    vitesseBalleX = rand()%5-2.5;

    if(vitesseBalleX==0){vitesseBalleX+=1;}
}


// Fonction de redimensionnement
void Jeu::resizeGL(int width, int height)
{
    // Définition du viewport
    glViewport(0,0,700,300);

    // Définition de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-350.0f * (16/9), 350.0f * (16/9), -150.0f, 150.0f, -50.0f,50.0f);

}

// Fonction d'affichage
void Jeu::paintGL()
{
    m_TexteLevel = QString("Niveau: %1").arg(QString::number(jeuCasseBrique->getNiveau()));
    m_TexteScore = QString("Score: %1").arg(QString::number(jeuCasseBrique->getScore()));
    m_TexteNbBalle = QString("Nombre de balle(s) restante(s): %1").arg(QString::number(jeuCasseBrique->getNbBalle()));

    glClearColor(1,1,1,1); // Couleur à utiliser lorsqu’on va nettoyer la fenetre ( = le fond)

    // Réinitialisation du tampon de couleur
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    // Réinitialisation de la matrice courante
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(posCamX_,posCamY_,posCamZ_,0,0,0,0,1,0);
    glScalef(1.25f,1.25f,1.0f);
    jeuCasseBrique->affichage();
    glColor3f(0,0,0);
    renderText(270, 35, "Casse-briques", QFont( "Helvetica", 20, QFont::Bold, TRUE ));
    renderText(0, 275, m_TexteNbBalle, QFont( "lucida", 10, QFont::Bold, TRUE ));
    renderText(325, 275, m_TexteLevel, QFont( "lucida", 10, QFont::Bold, TRUE ));
    renderText(575, 275, m_TexteScore, QFont( "lucida", 10, QFont::Bold, TRUE ));

}


void Jeu::rebondPalet(float xPalet, float xBalle){
    float vitesseAbsBalle = sqrt(vitesseBalleX*vitesseBalleX+vitesseBalleY*vitesseBalleY);
    float angleBalle = atan(vitesseBalleX/vitesseBalleY);
    float angleRebondBalle = -angleBalle+atan(1)*(xBalle-xPalet);
    vitesseBalleY = sqrt(vitesseAbsBalle*vitesseAbsBalle/(1+tan(angleRebondBalle)*tan(angleRebondBalle)));
    vitesseBalleX = sqrt(vitesseAbsBalle*vitesseAbsBalle-vitesseBalleY*vitesseBalleY);
}



