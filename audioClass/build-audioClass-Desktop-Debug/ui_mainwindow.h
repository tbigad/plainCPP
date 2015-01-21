/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *filePath;
    QPushButton *openFileButton_1;
    QPushButton *stopButton_1;
    QPushButton *playButton_1;
    QPushButton *pauseButton_1;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QSlider *volumeSlider;
    QSlider *seekSlider;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(550, 321);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(9, 0, 511, 91));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(50, 0, 0, 0);
        filePath = new QLineEdit(gridLayoutWidget);
        filePath->setObjectName(QStringLiteral("filePath"));
        filePath->setReadOnly(true);

        gridLayout->addWidget(filePath, 0, 0, 1, 1, Qt::AlignHCenter);

        openFileButton_1 = new QPushButton(gridLayoutWidget);
        openFileButton_1->setObjectName(QStringLiteral("openFileButton_1"));

        gridLayout->addWidget(openFileButton_1, 0, 1, 1, 1);

        stopButton_1 = new QPushButton(gridLayoutWidget);
        stopButton_1->setObjectName(QStringLiteral("stopButton_1"));

        gridLayout->addWidget(stopButton_1, 0, 4, 1, 1);

        playButton_1 = new QPushButton(gridLayoutWidget);
        playButton_1->setObjectName(QStringLiteral("playButton_1"));

        gridLayout->addWidget(playButton_1, 0, 2, 1, 1);

        pauseButton_1 = new QPushButton(gridLayoutWidget);
        pauseButton_1->setObjectName(QStringLiteral("pauseButton_1"));

        gridLayout->addWidget(pauseButton_1, 0, 3, 1, 1);

        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 100, 511, 151));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        volumeSlider = new QSlider(verticalLayoutWidget);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setMaximum(100);
        volumeSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(volumeSlider);

        seekSlider = new QSlider(verticalLayoutWidget);
        seekSlider->setObjectName(QStringLiteral("seekSlider"));
        seekSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(seekSlider);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 550, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        openFileButton_1->setText(QApplication::translate("MainWindow", "...", 0));
        stopButton_1->setText(QApplication::translate("MainWindow", "Stop", 0));
        playButton_1->setText(QApplication::translate("MainWindow", "Play", 0));
        pauseButton_1->setText(QApplication::translate("MainWindow", "Pause", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
