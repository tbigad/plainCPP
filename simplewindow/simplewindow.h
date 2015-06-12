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
    QWidget *wg;
protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // SIMPLEWINDOW_H
