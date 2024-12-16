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
    QLabel *output;
    QPushButton *color;
    QPushButton *pushButton_2;
    QPushButton *clear;
    QLabel *label;
    QPlainTextEdit *plainTextEdit;
    QPlainTextEdit *plainTextEdit_2;
    QPlainTextEdit *plainTextEdit_3;
    QPlainTextEdit *plainTextEdit_4;
    QPlainTextEdit *plainTextEdit_5;
    QPlainTextEdit *plainTextEdit_6;
    QPlainTextEdit *plainTextEdit_7;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *Translate;
    QPushButton *Rotate;
    QPushButton *Scale;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        output = new QLabel(centralwidget);
        output->setObjectName("output");
        output->setGeometry(QRect(10, 10, 500, 500));
        color = new QPushButton(centralwidget);
        color->setObjectName("color");
        color->setGeometry(QRect(660, 20, 75, 23));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(660, 50, 75, 23));
        clear = new QPushButton(centralwidget);
        clear->setObjectName("clear");
        clear->setGeometry(QRect(660, 80, 75, 23));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(630, 110, 81, 20));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(660, 130, 71, 31));
        plainTextEdit_2 = new QPlainTextEdit(centralwidget);
        plainTextEdit_2->setObjectName("plainTextEdit_2");
        plainTextEdit_2->setGeometry(QRect(660, 170, 71, 31));
        plainTextEdit_3 = new QPlainTextEdit(centralwidget);
        plainTextEdit_3->setObjectName("plainTextEdit_3");
        plainTextEdit_3->setGeometry(QRect(660, 260, 71, 31));
        plainTextEdit_4 = new QPlainTextEdit(centralwidget);
        plainTextEdit_4->setObjectName("plainTextEdit_4");
        plainTextEdit_4->setGeometry(QRect(660, 300, 71, 31));
        plainTextEdit_5 = new QPlainTextEdit(centralwidget);
        plainTextEdit_5->setObjectName("plainTextEdit_5");
        plainTextEdit_5->setGeometry(QRect(660, 340, 71, 31));
        plainTextEdit_6 = new QPlainTextEdit(centralwidget);
        plainTextEdit_6->setObjectName("plainTextEdit_6");
        plainTextEdit_6->setGeometry(QRect(660, 430, 71, 31));
        plainTextEdit_7 = new QPlainTextEdit(centralwidget);
        plainTextEdit_7->setObjectName("plainTextEdit_7");
        plainTextEdit_7->setGeometry(QRect(660, 470, 71, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(660, 240, 81, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(660, 410, 81, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(580, 130, 81, 20));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(580, 180, 81, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(620, 260, 41, 20));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(620, 300, 41, 20));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(620, 340, 41, 20));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(630, 440, 31, 20));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(630, 480, 31, 20));
        Translate = new QPushButton(centralwidget);
        Translate->setObjectName("Translate");
        Translate->setGeometry(QRect(660, 210, 75, 23));
        Rotate = new QPushButton(centralwidget);
        Rotate->setObjectName("Rotate");
        Rotate->setGeometry(QRect(660, 380, 75, 23));
        Scale = new QPushButton(centralwidget);
        Scale->setObjectName("Scale");
        Scale->setGeometry(QRect(660, 510, 75, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
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
        output->setText(QCoreApplication::translate("MainWindow", "OUTPUT", nullptr));
        color->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Draw", nullptr));
        clear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TRANSLATION", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "ROTATION", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "SCALING", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "movement in x:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "movement in y:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "angle :", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Pivot x :", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Pivot y : ", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Sx : ", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Sy :", nullptr));
        Translate->setText(QCoreApplication::translate("MainWindow", "Translate", nullptr));
        Rotate->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        Scale->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
