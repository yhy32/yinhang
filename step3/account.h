#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include "date.h"
#include "accumulator.h"
#include <string>

// ������� Account
class Account {
protected:
    std::string id;
    double balance;
    Date lastDate;
    static double total;  // �����˻��ܶ�

    void record(const Date& date, double amount, const std::string& desc);  // ��¼����
    double accumulate(const Date& date); // ������ϴε����ڵ���Ϣ�������������д��

public:
    Account(const Date& date, const std::string& id);
    virtual ~Account() {}  // ����������

    std::string getId() const { return id; }
    double getBalance() const { return balance; }
    static double getTotal() { return total; }

    virtual void deposit(const Date& date, double amount, const std::string& desc) = 0;
    virtual void withdraw(const Date& date, double amount, const std::string& desc) = 0;
    virtual void settle(const Date& date) = 0;
    virtual void show() const = 0;
};

// �����˻���
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

// �����˻���
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