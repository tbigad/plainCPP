#include "simplewindow.h"
#include <QDebug>

SimpleWindow::SimpleWindow(QWidget *parent)
    : QWidget(parent, Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint|Qt::CustomizeWindowHint),
      mFrameless(new FramelessHelper)
{
    setMouseTracking(true);
    mFrameless->activateOn(this);
    mFrameless->setWidgetMovable(true);
    mFrameless->setWidgetResizable(true);
}

SimpleWindow::~SimpleWindow()
{
}

