#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include"date.h"
#include"Accumulator.h"
#include<string>
#include<map>
#include<iostream>
using namespace std; 
class AccountRecord;



typedef multimap<Date, AccountRecord>RecordMap;
class Account
{
private:
	double balance;
	std::string Id;
	double static total;
public:
	std::string getId() const { return Id; }
	double  getBalance()const { return balance; }
	double static getTotal() { return total; }
	virtual void  deposit(const Date& date, double amount, const std::string& c)=0;
	virtual void  withdraw(const Date& date, double amount, const std:: string& c) = 0;
	virtual void  settle(const Date& date)=0;
	virtual void show()const;
	static RecordMap recordMap;
	static void query(const Date& date1, const Date& date2);
	virtual ~Account() {};
protected:
	Account(const Date& date, const std::string& id);
	void record(const Date& date, double amount, const std::string& c);
};
class SavingsAccount :public Account
{
private:
	Accumulator acc;
	double rate;
public:
	SavingsAccount(const Date& date, const std::string& id, double rate);
	double const getRate() { return rate; }
	virtual void deposit(const Date& date, double amount, const std::string& c);
	virtual void withdraw(const Date& date, double amount, const std::string& c);
	virtual void settle(const Date& date);
};
class CreditAccount :public Account
{
private:
	double credit;
	double rate;
	Accumulator acc;
	double fee;
public:
	double const getDebt()
	{
		return (getBalance() < 0 ? getBalance() : 0);
	}
	CreditAccount(const Date& date, const std::string& id, double credit, double rate, double fee);
	double getCredit()const { return credit; }
	double getRate()const { return rate; }
	double getFee()const { return fee; }
	double getAvailableCredit()const
	{
		if (getBalance() < 0)
			return credit + getBalance();
		else
			return credit;
	}
	virtual void deposit(const Date& date, double amount, const std::string& c);
	virtual void withdraw(const Date& date, double amount, const std::string& c);
	virtual void settle(const Date& date);
	virtual void show()const;
};
class AccountRecord
{
private:
	Date date;
	Account* account;
	double amount;
	double balance;
	std::string c;
public:
	AccountRecord(const Date& date, Account* account, double amount, double balance, const std::string& c);
	void show() const
	{
		std::cout << "\t#" << account->getId() << "\t" << amount << "\t" << balance << "\t" << c << std::endl;
	}
};


#endif // ACCOUNT_H_INCLUDED
