#include "registe.h"
#include "ui_registe.h"
#include "mainwindow.h"

#include<QMessageBox>

#include<QFile>
#include<QTextStream>
#include<QVector>
#include <QDebug>

Registe::Registe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registe)
{
    ui->setupUi(this);

    ui->account_password_1->setEchoMode(QLineEdit::Password);
    ui->account_password_2->setEchoMode(QLineEdit::Password);

}

Registe::~Registe()
{
    delete ui;
}

void Registe::recv_register(){

    this->show();
}



void Registe::on_launch_clicked()
{
    static MainWindow main;
    QObject::connect(this,SIGNAL(show_main()),&main,SLOT(rec_mainwindow()));

    this->close();
    emit show_main();
}

bool Registe::password_is_same(){
    AccountName = ui->account_name->text();
    AccountPasswd_1 = ui->account_password_1->text();
    AccountPasswd_2 = ui->account_password_2->text();

    if(AccountPasswd_1 !=AccountPasswd_2)
    {
        QMessageBox::information(this,"Error","第二次密码输入错误");

        ui->account_password_1->clear();
        ui->account_password_2->clear();

        return false;
    }
    else return true;
}

bool Registe::account_not_wrong(){
    QFile in("name.txt");
    if(in.open(QIODevice::ReadOnly))
    {
        QVector<QString> Account;
        QString line = in.readLine();
        line = line.trimmed();
        while(!line.isNull()){

            Account.push_back(line);
            line = in.readLine();
            line = line.trimmed();
        }

        in.close();

        for(int i = 0;i<Account.size();i++){//遍历判断
            if(ui->account_name->text() == Account[i])
            {  QMessageBox::information(this,"Error","已存在该账号");
                ui->account_name->clear();
                ui->account_password_1->clear();
                ui->account_password_2->clear();

                return false;
            }
        }


        return true;
    }
    else
    {qDebug()<<"账户信息读取失败";
        return false;}

}

void Registe::registe(){

    QFile out_name("name.txt");
    QFile out_password("password.txt");

    AccountName = ui->account_name->text();
    AccountPasswd_1 = ui->account_password_1->text();
    AccountPasswd_2 = ui->account_password_2->text();

    if(AccountName.isEmpty()||AccountPasswd_1.isEmpty()||AccountPasswd_2.isEmpty()){QMessageBox::information(this,"error","未输入完全"); return;}
    else if(out_name.open(QIODevice::WriteOnly|QIODevice::Append)&&out_password.open(QIODevice::WriteOnly|QIODevice::Append))
    {
        QTextStream name(&out_name);
        QTextStream password(&out_password);

        name<<'\n'<<AccountName;
        password<<'\n'<<AccountPasswd_1;


    out_name.close();
    out_password.close();
    }
}


void Registe::on_register_2_clicked()
{
    if(account_not_wrong()){
        if(password_is_same()){

            registe();

            ui->account_name->clear();
            ui->account_password_1->clear();
            ui->account_password_2->clear();

            static MainWindow main;
            QObject::connect(this,SIGNAL(registe_finished()),&main,SLOT(rec_mainwindow()));

            this->close();
            emit registe_finished();
    }
    }
}

