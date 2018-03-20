#ifndef VIDEO_H
#define VIDEO_H

#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <cstdio>
#include <iostream>

using namespace cv;
using namespace std;

class video
{
public:
    video(VideoCapture cap);

};

#endif // VIDEO_H
