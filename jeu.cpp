#include "jeu.h"



// Constructeur
Jeu::Jeu(QWidget *parent) : QGLWidget(parent) {

    // Reglage de la taille/position
    //setFixedSize(WIN_WIDTH, WIN_HEIGHT);
    //move(QApplication::desktop()->screen()->rect().center() - rect().center());


    qInfo() << "posX: "<<posX<<" , posY: "<<posY;
    /*scene_=new QGraphicsScene(0,0,width(),height());
    QPen *pen=new QPen();
    QColor *color=new QColor(0,0,255);
    pen->setColor(*color);
    scene_->addEllipse(posX,posY,50,50,*pen,Qt::blue);
    setScene(scene_);*/
}

// Fonction d'initialisation
void Jeu::initializeGL()
{

    couleur.setRgb(200, 150, 50);
}


// Fonction de redimensionnement
void Jeu::resizeGL(int width, int height)
{
    // Declarations des constantes
    const unsigned int WIN_WIDTH  = 1600;
    const unsigned int WIN_HEIGHT = 900;
    const float ASPECT_RATIO      = static_cast<float>(WIN_WIDTH) / WIN_HEIGHT;
    const float ORTHO_DIM         = 50.0f;
    // Definition de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ORTHO_DIM * ASPECT_RATIO, ORTHO_DIM * ASPECT_RATIO, -ORTHO_DIM, ORTHO_DIM, -2.0f * ORTHO_DIM, 2.0f * ORTHO_DIM);

    // Definition de la matrice de modele
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Fonction d'affichage
void Jeu::paintGL()
{
    glClearColor(100.0,100.0,100.0,1.0); // Couleur à utiliser lorsqu’on va nettoyer la fenetre ( = le fond)

    // Reinitialisation du tampon de couleur
    glClear(GL_COLOR_BUFFER_BIT);
    // Reinitialisation de la matrice courante

    // Reglage de la couleur
    glColor3f(couleur.redF(),couleur.greenF(),couleur.blueF());
    // Debut de l'affichage
    glBegin(GL_TRIANGLES); // Primitive à afficher et début de la déclaration des vertices de cette primitive
    glVertex2f(25, 25);  // Déclaration des coordonnées des sommets (en 2D, z=0)
    glVertex2f(75, 75);
    glVertex2f(25, 75);
    glVertex2f(75, 25);
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
