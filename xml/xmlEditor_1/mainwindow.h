#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "classxmleditor.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void addFile();

private:
    void xmlToTreeWidget(const QString file);
    Ui::MainWindow *ui;
    QString _file;
    classXmlEditor _editor;
};

#endif // MAINWINDOW_H
