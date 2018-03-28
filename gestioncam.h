#ifndef GESTIONCAM_H
#define GESTIONCAM_H
#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <QDebug>

using namespace std;
using namespace cv;
class gestionCam
{
public:
    gestionCam();
    ~gestionCam();
    Mat imageVideo();

    void setVect(Point v){ vect = v; }
    cv::Point getVect(){ return vect; }

private:
    VideoCapture * webCam_;
    cv::Point vect;

};

#endif // GESTIONCAM_H
