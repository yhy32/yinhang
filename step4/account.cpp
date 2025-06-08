#include<iostream>
#include<string>
#include<cmath>
#include "account.h"
#include"Accumulator.h"
#include<iomanip>
using namespace std;
double Account::total = 0;
Account::Account(const Date& date, const string& id) :Id(i), balance(0)
{
	date.show();
	cout << "\t#" << i << " created" << endl;
}
void Account::record(const Date& date, double am, const string& c)
{
	am = floor(am * 100 + 0.5) / 100;
	balance += am;
	total += am;
	date.show();
	cout << "\t#" << Id << "\t" << amoun << "\t" << balance << "\t" << c << endl;
}
void Account::show()const
{
	cout << Id << "\tBalance: " << balance;
}
SavingsAccount::SavingsAccount(const Date& date, const string& id, double rate)
	:rate(rate),Account(date,id),acc(date,0){}
void SavingsAccount::deposit(const Date& date, double am, const string& c)
{
	record(date, am, c);
	acc.change(date, getBalance());
}
void SavingsAccount::withdraw(const Date& date, double am, const string& c)
{
	if (am <= getBalance())
	{
		record(date, -am, c);
		acc.change(date, getBalance());
	}
}
void SavingsAccount:: settle(const Date& date)
{
	if (date.getMonth() == 1)
	{
		double interest = acc.getSum(date) * rate / date.distance(Date(date.getYear() - 1, 1, 1));
		if (interest != 0)
			record(date, interest, "interest");
		acc.reset(date, getBalance());
	}
}
CreditAccount::CreditAccount(const Date& date, const string& id, double credit, double rate, double fee)
	:credit(credit), rate(rate), fee(fee), Account(date, id), acc(date, 0) {}
void CreditAccount::deposit(const Date& date, double am, const string& c)
{
	record(date, am, c);
	acc.change(date, getDebt());
}
void CreditAccount::withdraw(const Date& date, double am, const string& c)
{
	if (am -getBalance()<=credit)
	{
		record(date, -am, c);
		acc.change(date, getDebt());
	}
}
void CreditAccount::settle(const Date& date)
{
	double interest = acc.getSum(date) * rate ;
	if (interest != 0)
		record(date, interest, "interest");
	if (date.getMonth() == 1)
		record(date, -fee, "annual fee");
	acc.reset(date, getDebt());
}
void CreditAccount::show()const
{
	Account::show();
	cout << "\tAvailable credit:" << getAvailableCredit();
}
