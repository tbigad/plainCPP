#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QtXml>
#include <QErrorMessage>

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
    QString _filePath;
    QFile _qFile;
    QDomDocument _domDoc;
void printTree(QDomDocument doc);

};

#endif // MAINWINDOW_H
