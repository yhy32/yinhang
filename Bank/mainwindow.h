#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void read_Account();
    void on_login_clicked();
    void on_register_2_clicked();

    void rec_mainwindow();
signals:
    void show_control(QString);
    void show_register();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
