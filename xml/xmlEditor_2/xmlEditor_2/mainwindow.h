#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>
#include <QtXml>
#include "TreeItem.h"
#include "TreeModel.h"
#include <QStringList>


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
    void selectTreeItem(QModelIndex index);
    void saveFile();
    void changeItem(int row, int col);

private:
    Ui::MainWindow *ui;
    void printNodes(QDomNode dNode, TreeItem *item);
    void readXml(const QString &xmlContent);
    TreeModel *model;
    void setRowCol(int row, int col);
    QStringList headerList;
};

#endif // MAINWINDOW_H
