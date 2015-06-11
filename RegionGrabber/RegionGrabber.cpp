#include "RegionGrabber.h"
#include <QVBoxLayout>
#include <QSizeGrip>

RegionGrabber::RegionGrabber(QWidget *parent) : QWidget(parent)
{

    this->setWindowFlags(Qt::Window|Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint|Qt::CustomizeWindowHint);
    this->setWindowOpacity(1);


    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(QMargins());
    layout->setSpacing(0);
    layout->addWidget(new QSizeGrip(this),0, Qt::AlignBottom | Qt::AlignRight | Qt::AlignAbsolute);

    this->show();


}
