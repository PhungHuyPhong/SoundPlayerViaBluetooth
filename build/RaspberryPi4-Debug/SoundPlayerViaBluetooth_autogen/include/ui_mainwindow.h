/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_Previous;
    QPushButton *pushButton_Next;
    QLabel *label_current_Time;
    QLabel *label_songTitle;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Volume;
    QSlider *horizontalSlider_Volume;
    QLabel *label_Total_Time;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_Seek_Backward;
    QPushButton *pushButton_Play_Pause;
    QPushButton *pushButton_Stop;
    QPushButton *pushButton_Seek_Forward;
    QGroupBox *groupBox_Video;
    QSlider *horizontalSlider_Duration;
    QPushButton *pushButton_AddSong;
    QPushButton *pushButton_SavePlaylist;
    QPushButton *pushButton_LoadPlaylist;
    QListWidget *playlistWidget;
    QPushButton *pushButton_Bluetooth;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1962, 1186);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(429, 659, 351, 102));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_Previous = new QPushButton(layoutWidget);
        pushButton_Previous->setObjectName("pushButton_Previous");
        pushButton_Previous->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    border-radius: 50px;\n"
"    background-color: rgb(255, 255, 255);\n"
"    color: rgb(52, 51, 64);\n"
"    min-width: 100px;\n"
"    max-width: 100px;\n"
"    min-height: 100px;\n"
"    max-height: 100px;\n"
"    padding: 0px;\n"
"}\n"
""));

        horizontalLayout_3->addWidget(pushButton_Previous);

        pushButton_Next = new QPushButton(layoutWidget);
        pushButton_Next->setObjectName("pushButton_Next");
        pushButton_Next->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    border-radius: 50px;\n"
"    background-color: rgb(255, 255, 255);\n"
"    color: rgb(52, 51, 64);\n"
"    min-width: 100px;\n"
"    max-width: 100px;\n"
"    min-height: 100px;\n"
"    max-height: 100px;\n"
"    padding: 0px;\n"
"}\n"
""));

        horizontalLayout_3->addWidget(pushButton_Next);

        label_current_Time = new QLabel(centralwidget);
        label_current_Time->setObjectName("label_current_Time");
        label_current_Time->setGeometry(QRect(260, 480, 82, 27));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label_current_Time->setFont(font);
        label_songTitle = new QLabel(centralwidget);
        label_songTitle->setObjectName("label_songTitle");
        label_songTitle->setGeometry(QRect(1159, 229, 291, 141));
        QFont font1;
        font1.setPointSize(19);
        font1.setBold(true);
        label_songTitle->setFont(font1);
        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(880, 530, 231, 102));
        horizontalLayout = new QHBoxLayout(layoutWidget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_Volume = new QPushButton(layoutWidget_2);
        pushButton_Volume->setObjectName("pushButton_Volume");
        pushButton_Volume->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    border-radius: 50px;\n"
"    background-color: rgb(255, 255, 255);\n"
"    color: rgb(52, 51, 64);\n"
"    min-width: 100px;\n"
"    max-width: 100px;\n"
"    min-height: 100px;\n"
"    max-height: 100px;\n"
"    padding: 0px;\n"
"}\n"
""));

        horizontalLayout->addWidget(pushButton_Volume);

        horizontalSlider_Volume = new QSlider(layoutWidget_2);
        horizontalSlider_Volume->setObjectName("horizontalSlider_Volume");
        horizontalSlider_Volume->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout->addWidget(horizontalSlider_Volume);

        label_Total_Time = new QLabel(centralwidget);
        label_Total_Time->setObjectName("label_Total_Time");
        label_Total_Time->setGeometry(QRect(1037, 480, 82, 27));
        label_Total_Time->setFont(font);
        layoutWidget_3 = new QWidget(centralwidget);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(251, 519, 491, 102));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_Seek_Backward = new QPushButton(layoutWidget_3);
        pushButton_Seek_Backward->setObjectName("pushButton_Seek_Backward");
        pushButton_Seek_Backward->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    border-radius: 50px;\n"
"    background-color: rgb(255, 255, 255);\n"
"    color: rgb(52, 51, 64);\n"
"    min-width: 100px;\n"
"    max-width: 100px;\n"
"    min-height: 100px;\n"
"    max-height: 100px;\n"
"    padding: 0px;\n"
"}\n"
""));

        horizontalLayout_2->addWidget(pushButton_Seek_Backward);

        pushButton_Play_Pause = new QPushButton(layoutWidget_3);
        pushButton_Play_Pause->setObjectName("pushButton_Play_Pause");
        pushButton_Play_Pause->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    border-radius: 50px;\n"
"    background-color: rgb(255, 255, 255);\n"
"    color: rgb(52, 51, 64);\n"
"    min-width: 100px;\n"
"    max-width: 100px;\n"
"    min-height: 100px;\n"
"    max-height: 100px;\n"
"    padding: 0px;\n"
"}\n"
""));

        horizontalLayout_2->addWidget(pushButton_Play_Pause);

        pushButton_Stop = new QPushButton(layoutWidget_3);
        pushButton_Stop->setObjectName("pushButton_Stop");
        pushButton_Stop->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    border-radius: 50px;\n"
"    background-color: rgb(255, 255, 255);\n"
"    color: rgb(52, 51, 64);\n"
"    min-width: 100px;\n"
"    max-width: 100px;\n"
"    min-height: 100px;\n"
"    max-height: 100px;\n"
"    padding: 0px;\n"
"}\n"
""));

        horizontalLayout_2->addWidget(pushButton_Stop);

        pushButton_Seek_Forward = new QPushButton(layoutWidget_3);
        pushButton_Seek_Forward->setObjectName("pushButton_Seek_Forward");
        pushButton_Seek_Forward->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    border-radius: 50px;\n"
"    background-color: rgb(255, 255, 255);\n"
"    color: rgb(52, 51, 64);\n"
"    min-width: 100px;\n"
"    max-width: 100px;\n"
"    min-height: 100px;\n"
"    max-height: 100px;\n"
"    padding: 0px;\n"
"}\n"
""));

        horizontalLayout_2->addWidget(pushButton_Seek_Forward);

        groupBox_Video = new QGroupBox(centralwidget);
        groupBox_Video->setObjectName("groupBox_Video");
        groupBox_Video->setGeometry(QRect(304, 24, 790, 450));
        groupBox_Video->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"	border:1px solid black;\n"
"}"));
        horizontalSlider_Duration = new QSlider(centralwidget);
        horizontalSlider_Duration->setObjectName("horizontalSlider_Duration");
        horizontalSlider_Duration->setGeometry(QRect(349, 485, 661, 18));
        horizontalSlider_Duration->setOrientation(Qt::Orientation::Horizontal);
        pushButton_AddSong = new QPushButton(centralwidget);
        pushButton_AddSong->setObjectName("pushButton_AddSong");
        pushButton_AddSong->setGeometry(QRect(50, 70, 83, 29));
        pushButton_SavePlaylist = new QPushButton(centralwidget);
        pushButton_SavePlaylist->setObjectName("pushButton_SavePlaylist");
        pushButton_SavePlaylist->setGeometry(QRect(50, 130, 83, 29));
        pushButton_LoadPlaylist = new QPushButton(centralwidget);
        pushButton_LoadPlaylist->setObjectName("pushButton_LoadPlaylist");
        pushButton_LoadPlaylist->setGeometry(QRect(50, 190, 83, 29));
        playlistWidget = new QListWidget(centralwidget);
        playlistWidget->setObjectName("playlistWidget");
        playlistWidget->setGeometry(QRect(20, 320, 151, 111));
        pushButton_Bluetooth = new QPushButton(centralwidget);
        pushButton_Bluetooth->setObjectName("pushButton_Bluetooth");
        pushButton_Bluetooth->setGeometry(QRect(340, 950, 221, 29));
        pushButton_Bluetooth->setStyleSheet(QString::fromUtf8("ui->pushButton_Bluetooth->setStyleSheet(R\"(\n"
"    QPushButton {\n"
"        background-color: #3498db;\n"
"        border-radius: 15px;\n"
"        color: white;\n"
"        font-size: 16px;\n"
"    }\n"
"    QPushButton:hover {\n"
"        background-color: #2980b9;\n"
"    }\n"
"    QPushButton:pressed {\n"
"        background-color: #1c5985;\n"
"    }\n"
")\");\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1962, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_Previous->setText(QString());
        pushButton_Next->setText(QString());
        label_current_Time->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        label_songTitle->setText(QCoreApplication::translate("MainWindow", "Name_File", nullptr));
        pushButton_Volume->setText(QString());
        label_Total_Time->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        pushButton_Seek_Backward->setText(QString());
        pushButton_Play_Pause->setText(QString());
        pushButton_Stop->setText(QString());
        pushButton_Seek_Forward->setText(QString());
        groupBox_Video->setTitle(QString());
        pushButton_AddSong->setText(QCoreApplication::translate("MainWindow", "Add Song", nullptr));
        pushButton_SavePlaylist->setText(QCoreApplication::translate("MainWindow", "Save Playlist", nullptr));
        pushButton_LoadPlaylist->setText(QCoreApplication::translate("MainWindow", "Load Playlist", nullptr));
        pushButton_Bluetooth->setText(QCoreApplication::translate("MainWindow", "Bluetooth", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
