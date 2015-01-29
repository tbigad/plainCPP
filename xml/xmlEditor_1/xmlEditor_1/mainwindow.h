#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtXml>
#include <QString>
#include <QFileDialog>
#include "domitem.h"
#include "dommodel.h"

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
    DomModel *model;
    QMenu *fileMenu;
    QString xmlPath;
public slots:
    void openFile();


};

#endif // MAINWINDOW_H
