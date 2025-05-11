#ifndef DATE_QUERY_H
#define DATE_QUERY_H

#include <QWidget>
#include "date.h"
#include "control.h"

namespace Ui {
class date_query;
}

class date_query : public QWidget
{
    Q_OBJECT

public:
    explicit date_query(QWidget *parent = nullptr);
    ~date_query();

private slots:
    void on_search_clicked();

    void address_get(Control* con);


private:
    Ui::date_query *ui;
    Control *control;
};

#endif // DATE_QUERY_H
