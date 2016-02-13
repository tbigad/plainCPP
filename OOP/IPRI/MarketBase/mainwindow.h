#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "market.h"
#include <QListWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_addButton_pressed();

    void on_buyButton_pressed();

    void on_editButton_pressed();

private:
    Ui::MainWindow *ui;
    Market* market;
    void update();
    int currentID = 0;
};

#endif // MAINWINDOW_H
