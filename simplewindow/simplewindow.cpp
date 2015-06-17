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
}

void SimpleWindow::updateGeometry()
{
    if (_initial == QPoint(-1,-1)) {
        return;
    }

    auto x = qMin(_initial.x(), _current.x());
    auto y = qMin(_initial.y(), _current.y());
    auto w = abs(_initial.x() - _current.x());
    auto h = abs(_initial.y() - _current.y());

    setGeometry(x, y, w, h);
}

void SimpleWindow::mousePressEvent(QMouseEvent *event)
{
    // save click position
    if (event->button() == Qt::LeftButton) {
        this->setCursor(Qt::ClosedHandCursor);
        m_dragPosition = event->globalPos() - frameGeometry().topLeft();

        _initial = event->pos();
        _current = event->pos();

        //event->accept();
    }
}

void SimpleWindow::mouseReleaseEvent(QMouseEvent *event)
{
    // save click position
    if (event->button() == Qt::LeftButton) {
        this->setCursor(Qt::ArrowCursor);

        _current = QPoint(-1,-1);
        _initial = QPoint(-1,-1);

        //event->accept();
    }
}

void SimpleWindow::mouseMoveEvent(QMouseEvent *event)
{
    // drag window
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPos() - m_dragPosition);

        _current = event->pos();
        updateGeometry();

        //event->accept();
    }
}
