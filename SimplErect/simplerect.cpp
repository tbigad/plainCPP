#include "simplerect.h"

SimpleRect::SimpleRect()
{
    wg = new QWidget;
    wg->show();
}

SimpleRect::~SimpleRect()
{
    delete wg;
}

