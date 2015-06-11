#include "grabber.h"
#include "ui_grabber.h"

Grabber::Grabber(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Grabber)
{
    ui->setupUi(this);

}

Grabber::~Grabber()
{
    delete ui;
}
