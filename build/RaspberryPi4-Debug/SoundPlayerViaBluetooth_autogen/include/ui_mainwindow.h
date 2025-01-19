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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_File;
    QAction *actionAdd_Device;
    QWidget *centralwidget;
    QGroupBox *groupBox_Video;
    QLabel *videoLabel;
    QLabel *label_Total_Time;
    QSlider *horizontalSlider_Duration;
    QLabel *label_current_Time;
    QLabel *label_songTitle;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Volume;
    QSlider *horizontalSlider_Volume;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_Previous;
    QPushButton *pushButton_Seek_Backward;
    QPushButton *pushButton_Play_Pause;
    QPushButton *pushButton_Seek_Forward;
    QPushButton *pushButton_Next;
    QMenuBar *menubar;
    QMenu *menuOpenFile;
    QMenu *menuBluetooth;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1018, 738);
        actionOpen_File = new QAction(MainWindow);
        actionOpen_File->setObjectName("actionOpen_File");
        actionAdd_Device = new QAction(MainWindow);
        actionAdd_Device->setObjectName("actionAdd_Device");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox_Video = new QGroupBox(centralwidget);
        groupBox_Video->setObjectName("groupBox_Video");
        groupBox_Video->setGeometry(QRect(100, 60, 790, 450));
        groupBox_Video->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"	border:1px solid black;\n"
"}"));
        videoLabel = new QLabel(groupBox_Video);
        videoLabel->setObjectName("videoLabel");
        videoLabel->setGeometry(QRect(350, 220, 67, 17));
        videoLabel->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        label_Total_Time = new QLabel(centralwidget);
        label_Total_Time->setObjectName("label_Total_Time");
        label_Total_Time->setGeometry(QRect(860, 520, 81, 27));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label_Total_Time->setFont(font);
        horizontalSlider_Duration = new QSlider(centralwidget);
        horizontalSlider_Duration->setObjectName("horizontalSlider_Duration");
        horizontalSlider_Duration->setGeometry(QRect(150, 520, 691, 31));
        horizontalSlider_Duration->setOrientation(Qt::Orientation::Horizontal);
        label_current_Time = new QLabel(centralwidget);
        label_current_Time->setObjectName("label_current_Time");
        label_current_Time->setGeometry(QRect(60, 520, 81, 27));
        label_current_Time->setFont(font);
        label_songTitle = new QLabel(centralwidget);
        label_songTitle->setObjectName("label_songTitle");
        label_songTitle->setGeometry(QRect(400, 0, 301, 71));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Ubuntu Mono")});
        font1.setPointSize(19);
        font1.setBold(false);
        label_songTitle->setFont(font1);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(710, 570, 231, 111));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_Volume = new QPushButton(layoutWidget);
        pushButton_Volume->setObjectName("pushButton_Volume");
        pushButton_Volume->setMinimumSize(QSize(100, 100));
        pushButton_Volume->setMaximumSize(QSize(100, 100));
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
        pushButton_Volume->setIconSize(QSize(16, 20));

        horizontalLayout->addWidget(pushButton_Volume);

        horizontalSlider_Volume = new QSlider(layoutWidget);
        horizontalSlider_Volume->setObjectName("horizontalSlider_Volume");
        horizontalSlider_Volume->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        horizontalSlider_Volume->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout->addWidget(horizontalSlider_Volume);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(60, 560, 626, 131));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_Previous = new QPushButton(layoutWidget1);
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

        horizontalLayout_2->addWidget(pushButton_Previous);

        pushButton_Seek_Backward = new QPushButton(layoutWidget1);
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

        pushButton_Play_Pause = new QPushButton(layoutWidget1);
        pushButton_Play_Pause->setObjectName("pushButton_Play_Pause");
        pushButton_Play_Pause->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    border-radius: 50px;\n"
"    background-color: rgb(255, 255, 255);\n"
"    color: rgb(52, 51, 64);\n"
"    min-width: 105px;\n"
"    max-width: 110px;\n"
"    min-height: 110px;\n"
"    max-height: 110px;\n"
"    padding: 0px;\n"
"}\n"
""));

        horizontalLayout_2->addWidget(pushButton_Play_Pause);

        pushButton_Seek_Forward = new QPushButton(layoutWidget1);
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

        pushButton_Next = new QPushButton(layoutWidget1);
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

        horizontalLayout_2->addWidget(pushButton_Next);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1018, 22));
        menuOpenFile = new QMenu(menubar);
        menuOpenFile->setObjectName("menuOpenFile");
        menuBluetooth = new QMenu(menubar);
        menuBluetooth->setObjectName("menuBluetooth");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuOpenFile->menuAction());
        menubar->addAction(menuBluetooth->menuAction());
        menuOpenFile->addAction(actionOpen_File);
        menuBluetooth->addAction(actionAdd_Device);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen_File->setText(QCoreApplication::translate("MainWindow", "Open File...", nullptr));
        actionAdd_Device->setText(QCoreApplication::translate("MainWindow", "Add Device...", nullptr));
        groupBox_Video->setTitle(QString());
        videoLabel->setText(QString());
        label_Total_Time->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        label_current_Time->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        label_songTitle->setText(QString());
        pushButton_Volume->setText(QString());
        pushButton_Previous->setText(QString());
        pushButton_Seek_Backward->setText(QString());
        pushButton_Play_Pause->setText(QString());
        pushButton_Seek_Forward->setText(QString());
        pushButton_Next->setText(QString());
        menuOpenFile->setTitle(QCoreApplication::translate("MainWindow", "Media", nullptr));
        menuBluetooth->setTitle(QCoreApplication::translate("MainWindow", "Bluetooth", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
