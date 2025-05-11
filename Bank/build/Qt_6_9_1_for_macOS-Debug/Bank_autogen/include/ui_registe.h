/********************************************************************************
** Form generated from reading UI file 'registe.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTE_H
#define UI_REGISTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Registe
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *register_2;
    QPushButton *launch;
    QLineEdit *account_name;
    QLineEdit *account_password_1;
    QLineEdit *account_password_2;

    void setupUi(QWidget *Registe)
    {
        if (Registe->objectName().isEmpty())
            Registe->setObjectName("Registe");
        Registe->resize(311, 213);
        label = new QLabel(Registe);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 30, 31, 21));
        label_2 = new QLabel(Registe);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 70, 41, 16));
        label_3 = new QLabel(Registe);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 110, 61, 21));
        register_2 = new QPushButton(Registe);
        register_2->setObjectName("register_2");
        register_2->setGeometry(QRect(100, 150, 111, 20));
        launch = new QPushButton(Registe);
        launch->setObjectName("launch");
        launch->setGeometry(QRect(100, 180, 111, 20));
        account_name = new QLineEdit(Registe);
        account_name->setObjectName("account_name");
        account_name->setGeometry(QRect(100, 30, 121, 20));
        account_password_1 = new QLineEdit(Registe);
        account_password_1->setObjectName("account_password_1");
        account_password_1->setGeometry(QRect(100, 70, 121, 20));
        account_password_2 = new QLineEdit(Registe);
        account_password_2->setObjectName("account_password_2");
        account_password_2->setGeometry(QRect(100, 110, 121, 20));

        retranslateUi(Registe);

        QMetaObject::connectSlotsByName(Registe);
    } // setupUi

    void retranslateUi(QWidget *Registe)
    {
        Registe->setWindowTitle(QCoreApplication::translate("Registe", "Form", nullptr));
        label->setText(QCoreApplication::translate("Registe", "\350\264\246\345\217\267\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Registe", "\345\257\206\347\240\201\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Registe", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        register_2->setText(QCoreApplication::translate("Registe", "\346\263\250\345\206\214", nullptr));
        launch->setText(QCoreApplication::translate("Registe", "\345\267\262\346\234\211\350\264\246\345\217\267\357\274\237\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Registe: public Ui_Registe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTE_H
