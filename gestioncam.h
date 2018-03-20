#ifndef GESTIONCAM_H
#define GESTIONCAM_H

#include <QImage>
#include "opencv2/opencv.hpp"
using namespace cv;

class gestionCam : public QWidget {
    Q_OBJECT
public:
    gestionCam();   // constructeur
    ~gestionCam();  // destructeur
    QImage capture();      //capture d'une image

private:
    VideoCapture * webCam_;



};

#endif // GESTIONCAM_H
