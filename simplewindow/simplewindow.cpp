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
    //setMouseTracking(false);
}

void SimpleWindow::mousePressEvent(QMouseEvent *event)
{
    // save click position
    if (event->button() == Qt::LeftButton) {
        this->setCursor(Qt::ClosedHandCursor);
        m_dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void SimpleWindow::mouseReleaseEvent(QMouseEvent *event)
{
    // save click position
    if (event->button() == Qt::LeftButton) {
        this->setCursor(Qt::ArrowCursor);
        event->accept();
    }
}

void SimpleWindow::mouseMoveEvent(QMouseEvent *event)
{
    // drag window
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPos() - m_dragPosition);
        event->accept();
    }
}
