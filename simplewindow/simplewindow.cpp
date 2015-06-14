#include "simplewindow.h"
#include <QDebug>

SimpleWindow::SimpleWindow(QWidget *parent)
    :QWidget(parent, Qt::Window|Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint|Qt::CustomizeWindowHint)
{
}

SimpleWindow::~SimpleWindow()
{
}

void SimpleWindow::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    if(event->button() == Qt::LeftButton)
        qDebug()<<"LMB pressed!";
    if(event->button() == Qt::RightButton)
    {
        qDebug()<<"RMB pressed!";
        _gmp = event->globalPos();
    }
}

void SimpleWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
        {
        this->move(mapToParent(event->pos()-_gmp));
        qDebug()<<"x: "<< _gmp.x();
        qDebug()<<"y: "<< _gmp.y();
        }
}
