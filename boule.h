#ifndef BOULE_H
#define BOULE_H

#include <QWidget>
#include <QGraphicsScene>
#include "QGraphicsView"

class boule : public QGraphicsView
{
    Q_OBJECT
public:
    explicit boule(QWidget *parent = 0);

public slots:
private:
    QGraphicsScene *scene_;
};
#endif // BOULE_H
