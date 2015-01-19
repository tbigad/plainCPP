#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_pushButton_clicked();
    void on_numberButton_1_clicked();

    void on_numberButton_2_clicked();

    void on_numberButton_3_clicked();

    void on_numberButton_4_clicked();

    void on_numberButton_5_clicked();

    void on_numberButton_6_clicked();

    void on_numberButton_7_clicked();

    void on_numberButton_8_clicked();

    void on_numberButton_9_clicked();

    void on_numberButton_0_clicked();

    void on_plusButton_clicked();

    void on_minusButton_clicked();

    void on_multiplicationButton_clicked();

    void on_divisionButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
