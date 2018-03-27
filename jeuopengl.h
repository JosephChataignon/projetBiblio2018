#ifndef JEUOPENGL_H
#define JEUOPENGL_H

#include <QGLWidget>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>
#include "brique.h"

class jeuOpenGL: public QGLWidget
{
    Q_OBJECT

public:

    // Constructeur
    jeuOpenGL(QWidget * parent = nullptr);

protected:

    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();
private:
    std::vector<brique*>tabBrique;

};

#endif // JEUOPENGL_H
