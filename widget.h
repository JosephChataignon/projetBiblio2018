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
    explicit Widget(QWidget *parent = 0);
    void setVect(Point v){ vect = v; }
    cv::Point getVect(){ return vect; }
    ~Widget();

private:
    Ui::Widget *ui;
    Mat frame;
    QTimer* time;
    gestionCam *cam;
    cv::Point vect;

private slots:
    void video();
};

#endif // WIDGET_H
