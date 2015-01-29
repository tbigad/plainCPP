#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>
#include <QtXml>


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
    void openFile();

private:
    Ui::MainWindow *ui;
    void printNodes(QDomNode dNode, QStandardItem *item);
    void readXml(const QString &xmlContent);
};

#endif // MAINWINDOW_H
