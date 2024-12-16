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
    QLabel *background;
    QPlainTextEdit *plainTextEdit;
    QPlainTextEdit *plainTextEdit_2;
    QPlainTextEdit *plainTextEdit_3;
    QPlainTextEdit *plainTextEdit_4;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *windowColor;
    QPushButton *createWindow;
    QLabel *label_7;
    QPushButton *lineColor;
    QPushButton *createLine;
    QPushButton *clipLine;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        background = new QLabel(centralwidget);
        background->setObjectName("background");
        background->setGeometry(QRect(10, 10, 500, 500));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(640, 30, 81, 31));
        plainTextEdit_2 = new QPlainTextEdit(centralwidget);
        plainTextEdit_2->setObjectName("plainTextEdit_2");
        plainTextEdit_2->setGeometry(QRect(640, 70, 81, 31));
        plainTextEdit_3 = new QPlainTextEdit(centralwidget);
        plainTextEdit_3->setObjectName("plainTextEdit_3");
        plainTextEdit_3->setGeometry(QRect(640, 110, 81, 31));
        plainTextEdit_4 = new QPlainTextEdit(centralwidget);
        plainTextEdit_4->setObjectName("plainTextEdit_4");
        plainTextEdit_4->setGeometry(QRect(640, 150, 81, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(640, 0, 81, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(600, 40, 47, 13));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(600, 80, 47, 13));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(600, 120, 47, 13));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(600, 160, 47, 13));
        windowColor = new QPushButton(centralwidget);
        windowColor->setObjectName("windowColor");
        windowColor->setGeometry(QRect(640, 200, 81, 23));
        createWindow = new QPushButton(centralwidget);
        createWindow->setObjectName("createWindow");
        createWindow->setGeometry(QRect(630, 230, 101, 23));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(650, 290, 81, 21));
        lineColor = new QPushButton(centralwidget);
        lineColor->setObjectName("lineColor");
        lineColor->setGeometry(QRect(640, 330, 91, 23));
        createLine = new QPushButton(centralwidget);
        createLine->setObjectName("createLine");
        createLine->setGeometry(QRect(640, 360, 91, 23));
        clipLine = new QPushButton(centralwidget);
        clipLine->setObjectName("clipLine");
        clipLine->setGeometry(QRect(640, 460, 91, 23));
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
        background->setText(QCoreApplication::translate("MainWindow", "World Coordinates", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Clipping Window", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "x1 = ", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "y1 = ", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "x2 = ", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "y2 = ", nullptr));
        windowColor->setText(QCoreApplication::translate("MainWindow", "Window Color", nullptr));
        createWindow->setText(QCoreApplication::translate("MainWindow", "Create Window ", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Line Attributes", nullptr));
        lineColor->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        createLine->setText(QCoreApplication::translate("MainWindow", "Draw Line", nullptr));
        clipLine->setText(QCoreApplication::translate("MainWindow", "Clip Line", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
