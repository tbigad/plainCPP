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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QLineEdit *filePath;
    QPushButton *openFileButton_1;
    QPushButton *playButton_1;
    QPushButton *pauseButton_1;
    QPushButton *stopButton_1;
    QSlider *volumeSlider;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(472, 287);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Horizontal);
        filePath = new QLineEdit(splitter);
        filePath->setObjectName(QStringLiteral("filePath"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(120);
        sizePolicy1.setVerticalStretch(25);
        sizePolicy1.setHeightForWidth(filePath->sizePolicy().hasHeightForWidth());
        filePath->setSizePolicy(sizePolicy1);
        filePath->setMaximumSize(QSize(850, 25));
        filePath->setReadOnly(true);
        splitter->addWidget(filePath);
        openFileButton_1 = new QPushButton(splitter);
        openFileButton_1->setObjectName(QStringLiteral("openFileButton_1"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(openFileButton_1->sizePolicy().hasHeightForWidth());
        openFileButton_1->setSizePolicy(sizePolicy2);
        splitter->addWidget(openFileButton_1);
        playButton_1 = new QPushButton(splitter);
        playButton_1->setObjectName(QStringLiteral("playButton_1"));
        sizePolicy2.setHeightForWidth(playButton_1->sizePolicy().hasHeightForWidth());
        playButton_1->setSizePolicy(sizePolicy2);
        splitter->addWidget(playButton_1);
        pauseButton_1 = new QPushButton(splitter);
        pauseButton_1->setObjectName(QStringLiteral("pauseButton_1"));
        sizePolicy2.setHeightForWidth(pauseButton_1->sizePolicy().hasHeightForWidth());
        pauseButton_1->setSizePolicy(sizePolicy2);
        splitter->addWidget(pauseButton_1);
        stopButton_1 = new QPushButton(splitter);
        stopButton_1->setObjectName(QStringLiteral("stopButton_1"));
        sizePolicy2.setHeightForWidth(stopButton_1->sizePolicy().hasHeightForWidth());
        stopButton_1->setSizePolicy(sizePolicy2);
        splitter->addWidget(stopButton_1);

        verticalLayout->addWidget(splitter);

        volumeSlider = new QSlider(centralWidget);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setMaximum(100);
        volumeSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(volumeSlider);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        volumeSlider->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 472, 19));
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
        playButton_1->setText(QApplication::translate("MainWindow", "Play", 0));
        pauseButton_1->setText(QApplication::translate("MainWindow", "Pause", 0));
        stopButton_1->setText(QApplication::translate("MainWindow", "Stop", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
