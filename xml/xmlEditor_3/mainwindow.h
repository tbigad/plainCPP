#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QStandardItem>
#include <QStandardItemModel>
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
    void startTree();

private:
    Ui::MainWindow *ui;

    void insertFather(QString name);
    void insertChildren(QString name);
    void setItem(QStandardItemModel *model);
    void preOrder(QDomNode dom, QStandardItemModel *model);

    QStandardItem *item;
    int nRow;
    QStandardItemModel *model;
    QDomDocument doc;
};

#endif // MAINWINDOW_H
