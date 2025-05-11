#ifndef CONTROL_H
#define CONTROL_H

#include <QWidget>
#include "date.h"


namespace Ui {
class Control;
}

class Control : public QWidget
{
    Q_OBJECT

public:
    explicit Control(QWidget *parent = nullptr);
    ~Control();

    void log_search_finished(Date firstDate,Date laterDate);

private slots:
    void recv_control(QString);

    void on_create_clicked();
    void on_operate_clicked();

    void on_log_search_clicked();

    void on_next_month_clicked();

    void on_quit_clicked();

signals:
    void address_push(Control*);
    void quit();



private:

    QString name;
    void recover();
    void save();
    void setALL();
    void setInput();
    void setOut();
    void setDebt();

    Ui::Control *ui;
};


#endif // CONTROL_H
