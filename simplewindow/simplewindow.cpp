#include "simplewindow.h"

SimpleWindow::SimpleWindow()
{
    wg = new QWidget;
    wg->setWindowFlags(Qt::Window|Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint|Qt::CustomizeWindowHint);
    wg->show();
}

SimpleWindow::~SimpleWindow()
{
    delete wg;
}
