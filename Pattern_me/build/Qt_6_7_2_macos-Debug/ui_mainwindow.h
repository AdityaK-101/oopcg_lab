/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *display;
    QPlainTextEdit *xc;
    QPlainTextEdit *yc;
    QPlainTextEdit *rad;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *create;
    QPushButton *clear;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        display = new QLabel(centralwidget);
        display->setObjectName("display");
        display->setGeometry(QRect(0, 0, 500, 500));
        xc = new QPlainTextEdit(centralwidget);
        xc->setObjectName("xc");
        xc->setGeometry(QRect(650, 80, 104, 31));
        yc = new QPlainTextEdit(centralwidget);
        yc->setObjectName("yc");
        yc->setGeometry(QRect(650, 130, 104, 31));
        rad = new QPlainTextEdit(centralwidget);
        rad->setObjectName("rad");
        rad->setGeometry(QRect(650, 180, 104, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(590, 90, 58, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(590, 130, 58, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(590, 190, 58, 16));
        create = new QPushButton(centralwidget);
        create->setObjectName("create");
        create->setGeometry(QRect(660, 270, 100, 32));
        clear = new QPushButton(centralwidget);
        clear->setObjectName("clear");
        clear->setGeometry(QRect(660, 320, 100, 32));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
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
        display->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "xc", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "yc", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "r", nullptr));
        create->setText(QCoreApplication::translate("MainWindow", "Create", nullptr));
        clear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
