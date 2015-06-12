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
        qDebug()<<"RMB pressed!";
}

void SimpleWindow::mouseMoveEvent(QMouseEvent *event)
{
    _gmp = event->globalPos();
    qDebug()<<"x: "<< _gmp.x();
    qDebug()<<"y: "<< _gmp.y();
}
