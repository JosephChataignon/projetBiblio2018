#include "opencv2/opencv.hpp"
#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "widget.h"
#include "ui_widget.h"
#include <cstdio>
#include <iostream>
#include <QString>

using namespace cv;
using namespace std;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget){
    ui->setupUi(this);

    webCam_ = new VideoCapture(0); //ouvre la caméra par défaut
    int width  = webCam_->get(CV_CAP_PROP_FRAME_WIDTH);
    int height = webCam_->get(CV_CAP_PROP_FRAME_HEIGHT);

    if(!webCam_->isOpened()) { // vérification de la caméra
        ui->infoLabel_->setText("Error openning the default camera !");
    }
    else {
        ui->infoLabel_->setText(QString("Vidéo ok, taille de l'image: %1x%2 pixels").arg(width).arg(height));
        captureVid();
    }
}


Widget::~Widget()
{
    delete ui;
    delete webCam_;
}

void Widget::captureVid(){
    // INITIALISATION
    Mat frame1,frame2,frameRect1,frameRect2;
        int frameWidth=320;
        int frameHeight=240;
        int subImageWidth=100;
        int subImageHeight=100;
        int templateWidth=25;
        int templateHeight=25;
    Rect workingRect((frameWidth-subImageWidth)/2,frameHeight/2+(frameHeight/2-subImageHeight)/2,subImageWidth,subImageHeight);
    Rect templateRect((workingRect.width-templateWidth)/2,(workingRect.height-templateHeight)/2,templateWidth,templateHeight);
    Point workingCenter(workingRect.x+subImageWidth/2,workingRect.y+subImageHeight/2);
    // Récupération frame1
    *webCam_ >> frame1;
    // Effet miroir
    cv::flip(frame1,frame1,1);
    // Extraction de rect1 et conversion en NDG
    cv::cvtColor(Mat(frame1,workingRect),frameRect1,COLOR_BGR2GRAY);

    // Créer le résultat d'image MatchTemplate
    Mat resultImage;    // pour stocker le résultat matchTemplate
    int result_cols = frame1.cols-templateWidth  + 1;
    int result_rows = frame1.rows-templateHeight + 1;
    resultImage.create( result_cols, result_rows, CV_32FC1 );

    // Convert to Qt image
    QImage img= QImage((const unsigned char*)(frame1.data),frame1.cols,frame1.rows,QImage::Format_RGB888);
    // Display on label
    ui->imageLabel_->setPixmap(QPixmap::fromImage(img));
    // Resize the label to fit the image
    ui->imageLabel_->resize(ui->imageLabel_->pixmap()->size());

    while ( waitKey(5) < 0 ) {
        // Récupération frame2
        *webCam_ >> frame2;
        // Effet miroir
        cv::flip(frame2,frame2,1);
        // Extrait workingRect de frame2 et conversion en NDG
        cv::cvtColor(Mat(frame2,workingRect),frameRect2,COLOR_BGR2GRAY);

        // Extrait l'image template de frame1
        Mat templateImage(frameRect1,templateRect);
        // Fait la correspondance entre le workingRect de frame2 et le templateImage de frame1
        matchTemplate( frameRect2, templateImage, resultImage, TM_CCORR_NORMED );
        // Localise la meilleure correspondance avec minMaxLoc
        double minVal; double maxVal; Point minLoc; Point maxLoc;
        minMaxLoc( resultImage, &minVal, &maxVal, &minLoc, &maxLoc);
        // Calcule le vecteur de translation entre l'origine et le matching rect
        Point vect(maxLoc.x-templateRect.x,maxLoc.y-templateRect.y);

        // Dessine le rectangle vert et le vecteur de translation
        rectangle(frame2,workingRect,Scalar( 0, 255, 0),2);
        Point p(workingCenter.x+vect.x,workingCenter.y+vect.y);
        arrowedLine(frame2,workingCenter,p,Scalar(255,255,255),2);

        // Convert to Qt image
        QImage img= QImage((const unsigned char*)(frame2.data),frame2.cols,frame2.rows,QImage::Format_RGB888);
        // Display on label
        ui->imageLabel_->setPixmap(QPixmap::fromImage(img));
        // Resize the label to fit the image
        ui->imageLabel_->resize(ui->imageLabel_->pixmap()->size());

        // Display frame2
        //imshow(ui->imageLabel_, frame2);

        // Swap matrixes
        swap(frameRect1,frameRect2);
    }

}












