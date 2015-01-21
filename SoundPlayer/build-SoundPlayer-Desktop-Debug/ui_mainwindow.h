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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_separated_file;
    QAction *actionOpen_file_with_appending_to_playlist;
    QAction *actionCreate_playlist_from_directory;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTableWidget *playlist;
    QLabel *label_2;
    QSlider *volumeSlider;
    QHBoxLayout *horizontalLayout;
    QPushButton *playButton;
    QPushButton *pauseButton;
    QPushButton *stopButton;
    QPushButton *muteButton;
    QMenuBar *menuBar;
    QMenu *menuFile_menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(675, 399);
        actionOpen_separated_file = new QAction(MainWindow);
        actionOpen_separated_file->setObjectName(QStringLiteral("actionOpen_separated_file"));
        actionOpen_file_with_appending_to_playlist = new QAction(MainWindow);
        actionOpen_file_with_appending_to_playlist->setObjectName(QStringLiteral("actionOpen_file_with_appending_to_playlist"));
        actionCreate_playlist_from_directory = new QAction(MainWindow);
        actionCreate_playlist_from_directory->setObjectName(QStringLiteral("actionCreate_playlist_from_directory"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        playlist = new QTableWidget(centralWidget);
        playlist->setObjectName(QStringLiteral("playlist"));
        playlist->setEditTriggers(QAbstractItemView::NoEditTriggers);
        playlist->setTabKeyNavigation(false);
        playlist->setRowCount(0);
        playlist->setColumnCount(0);

        verticalLayout->addWidget(playlist);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setPointSize(20);
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        volumeSlider = new QSlider(centralWidget);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(volumeSlider->sizePolicy().hasHeightForWidth());
        volumeSlider->setSizePolicy(sizePolicy);
        volumeSlider->setMaximumSize(QSize(16777215, 16777215));
        volumeSlider->setBaseSize(QSize(14464, 0));
        volumeSlider->setPageStep(10);
        volumeSlider->setValue(50);
        volumeSlider->setOrientation(Qt::Horizontal);
        volumeSlider->setTickPosition(QSlider::TicksAbove);

        verticalLayout->addWidget(volumeSlider);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        playButton = new QPushButton(centralWidget);
        playButton->setObjectName(QStringLiteral("playButton"));

        horizontalLayout->addWidget(playButton);

        pauseButton = new QPushButton(centralWidget);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));

        horizontalLayout->addWidget(pauseButton);

        stopButton = new QPushButton(centralWidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));

        horizontalLayout->addWidget(stopButton);

        muteButton = new QPushButton(centralWidget);
        muteButton->setObjectName(QStringLiteral("muteButton"));

        horizontalLayout->addWidget(muteButton);


        verticalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 675, 19));
        menuFile_menu = new QMenu(menuBar);
        menuFile_menu->setObjectName(QStringLiteral("menuFile_menu"));
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

        menuBar->addAction(menuFile_menu->menuAction());
        menuFile_menu->addAction(actionOpen_separated_file);
        menuFile_menu->addAction(actionOpen_file_with_appending_to_playlist);
        menuFile_menu->addAction(actionCreate_playlist_from_directory);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionOpen_separated_file->setText(QApplication::translate("MainWindow", "Open separated file (without appending to playlist)", 0));
        actionOpen_file_with_appending_to_playlist->setText(QApplication::translate("MainWindow", "Open file (with appending to playlist)", 0));
        actionCreate_playlist_from_directory->setText(QApplication::translate("MainWindow", "Create playlist from directory", 0));
        label_2->setText(QApplication::translate("MainWindow", "Volume", 0));
        playButton->setText(QApplication::translate("MainWindow", "Play", 0));
        pauseButton->setText(QApplication::translate("MainWindow", "Pause", 0));
        stopButton->setText(QApplication::translate("MainWindow", "Stop", 0));
        muteButton->setText(QApplication::translate("MainWindow", "Mute", 0));
        menuFile_menu->setTitle(QApplication::translate("MainWindow", "File menu", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
