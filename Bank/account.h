#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QWidget>
#include<QString>
#include<QMap>
#include"date.h"
#include"accumulator.h"




class Account;	//前置声明

// Record的实现
class AccountRecord  //账目记录
{
private:
    Date date;                     //日期
    const Account *account;        //账户
    double amount;                 //金额
    double balance;                //余额
    QString desc;              //描述

public:
    AccountRecord(const Date& date, Account* account, double amount, double balance, const QString& desc);
    void show() const;


};



//基类Account的定义


class Account
{
private:
    QString id;//账户
    double balance;//余额
    static double total;//银行总余额
    static QMultiMap<Date, AccountRecord> recordMap;//定义用来存储账目记录的多重映射类型
protected:

    //供派生类调用的构造函数，id为账户
    Account(const Date& date, const QString& id);


    //记录一笔帐，date为日期，amount为金额，desc为说明
    void record(const Date& date, double amount, const QString& desc);


//    //报告错误信息
//    void error(const QString& msg) const;

public:

    const QString& getId() const { return id; }
    double getBalance() const { return balance; }
    static double getTotal() { return total; }

    //显示账户信息
    virtual void show() const;
    //存入现金，date为日期，amount为金额，desc为款项说明
    virtual void deposit(const Date& date, double amount, const QString& desc) = 0;
    //取出现金，date为日期，amount为金额，desc为款项说明
    virtual void withdraw(const Date& date, double amount, const QString& desc) = 0;
    //结算（计算利息、年费等），每月结算一次，date为结算日期
    virtual void settle(const Date& date) = 0;
    //查询操作记录
    static void query(Date& day1, Date& day2);
};


//派生类的定义

class SavingsAccount : public Account{ //储蓄账户类
private:
    Accumulator acc;	//辅助计算利息的累加器
    double rate;		//存款的年利率
public:
    //构造函数
    SavingsAccount(const Date& date, const QString& id,double rate);


    double getRate() const { return rate; }

    //更改利息
    void setRate(double rate = 0.015){this->rate=rate;}
    //存入现金
    virtual void deposit(const Date& date, double amount, const QString& desc);
    //取出现金
    virtual void withdraw(const Date& date, double amount, const QString& desc);
    //结算利息，每年1月1日调用一次该函数
    virtual void settle(const Date& date);

signals:
    void with_wrong_saving(){}
};



class CreditAccount : public Account { //信用账户类
private:
    Accumulator acc;	//辅助计算利息的累加器
    double credit;		//信用额度
    double rate;		//欠款的日利率
    double fee;			//信用卡年费

    double getDebt() const {	//获得欠款额
        double balance = getBalance();
        return (balance < 0 ? balance : 0);
    }
public:
    //构造函数
    CreditAccount(const Date& date, const QString& id,double credit =10000 ,double rate=0.015,double fee=50);


    double getCredit() const { return credit; }
    double getRate() const { return rate; }
    double getFee() const { return fee; }
    double getAvailableCredit() const {	//获得可用信用
        if (getBalance() < 0)
            return credit + getBalance();
        else
            return credit;
    }

    //更改信用
    void setCredit(double credit = 10000){this->credit = credit;}
    //更改年费
    void setFee(double fee = 50){this->fee = fee;}
    //更改利息
    void setRate(double rate = 0.0005){this->rate=rate;}
    //存入现金
    virtual void deposit(const Date& date, double amount, const QString& desc);
    //取出现金
    virtual void withdraw(const Date& date, double amount, const QString& desc);
    //结算利息和年费，每月1日调用一次该函数
    virtual void settle(const Date& date);

    virtual void show() const;
signals:
    void with_wrong_credit(){}
};


//错误账户
//class AccountException :public runtime_error
//{
//private:
//    const Account* wrong_account;

//public:
//    AccountException(const Account* wrong) :wrong_account(wrong), runtime_error("withdraw   false") { };

//};
#endif // ACCOUNT_H
