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
        _wmp = event->pos();
    if(event->button() == Qt::RightButton)
    {
        qDebug()<<"RMB pressed!";
    }
}

void SimpleWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
        {
        this->move(event->globalPos()-_wmp);
        qDebug()<<"x: "<< event->globalPos().x();
        qDebug()<<"y: "<< event->globalPos().y();
        }
}
