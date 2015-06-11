#ifndef GRABBER_H
#define GRABBER_H

#include <QWidget>

namespace Ui {
class Grabber;
}

class Grabber : public QWidget
{
    Q_OBJECT

public:
    explicit Grabber(QWidget *parent = 0);
    ~Grabber();

private:
    Ui::Grabber *ui;
};

#endif // GRABBER_H
