#include "simplewindow.h"
#include <QDebug>
#include <QRect>

SimpleWindow::SimpleWindow(QWidget *parent)
    :QWidget(parent, Qt::Window|Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint|Qt::CustomizeWindowHint)
{
    setMouseTracking(true);
}

SimpleWindow::~SimpleWindow()
{
    setMouseTracking(true);
}

void SimpleWindow::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    if(event->button() == Qt::LeftButton)
    {
        qDebug()<<"LMB pressed!";
    }
    if(event->button() == Qt::RightButton)
    {
        _wmp = event->pos();
        qDebug()<<"RMB pressed!";
    }


}

void SimpleWindow::mouseMoveEvent(QMouseEvent *event)
{
    this->setCursor(Qt::OpenHandCursor);
    _cmp = event->globalPos();
    qDebug()<<"Current pos: x:"<<_cmp.x() << "y: " <<_cmp.y();
    qDebug()<<"Current geometry left:"<<this->geometry().left()<< "right: "<<this->geometry().right();
    qDebug()<<"top: "<<this->geometry().top();

    if(event->buttons() & Qt::RightButton)
        {
        this->setCursor(Qt::ClosedHandCursor);
        this->move(event->globalPos()-_wmp);
        }

    if((_cmp.x() - this->geometry().left()) < 5)
    {
        qDebug()<<"On LEFT Border!!!!";
        this->setCursor(Qt::SizeHorCursor);
    }

    if((_cmp.y() - this->geometry().top()) < 5)
    {
        qDebug()<<"On TOP Border!!!!";
        this->setCursor(Qt::SizeVerCursor);
    }
    if((_cmp.x() + this->geometry().right()) < 5)
    {
        qDebug()<<"On RIGHT Border!!!!";
        this->setCursor(Qt::SizeHorCursor);
    }
    if((_cmp.y() + this->geometry().bottom()) < 5)
    {
        qDebug()<<"On BOTTOM Border!!!!";
        this->setCursor(Qt::SizeVerCursor);
    }

    if(event->button() == Qt::LeftButton)
    {
        if((_cmp.x() - this->geometry().left()) < 5)
        {
           qDebug()<<"Ready to resize";
           this->resize(_cmp.x(), this->geometry().y());
        }
    }
}
