#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include "date.h"
#include "accumulator.h"
#include <string>

// 抽象基类 Account
class Account {
protected:
    std::string id;
    double balance;
    Date lastDate;
    static double total;  // 所有账户总额

    void record(const Date& date, double amount, const std::string& desc);  // 记录交易
    double accumulate(const Date& date); // 计算从上次到现在的利息基础（子类可重写）

public:
    Account(const Date& date, const std::string& id);
    virtual ~Account() {}  // 虚析构函数

    std::string getId() const { return id; }
    double getBalance() const { return balance; }
    static double getTotal() { return total; }

    virtual void deposit(const Date& date, double amount, const std::string& desc) = 0;
    virtual void withdraw(const Date& date, double amount, const std::string& desc) = 0;
    virtual void settle(const Date& date) = 0;
    virtual void show() const = 0;
};

// 储蓄账户类
class SavingsAccount : public Account {
private:
    double rate;
    Accumulator acc;

public:
    SavingsAccount(const Date& date, const std::string& id, double rate);
    
    double getRate() const { return rate; }

    virtual void deposit(const Date& date, double amount, const std::string& desc) override;
    virtual void withdraw(const Date& date, double amount, const std::string& desc) override;
    virtual void settle(const Date& date) override;
    virtual void show() const override;
};

// 信用账户类
class CreditAccount : public Account {
private:
    double credit;
    double rate;
    double fee;
    Accumulator acc;

public:
    CreditAccount(const Date& date, const std::string& id, double credit, double rate, double fee);

    double getCredit() const { return credit; }
    double getRate() const { return rate; }
    double getFee() const { return fee; }
    double getDebt() const { return (getBalance() < 0 ? getBalance() : 0); }

    double getAvailableCredit() const {
        return (getBalance() < 0) ? (credit + getBalance()) : credit;
    }

    virtual void deposit(const Date& date, double amount, const std::string& desc) override;
    virtual void withdraw(const Date& date, double amount, const std::string& desc) override;
    virtual void settle(const Date& date) override;
    virtual void show() const override;
};

#endif // ACCOUNT_H_