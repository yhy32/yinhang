/********************************************************************************
** Form generated from reading UI file 'control.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROL_H
#define UI_CONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Control
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *create;
    QPushButton *operate;
    QPushButton *log_search;
    QLabel *label_4;
    QLineEdit *ALL;
    QLineEdit *input;
    QLineEdit *output;
    QLineEdit *debt;
    QDateEdit *date;
    QTextBrowser *log;
    QPushButton *next_month;
    QPushButton *quit;

    void setupUi(QWidget *Control)
    {
        if (Control->objectName().isEmpty())
            Control->setObjectName("Control");
        Control->resize(501, 443);
        label = new QLabel(Control);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 50, 51, 21));
        label_2 = new QLabel(Control);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(100, 90, 51, 21));
        label_3 = new QLabel(Control);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(100, 130, 51, 21));
        create = new QPushButton(Control);
        create->setObjectName("create");
        create->setGeometry(QRect(30, 170, 81, 21));
        operate = new QPushButton(Control);
        operate->setObjectName("operate");
        operate->setGeometry(QRect(150, 170, 81, 21));
        log_search = new QPushButton(Control);
        log_search->setObjectName("log_search");
        log_search->setGeometry(QRect(270, 170, 81, 21));
        label_4 = new QLabel(Control);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(210, 10, 61, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font.setPointSize(14);
        label_4->setFont(font);
        ALL = new QLineEdit(Control);
        ALL->setObjectName("ALL");
        ALL->setGeometry(QRect(280, 10, 113, 20));
        input = new QLineEdit(Control);
        input->setObjectName("input");
        input->setGeometry(QRect(160, 50, 231, 20));
        output = new QLineEdit(Control);
        output->setObjectName("output");
        output->setGeometry(QRect(160, 90, 231, 20));
        debt = new QLineEdit(Control);
        debt->setObjectName("debt");
        debt->setGeometry(QRect(160, 130, 231, 20));
        date = new QDateEdit(Control);
        date->setObjectName("date");
        date->setGeometry(QRect(90, 10, 110, 22));
        log = new QTextBrowser(Control);
        log->setObjectName("log");
        log->setGeometry(QRect(30, 211, 441, 211));
        next_month = new QPushButton(Control);
        next_month->setObjectName("next_month");
        next_month->setGeometry(QRect(390, 170, 81, 21));
        quit = new QPushButton(Control);
        quit->setObjectName("quit");
        quit->setGeometry(QRect(440, 10, 51, 21));
        ALL->raise();
        debt->raise();
        output->raise();
        create->raise();
        operate->raise();
        log_search->raise();
        input->raise();
        label->raise();
        label_3->raise();
        label_2->raise();
        label_4->raise();
        date->raise();
        log->raise();
        next_month->raise();
        quit->raise();

        retranslateUi(Control);

        QMetaObject::connectSlotsByName(Control);
    } // setupUi

    void retranslateUi(QWidget *Control)
    {
        Control->setWindowTitle(QCoreApplication::translate("Control", "Form", nullptr));
        label->setText(QCoreApplication::translate("Control", "\344\270\212\346\234\210\346\224\266\345\205\245\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Control", "\344\270\212\346\234\210\346\224\257\345\207\272\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Control", "\345\275\223\345\211\215\346\254\240\346\254\276\357\274\232", nullptr));
        create->setText(QCoreApplication::translate("Control", "\345\210\233\345\273\272\350\264\246\346\210\267", nullptr));
        operate->setText(QCoreApplication::translate("Control", "\346\223\215\344\275\234\350\264\246\346\210\267", nullptr));
        log_search->setText(QCoreApplication::translate("Control", "\346\227\245\345\277\227\346\237\245\350\257\242", nullptr));
        label_4->setText(QCoreApplication::translate("Control", "\346\200\273\344\275\231\351\242\235\357\274\232", nullptr));
        ALL->setText(QCoreApplication::translate("Control", "0", nullptr));
        input->setText(QCoreApplication::translate("Control", "0", nullptr));
        output->setText(QCoreApplication::translate("Control", "0", nullptr));
        debt->setText(QCoreApplication::translate("Control", "0", nullptr));
        next_month->setText(QCoreApplication::translate("Control", "\344\270\213\344\270\200\344\270\252\346\234\210", nullptr));
        quit->setText(QCoreApplication::translate("Control", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Control: public Ui_Control {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROL_H
