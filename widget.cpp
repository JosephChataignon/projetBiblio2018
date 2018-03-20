#include "opencv2/opencv.hpp"
#include "widget.h"
#include "ui_widget.h"
#include <QString>
using namespace cv;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    camera = new gestionCam();

    time = new QTimer(this);
    connect(time,SIGNAL(timeout()),this,SLOT(video()));
    time->start(20);
}


Widget::~Widget(){
    delete ui;
}


void Widget::video() {

    QImage img = camera->capture();
    // Display on label
    ui->imageLabel_->setPixmap(QPixmap::fromImage(img));
    // Resize the label to fit the image
    ui->imageLabel_->resize(ui->imageLabel_->pixmap()->size());

}
