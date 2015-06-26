#include "simplewindow.h"
#include "fullscreenhelper.h"

#include <QDebug>

SimpleWindow::SimpleWindow(QWidget *parent)
    : QWidget(parent, Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint|Qt::CustomizeWindowHint),
      mFrameless(new FramelessHelper)
{
    FullScreenHelper::MaximizeOnVirtualScreen(this);
    setWindowOpacity(0.05);
    setCursor(Qt::CrossCursor);
    widgetCreated = false;
}

SimpleWindow::~SimpleWindow()
{
}

void SimpleWindow::mousePressEvent(QMouseEvent *event)
{
    switch (event->button()) {
    case Qt::LeftButton:
        if(widgetCreated)
            return;
        mStartDragPos = event->globalPos();
        mLeftBtnPressed = true;
        break;
    case Qt::RightButton:
        this->close();
        break;
    default:
        return;
    }
}

void SimpleWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(widgetCreated)
        return;

    if(mLeftBtnPressed)
    setSizeWidget(event->globalPos());
}

void SimpleWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(widgetCreated){
        return;
        mLeftBtnPressed = false;
    }

    if((this->size().height()< 10) && (this->size().width()< 10) )
    {
        this->showMaximized();
        return;
    }

    if (!(this->isFullScreen() || this->isMaximized())){
        mFrameless->activateOn(this);
        mFrameless->setWidgetMovable(true);
        mFrameless->setWidgetResizable(true);
        widgetCreated = true;
    }
}

void SimpleWindow::setSizeWidget(QPoint moveMousePos)
{
    if(widgetCreated && mLeftBtnPressed)
        return;

    setWindowOpacity(0.5);
    QPoint topLeft, bottonRight;
    topLeft = mStartDragPos;
    bottonRight = moveMousePos;
    if(topLeft.x()>bottonRight.x())
    {
         topLeft.setX(bottonRight.x());
         bottonRight.setX(mStartDragPos.x());
    }
    if(topLeft.y()>bottonRight.y())
    {
        topLeft.setY(bottonRight.y());
        bottonRight.setY(mStartDragPos.y());
    }

    QRect initRect(topLeft,bottonRight);
    setGeometry(initRect);
    raise();
}

void SimpleWindow::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    QPen pen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    paint.setPen(pen);
    QRectF rec(rect().topLeft(),size());
    paint.setOpacity(2);
    paint.drawRect(rec);
}
