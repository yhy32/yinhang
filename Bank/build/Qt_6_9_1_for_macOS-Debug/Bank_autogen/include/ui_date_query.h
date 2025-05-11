/********************************************************************************
** Form generated from reading UI file 'date_query.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATE_QUERY_H
#define UI_DATE_QUERY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_date_query
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QDateEdit *dateEdit;
    QDateEdit *dateEdit_2;
    QPushButton *search;

    void setupUi(QWidget *date_query)
    {
        if (date_query->objectName().isEmpty())
            date_query->setObjectName("date_query");
        date_query->resize(291, 187);
        label = new QLabel(date_query);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 60, 81, 21));
        label_2 = new QLabel(date_query);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 110, 81, 21));
        label_3 = new QLabel(date_query);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(90, 10, 91, 31));
        dateEdit = new QDateEdit(date_query);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(130, 60, 110, 22));
        dateEdit_2 = new QDateEdit(date_query);
        dateEdit_2->setObjectName("dateEdit_2");
        dateEdit_2->setGeometry(QRect(130, 110, 110, 22));
        search = new QPushButton(date_query);
        search->setObjectName("search");
        search->setGeometry(QRect(100, 150, 80, 18));

        retranslateUi(date_query);

        QMetaObject::connectSlotsByName(date_query);
    } // setupUi

    void retranslateUi(QWidget *date_query)
    {
        date_query->setWindowTitle(QCoreApplication::translate("date_query", "Form", nullptr));
        label->setText(QCoreApplication::translate("date_query", "\350\257\267\350\276\223\345\205\245\345\274\200\345\247\213\346\227\245\346\234\237\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("date_query", "\350\257\267\350\276\223\345\205\245\346\210\252\346\255\242\346\227\245\346\234\237\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("date_query", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\346\227\245\345\277\227\346\237\245\350\257\242</span></p></body></html>", nullptr));
        search->setText(QCoreApplication::translate("date_query", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class date_query: public Ui_date_query {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATE_QUERY_H
