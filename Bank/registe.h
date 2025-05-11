#ifndef REGISTE_H
#define REGISTE_H

#include <QWidget>
#include <QString>

namespace Ui {
class Registe;
}

class Registe : public QWidget
{
    Q_OBJECT

public:
    explicit Registe(QWidget *parent = nullptr);
    ~Registe();

    bool password_is_same();
    bool account_not_wrong();
    void registe();

private slots:
    void recv_register();

    void on_launch_clicked();

    void on_register_2_clicked();

signals:
    void show_main();
    void show_control();
    void registe_finished();

private:
    Ui::Registe *ui;
    QString AccountName;
    QString AccountPasswd_1;
    QString AccountPasswd_2;
};

#endif // REGISTE_H
