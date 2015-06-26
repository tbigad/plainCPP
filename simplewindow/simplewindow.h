#ifndef SIMPLEWINDOW_H
#define SIMPLEWINDOW_H

#include "FramelessHelper.h"
#include <QWidget>
#include <QMouseEvent>
#include <QPainter>


//class QMouseEvent;

class SimpleWindow: public QWidget
{
public:
    SimpleWindow(QWidget *parent = 0);
   ~SimpleWindow();
private:
    FramelessHelper* mFrameless;
    void setSizeWidget(QPoint moveMousePos);

    QPoint mStartDragPos;

    bool mLeftBtnPressed;
    bool widgetCreated;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
};

#endif // SIMPLEWINDOW_H
