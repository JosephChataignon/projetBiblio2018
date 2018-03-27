#include "jeuopengl.h"
#include <GL/glu.h>
#include <QApplication>
#include <QDesktopWidget>

// Declarations des constantes
const unsigned int WIN_WIDTH  = 700;
const unsigned int WIN_HEIGHT = 300;
const float ASPECT_RATIO      = static_cast<float>(WIN_WIDTH) / WIN_HEIGHT;
const float ORTHO_DIM         = 10.0f;

jeuOpenGL::jeuOpenGL(QWidget * parent) : QGLWidget(parent)
{
    // Reglage de la taille/position
    setFixedSize(WIN_WIDTH, WIN_HEIGHT);
    move(QApplication::desktop()->screen()->rect().center() - rect().center());

    tabBrique.push_back(new brique(4,0,0));
    tabBrique.push_back(new brique(0,0,0));
    tabBrique.push_back(new brique(8,0,0));
    tabBrique.push_back(new brique(12,0,0));
}

void jeuOpenGL::initializeGL()
{
    // Reglage de la couleur de fond
    glClearColor(0.5,0.5,0.5,1);
    // Activation du zbuffer
    glEnable(GL_DEPTH_TEST);

}

void jeuOpenGL::resizeGL(int width, int height)
{

    // Definition du viewport (zone d'affichage)
    glViewport(0,0,width,height);
    // Definition de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ORTHO_DIM * ASPECT_RATIO, ORTHO_DIM * ASPECT_RATIO, -ORTHO_DIM, ORTHO_DIM, -2.0f * ORTHO_DIM, 2.0f * ORTHO_DIM);

}

void jeuOpenGL::paintGL()
{
    // Reinitialisation des tampons
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    // Definition de la matrice modelview
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,1,1,0,0,0,0,1,0);
    glPushMatrix();
    for(int i=0;i<tabBrique.size();i++){
       tabBrique[i]->displayBrique();
       glPopMatrix();
    }


}
