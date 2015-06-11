#include "RegionGrabber.h"
#include <QApplication>
#include <QDesktopWidget>
RegionGrabber::RegionGrabber()
{
    QPainter pd(QApplication::desktop());
    QLineF line(10.0, 80.0, 90.0, 20.0);
    pd.drawLine(line);
}



