/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *login;
    QPushButton *register_2;
    QLineEdit *Account_name;
    QLabel *Acount_name_label;
    QLabel *Account_password_label;
    QLineEdit *Acount_password;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(308, 180);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        login = new QPushButton(centralwidget);
        login->setObjectName("login");
        login->setGeometry(QRect(70, 110, 61, 20));
        register_2 = new QPushButton(centralwidget);
        register_2->setObjectName("register_2");
        register_2->setGeometry(QRect(180, 110, 61, 20));
        Account_name = new QLineEdit(centralwidget);
        Account_name->setObjectName("Account_name");
        Account_name->setGeometry(QRect(100, 30, 131, 20));
        Acount_name_label = new QLabel(centralwidget);
        Acount_name_label->setObjectName("Acount_name_label");
        Acount_name_label->setGeometry(QRect(70, 30, 41, 20));
        Account_password_label = new QLabel(centralwidget);
        Account_password_label->setObjectName("Account_password_label");
        Account_password_label->setGeometry(QRect(70, 70, 41, 20));
        Acount_password = new QLineEdit(centralwidget);
        Acount_password->setObjectName("Acount_password");
        Acount_password->setGeometry(QRect(100, 70, 131, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 308, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Bank", nullptr));
        login->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        register_2->setText(QCoreApplication::translate("MainWindow", "\346\263\250\345\206\214", nullptr));
        Acount_name_label->setText(QCoreApplication::translate("MainWindow", "\350\264\246\345\217\267\357\274\232", nullptr));
        Account_password_label->setText(QCoreApplication::translate("MainWindow", "\345\257\206\347\240\201\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
