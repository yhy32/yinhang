#include "control.h"
#include "account.h"
#include "date_query.h"
#include "ui_control.h"
#include "mainwindow.h"

#include <cmath>

#include<QVector>
#include <QInputDialog>
#include <QFile>
#include <QMessageBox>
#include <QDir>


#include <QDebug>

QVector<Account*> accounts;
Date date;
QFile log_out;
QTextStream out(&log_out);

Control *This;
Ui::Control *UI;

double sum_input=0;
double sum_output=0;
double sum_debt=0;

Control::Control(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Control)
{
    UI = ui;
    This = this;
    ui->setupUi(this);
    ui->ALL->setFrame(false);//去除边框线
    ui->input->setFrame(false);
    ui->output->setFrame(false);
    ui->debt->setFrame(false);
    ui->date->setReadOnly(true);

}


Control::~Control()
{
    delete ui;
}




void Control::recv_control(QString name)
{
    this->name = name;
    log_out.setFileName("./log/" + name + ".txt");
    if(!log_out.open(QIODevice::ReadOnly)){qDebug()<<"文件打开失败(恢复)";}
    recover();
    this->show();
    save();

}

void Control::recover(){

    QTextStream in(&log_out);

    if (log_out.isOpen()) {
        while (!in.atEnd())
        {

            Date date(2000,1,1);
            char cmd,type;

            int index;//, day;

            double amount, credit, rate, fee;

            QString id,desc;

            Account* account;

            char temp;//储存换行符

            //Date date1, date2;



            in >> cmd;
            in.QTextStream::skipWhiteSpace();//跳过空格

            switch (cmd) {

            case 'a'://增加账户

                {in >> type >> id;

                if (type == 's') {

                    in >> rate>>temp;

                    account = new SavingsAccount(date, id, rate);

                }

                else {

                    in >> credit >> rate >> fee>>temp;

                    account = new CreditAccount(date, id, credit, rate, fee);

                }

                accounts.push_back(account);

                break;}

            case 'd'://存入现金

                {in >> index >> amount;

                desc = in.readLine();
                desc = desc.trimmed();

                accounts[index]->deposit(date, amount, desc);

                break;}

            case 'w'://取出现金

                {in >> index >> amount;

                desc = in.readLine();
                desc = desc.trimmed();

                accounts[index]->withdraw(date, amount, desc);

                break;}
            case 's'://查询各账户信息

                in>>temp;
                {for (size_t i = 0; i < accounts.size(); i++) {

                    accounts[i]->show();

                }

                break;}


            case 'n'://进入下个月

                in>>temp;

                {if (date.getMonth() == 12)

                date = Date(date.getYear() + 1, 1, 1);

                else

                date = Date(date.getYear(), date.getMonth() + 1, 1);

                for (QVector<Account*>::iterator iter = accounts.begin(); iter != accounts.end(); ++iter)

                    (*iter)->settle(date);

                break;}

            }

        }
    }
    else { qDebug() << "文件打开失败(恢复)"; }

    log_out.close();
}


void Control::save(){
    QString path = QCoreApplication::applicationDirPath();
    QString fullPath = path+"/log";
    QDir dir(fullPath);
    if(!dir.exists()){
     bool ok = dir.mkpath(fullPath);//创建多级目录
    }

    log_out.setFileName(fullPath+"/" + name + ".txt");
    if(!log_out.open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Text)){qDebug()<<"文件打开失败(储存)";}

}

void Control::setALL(){
    ui->ALL->setText(QString("%1").arg(Account::getTotal()));
}
void Control::setInput(){
    sum_input = floor(sum_input * 100 + 0.5) / 100;
    ui->input->setText(QString("%1").arg(sum_input));
}
void Control::setOut(){
     sum_output = floor(sum_output * 100 + 0.5) / 100;
    ui->output->setText(QString("%1").arg(sum_output));
}
void Control::setDebt(){
     sum_debt = floor(sum_debt * 100 + 0.5) / 100;
    ui->debt->setText(QString("%1").arg(sum_debt));
}



void Control::on_create_clicked()
{

    Account* account;
    date = Date(ui->date->date().year(),ui->date->date().month(),ui->date->date().day());

    //提示窗口的设置
    QMessageBox createAccount(QMessageBox::Question,"","");
    createAccount.setParent(this);
    createAccount.setWindowFlag(Qt::Dialog);
    createAccount.setWindowTitle("创建用户");
    createAccount.setText("请选择您想要创建的用户");

    QPushButton* savingsBut;
    QPushButton* creditBut;
    savingsBut = createAccount.addButton("储蓄类账户",QMessageBox::AcceptRole);
    creditBut = createAccount.addButton("信用类账户",QMessageBox::RejectRole);

    int reply = createAccount.exec();//显示提示窗口

    reName: QString name = QInputDialog::getText(this,"账户","请输入账户名称");//输入账户

    for(int i=0;i<accounts.size();i++){
        if(name == accounts[i]->getId()){
            QMessageBox::information(this,"Error","已存在该账户");
            goto reName;
        }
    }

    if(name==""){QMessageBox::information(this,"Error","请输入账号名称");}
    else{

    switch(reply){
    case QMessageBox::AcceptRole:
    {
        bool ok;
        double rate = QInputDialog::getDouble(this,"利息","请输入利息",0,0,1,4,&ok);
        if(ok)
            {account = new SavingsAccount(date, name,rate);
}
        else
            {return;}

    out<<'a'<<' '<<"s"/*<<date*/<<' '<<name<<' '<<rate<<Qt::endl;
        accounts.push_back(account);
        break;}

    case QMessageBox::RejectRole:
    {   account = new CreditAccount(date, name);

        bool ok;
        double credit = QInputDialog::getDouble(this,"Credit","请输入信用额度",0,0,2147483647,1,&ok);
        if(ok){dynamic_cast<CreditAccount*>(account)->setCredit(credit);}
        else{return;}

        double rate = QInputDialog::getDouble(this,"Rate","请输入利息",0,0,1,4,&ok);//0为默认值，0为最低值，1为最高值，4为小数点位数，ok为用户点击选项
        if(ok)
            {dynamic_cast<CreditAccount*>(account)->setFee(rate);}
        else
            {return;}

        double fee = QInputDialog::getDouble(this,"Fee","请输入年费",0,0,2147483647,1,&ok);
        if(!ok){return;}

        dynamic_cast<CreditAccount*>(account)->setFee(fee);

        out<<'a'<<' '<<"c"/*<<date*/<<' '<<name<<' '<< credit<<' '<<rate<<' '<<fee<<Qt::endl;
        accounts.push_back(account);
        break;}
    }
    }


}


void Control::on_operate_clicked()
{

    Date date(ui->date->date().year(),ui->date->date().month(),ui->date->date().day());

    //提示窗口的设置
    QMessageBox createAccount(QMessageBox::Question,"","");
    createAccount.setParent(this);
    createAccount.setWindowFlag(Qt::Dialog);
    createAccount.setWindowTitle("操作用户");
    createAccount.setText("请选择您想要进行的操作");

    QPushButton* withdraw;
    QPushButton* deposit;
    QPushButton* show_operate;
    withdraw = createAccount.addButton("取款",QMessageBox::AcceptRole);
    deposit = createAccount.addButton("存款",QMessageBox::RejectRole);
    show_operate = createAccount.addButton("查看当前信息",QMessageBox::YesRole);

    int reply = createAccount.exec();//显示提示窗口

    int index = 0;
    bool temp;
    QString name = 0;
    double number = 0;
    QString desc ={};

    if(reply!= 2/*QMessageBox::YesRole*/ ){

     name = QInputDialog::getText(this,"账户","请输入账户名称",QLineEdit::Normal,QString(),&temp);//输入账户
        if(temp){temp=false;}
        else {return;}
        for(index;index < accounts.size();index++)
        {
            if(accounts[index]->getId() == name)
            {  temp=true;
                break;}

        }
        if(!temp){QMessageBox::information(this,"Error","不存在该账户");}
        else{
         number = QInputDialog::getDouble(this,"数目","请输入数目",0,0,2147483647,2,&temp);//操作金额
         if(!temp){return;}

         desc = QInputDialog::getText(this,"信息","请输入描述信息",QLineEdit::Normal,QString(),&temp);//输入描述
         if(!temp){return;}
         //if(desc==''){desc ="NULL" ;}
        }

    }


    switch(reply){
    case QMessageBox::AcceptRole://取款
    {
        sum_output+=number;
        if(temp){
        accounts[index]->withdraw(date,number,desc);

         out<<"w "<<index<<' '<<number<<' '<<desc<<Qt::endl;
        }break;}
    case QMessageBox::RejectRole://存款
    {
        sum_input+=number;
        if(temp){
        accounts[index]->deposit(date,number,desc);
         out<<"d "<<index<<' '<<number<<' '<<desc<<Qt::endl;
        }break;}
    case 2/*QMessageBox::YesRole*/:
    {
        date.show();
        for(int i=0;i<accounts.size();i++)
        { accounts[i]->show();}
        out<<'s'<<Qt::endl;

    break;}
    }
}


void Control::on_log_search_clicked()
{
    static date_query m;

    emit address_push(this);
    m.show();

}

void Control::log_search_finished(Date firstDate,Date laterDate){


    Account::query(firstDate,laterDate);
}




void Control::on_next_month_clicked()
{
    out<<'n'<<Qt::endl;
    sum_input=0;
    sum_output=0;
    sum_debt=0;
if (date.getMonth() == 12)
    {
date = Date(date.getYear() + 1, 1, 1);
    ui->date->setDate(QDate(date.getYear() + 1, 1, 1));
}
else
{
date = Date(date.getYear(), date.getMonth() + 1, 1);
    ui->date->setDate(QDate(date.getYear(), date.getMonth() + 1, 1));
}
for (QVector<Account*>::iterator iter = accounts.begin(); iter != accounts.end(); ++iter)
{
(*iter)->settle(date);}

setALL();
setInput();
setOut();
setDebt();

}


//Account.h的实现


double Account::total = 0;
QMultiMap<Date,AccountRecord> Account::recordMap;

//void deleted() {

//    QFile in("log.txt");


//    QVector<QString> tempstr;//储存命令行
//    QString temp;
//    int i = 0;
//    while (in.open(QIODevice::ReadOnly))
//    {
//        temp = in.readLine();
//        temp =temp.trimmed();

//        if(temp.length()!=0)
//            tempstr.push_back(temp);
//    }
//    QFile out("log.txt");
//    out.open(QIODevice::WriteOnly);//输出文件

//    for ( i=0 ; i < tempstr.size()-1; i++)
//    {
//        out << tempstr[i];
//        out << Qt::endl<<Qt::endl;
//    }

//    in.close();
//    out.close();

//}


AccountRecord::AccountRecord(const Date& date, Account* account, double amount, double balance, const QString& desc)
    :date(date), account(account), amount(amount), balance(balance), desc(desc) {}

void AccountRecord::show() const
{
    date.show();
    UI->log->append("#"+account->getId()+"\t操作金额："+QString("%1").arg(amount)+"\t余额："+ QString("%1").arg(balance)+"\t信息："+desc);
}

//Account类的实现
Account::Account(const Date& date, const QString& id)
    : id(id), balance(0) {
    date.show();
    UI->log->append( "#" + id + " created" );
}

void Account::record(const Date& date, double amount, const QString& desc) {
    amount = floor(amount * 100 + 0.5) / 100;	//保留小数点后两位
    balance += amount;
    total += amount;

    AccountRecord record(date, this, amount, balance, desc);

    recordMap.insert(date, record);

    record.show();

}

void Account::show() const {
    UI->log->append("#" + id + "\t余额：" +QString("%1").arg(balance));
}

//void Account::error(const QString& msg) const {
//    //cout << "Error(#" << id << "): " << msg << endl;
//}

void Account::query(Date& day1, Date& day2){
    if (day1 < day2) {
    QMultiMap<Date,AccountRecord>::iterator iter1 = recordMap.lowerBound(day1);
    QMultiMap<Date,AccountRecord>::iterator iter2 = recordMap.upperBound(day2);
    for (QMultiMap<Date,AccountRecord>::iterator iter = iter1; iter != iter2; ++iter)
         iter->show();
    }
    else{QMessageBox::information(This,"Error","截止日期在起始日期之前");}
}


//SavingsAccount类相关成员函数的实现
SavingsAccount::SavingsAccount(const Date& date, const QString& id,double rate =0.015)
    : Account(date, id), acc(date, 0),rate(rate) { }

void SavingsAccount::deposit(const Date& date, double amount, const QString& desc) {
    record(date, amount, desc);
    acc.change(date, getBalance());
}



void SavingsAccount::settle(const Date& date) {
    if (date.getMonth() == 1) {	//每年的一月计算一次利息
    double interest = acc.getSum(date) * rate
                      / (date.distance(Date(date.getYear() - 1, 1, 1)));
    if (interest != 0){
         record(date, interest, "月息");
         sum_input+=interest;
    }
    acc.reset(date, getBalance());
    }
}

//CreditAccount类相关成员函数的实现
CreditAccount::CreditAccount(const Date& date, const QString& id,double credit,double rate,double fee)
    : Account(date, id), acc(date, 0),credit(credit),rate(rate),fee(fee) {}

void CreditAccount::deposit(const Date& date, double amount, const QString& desc) {
    record(date, amount, desc);
    acc.change(date, getDebt());
}



void CreditAccount::settle(const Date& date) {
    double interest = acc.getSum(date) * rate;
    if (interest != 0){
    record(date, interest, "月息");
    sum_output-=interest;
    }
    if (date.getMonth() == 1)
    record(date, -fee, "年费");
    acc.reset(date, getDebt());
    sum_debt+=getDebt();
}

void CreditAccount::show() const {
    Account::show();
    UI->log->append("剩余信用额度:" + QString("%1").arg(getAvailableCredit()));
}


void SavingsAccount::withdraw(const Date& date, double amount, const QString& desc) {
    if (amount > getBalance()) {
    QMessageBox::information(This,"Error","余额不足");
    }
    else {
    record(date, -amount, desc);
    acc.change(date, getBalance());
    }
}

void CreditAccount::withdraw(const Date& date, double amount, const QString& desc) {

    if (amount - getBalance() > credit) {
        QMessageBox::information(This,"Error","信用额度不在足");
    emit with_wrong_credit();
    }
    else {
    record(date, -amount, desc);
    acc.change(date, getDebt());
    }
}




void Date::show() const {
    UI->log->append( QString("%1").arg(getYear()) + "-" +QString("%1").arg(getMonth()) + "-" +QString("%1").arg( getDay()));
}






void Control::on_quit_clicked()
{

    static MainWindow ori;
    QObject::connect(this,SIGNAL(quit()),&ori,SLOT(rec_mainwindow()));

    this->close();
    emit quit();
}

