#include "jeu.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QFont>
#include <thread>

// Constructeur
Jeu::Jeu(QWidget *parent) : QGLWidget(parent) {

    // Reglage de la taille/position
    setFixedSize(700, 300);
    move(QApplication::desktop()->screen()->rect().center() - rect().center());

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



    posCamX_=2.0f;
    posCamY_=1.75f;
    posCamZ_=145.0f;

    vitessePalet = 0;

    //initialisation des variables du jeu
    jeuCasseBrique=new cassebrique();
    vitesseBalleY = 5;
    //la balle commence avec un angle aléatoire
    vitesseBalleX = rand()%5-2.5;
    if(vitesseBalleX==0){vitesseBalleX+=1;} //cet angle ne doit pas être nul
}


// Fonction de redimensionnement
void Jeu::resizeGL(int width, int height)
{
    // Définition du viewport
    glViewport(0,0,700,300);

    // Définition de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-350.0f * (16/9), 350.0f * (16/9), -150.0f, 150.0f, -50.0f,50.0f);
    //glFrustum(-350.0f * (16/9), 350.0f * (16/9), -150.0f, 150.0f, 0.1f,3.0f);
    gluPerspective(75.0f, 700/300, 0.01f , 150.0f );
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
    gluLookAt(posCamX_,posCamY_,posCamZ_,0,0,1,0,1,0);
    jeuCasseBrique->affichage();
    if(pause_){
        pause();
        pause_=false;
    }
    if(jeuCasseBrique->getNewBall()){
        pause_=true;

        if(jeuCasseBrique->getNbBalle()==0){
            glColor3f(1,1,1);
            renderText(270,190, "PERDU", QFont( "Helvetica", 20, QFont::Bold, TRUE ));
            jeuCasseBrique->setNbBalle(3);
        }else {
            glColor3f(1,1,1);
            renderText(250,190, "Nouvelle balle", QFont( "Helvetica", 20, QFont::Bold, TRUE ));
        }
        jeuCasseBrique->setNewBall(false);
    }

    glColor3f(0,0,0);
    renderText(270, 25, "Casse-briques", QFont( "Helvetica", 18, QFont::Bold, TRUE ));
    renderText(0, 285, m_TexteNbBalle, QFont( "lucida", 10, QFont::Bold, TRUE ));
    renderText(325, 285, m_TexteLevel, QFont( "lucida", 10, QFont::Bold, TRUE ));
    renderText(575, 285, m_TexteScore, QFont( "lucida", 10, QFont::Bold, TRUE ));

}


void Jeu::rebondPalet(float xPalet, float xBalle){
    float vitesseAbsBalle = sqrt(vitesseBalleX*vitesseBalleX+vitesseBalleY*vitesseBalleY);
    float angleBalle = atan(vitesseBalleX/vitesseBalleY);
    float angleRebondBalle = -angleBalle+atan(1)*(xBalle-xPalet);
    vitesseBalleY = sqrt(vitesseAbsBalle*vitesseAbsBalle/(1+tan(angleRebondBalle)*tan(angleRebondBalle)));
    vitesseBalleX = sqrt(vitesseAbsBalle*vitesseAbsBalle-vitesseBalleY*vitesseBalleY);
}

void Jeu::pause(){
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}


