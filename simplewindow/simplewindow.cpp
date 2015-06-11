#include "simplewindow.h"
#include <QDebug>


SimpleWindow::SimpleWindow()
{
    wg = new QWidget;
    wg->setWindowFlags(Qt::Window|Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint|Qt::CustomizeWindowHint);
    wg->show();
    qDebug()<<"widget Created";
}

SimpleWindow::~SimpleWindow()
{
    delete wg;
}

void SimpleWindow::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    if(event->button() == Qt::LeftButton)
        qDebug()<<"pressed!";

}
