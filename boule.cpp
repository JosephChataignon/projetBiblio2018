#include "boule.h"
boule::boule(QWidget *parent) :
    QGraphicsView(parent)
{
    scene_=new QGraphicsScene(0,0,width(),height());
    QPen *pen=new QPen();
    QColor *color=new QColor(0,0,255);
    pen->setColor(*color);
    scene_->addEllipse(0,0,50,50,*pen,Qt::blue);
    setScene(scene_);

}
