#ifndef GESTIONCAM_H
#define GESTIONCAM_H
#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace std;
using namespace cv;
class gestionCam
{
public:
    gestionCam();
    ~gestionCam();
    Mat imageVideo();
private:
    VideoCapture * webCam_;

};

#endif // GESTIONCAM_H
