#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "simplewindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();
    void closeEvent(QCloseEvent *event);

private slots:
    void on_pushButton_clicked();

private:
    QVector<QSharedPointer<SimpleWindow> > sWinVec;

    Ui::MainWindow *ui;
    //SimpleWindow *win;

};

#endif // MAINWINDOW_H
