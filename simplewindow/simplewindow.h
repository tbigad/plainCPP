#ifndef SIMPLEWINDOW_H
#define SIMPLEWINDOW_H
#include <QWidget>
#include <QtGui/QMouseEvent>

class QMouseEvent;

class SimpleWindow: public QWidget
{
public:
    SimpleWindow(QWidget *parent = 0);
   ~SimpleWindow();
private:
    QPoint _wmp;//Widget Mouse Point
    QPoint _cmp;//Current Mouse Point

    QPoint m_dragPosition;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // SIMPLEWINDOW_H
