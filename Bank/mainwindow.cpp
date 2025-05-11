#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "QDebug"
#include <QLineEdit>
#include <QString>
#include <QMap>
#include <QFile>
#include <QMessageBox>
#include<string>

#include "control.h"
#include "registe.h"
#include <QObject>

QMap<QString,QString>  Account;//储存所有账号

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    read_Account();
    ui->Acount_password->setEchoMode(QLineEdit::Password);//将密码输入框输入隐藏
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::read_Account(){

    QFile check_name("name.txt");
    if (!check_name.exists()) {
        check_name.open(QIODevice::WriteOnly);
        check_name.close();
    }

    QFile check_password("password.txt");
    if (!check_password.exists()) {
        check_password.open(QIODevice::WriteOnly);
        check_password.close();
    }

    QFile in_name("name.txt");//读取已创建的账号密码信息
    QFile in_passwd("password.txt");

    if(in_name.open(QIODevice::ReadOnly)&&in_passwd.open(QIODevice::ReadOnly))
    {
        QString na;
        QString passwd;

        na = in_name.readLine();
        na = na.trimmed();
        passwd = in_passwd.readLine();
        passwd = passwd.trimmed();

        while(!(na.isNull()&&passwd.isNull()))
        {

            Account.insert(na,passwd);
            na = in_name.readLine();
            na = na.trimmed();
            passwd = in_passwd.readLine();
            passwd = passwd.trimmed();
        }

        in_name.close();
        in_passwd.close();

    }
    else {qDebug()<< "文件打开失败";}
}

void MainWindow::on_login_clicked()
{
    static Control control;
    QObject::connect(this,SIGNAL(show_control(QString)),&control,SLOT(recv_control(QString)));//进行信号与槽的链接

    bool exsit = false;//用于判断是否存在该账户

    QString name = ui->Account_name->text();//读取输入
    QString password = ui->Acount_password->text();//读取输入
    QMap<QString,QString>::const_iterator iter;//遍历查找

    iter = Account.find(name);
    if(iter != Account.constEnd())
    {exsit=true;}


    if(exsit)
    {
        if(Account.value(name) == password)//存在账户且密码正确，转换到control窗口
        {
            QString na = ui->Account_name->text();
            ui->Account_name->clear();
            ui->Acount_password->clear();
            this->close();
            emit show_control(na);
        }
        else{QMessageBox::information(this,"Error","密码错误");}
    }
    else
    {
        QMessageBox::information(this,"Error","不存在该账户");
    }


}



void MainWindow::on_register_2_clicked()
{
    ui->Account_name->clear();
    ui->Acount_password->clear();

    static Registe registe;
    QObject::connect(this,SIGNAL(show_register()),&registe,SLOT(recv_register()));

    this->close();
    emit show_register();
}

void MainWindow::rec_mainwindow(){
    this->show();
}
