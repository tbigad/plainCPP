#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "market.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Market* market;
    void update();
};

#endif // MAINWINDOW_H
