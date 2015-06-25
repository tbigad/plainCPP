#include "fullscreenhelper.h"

#include <QDesktopWidget>
#include <QApplication>

void FullScreenHelper::MaximizeOnVirtualScreen(QWidget *widget)
{
    if (!widget)
        return;

    QDesktopWidget* m = QApplication::desktop();
    widget->setGeometry(0, 0, m->width(), m->height());
}
