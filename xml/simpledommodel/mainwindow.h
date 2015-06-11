#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

class DomModel;
class QMenu;
class QTreeView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

public slots:
    void openFile();

private:
    DomModel *model;
    QMenu *fileMenu;
    QString xmlPath;
    QTreeView *view;
};

#endif // MAINWINDOW_H