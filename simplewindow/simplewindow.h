#ifndef SIMPLEWINDOW_H
#define SIMPLEWINDOW_H
#include <QWidget>
#include <QtGui/QMouseEvent>

class QMouseEvent;

class SimpleWindow: QWidget
{
  // Q_OBJECT
public:
    SimpleWindow();
   ~SimpleWindow();
private:
    QWidget *wg;
protected:
    void mousePressEvent(QMouseEvent *event);

};

#endif // SIMPLEWINDOW_H
