#include<iostream>
#include<string>
#include<math.h>
#include "account.h"
#include"Accumulator.h"
#include"AccountException.h"
#include<iomanip>
#include<vector>
#include<map>

using namespace std;
double Account::total = 0;
RecordMap Account::recordMap;
void Account::query(const Date& date_1, const Date& date_2)
{
	if (date_1 < date_2)
	{
		RecordMap::iterator iter1 = recordMap.lower_bound(date_1);
		RecordMap::iterator iter2 = recordMap.upper_bound(date_2);
		for (RecordMap::iterator iter = iter1; iter != iter2; ++iter)
			iter->second.show();
	}
}
Account::Account(const Date& date, const string& id) : balance(0), Id(id)
{
	date.show();
	cout << "\t#" << id << " created" << endl;
}
void Account::record(const Date& date, double am, const string& c)
{
	am = floor(am * 100 + 0.5) / 100;
	balance += am;
	total += am;
	date.show();
	cout << "\t#" << Id << "\t" << am << "\t" << balance << "\t" << c << endl;
	AccountRecord record(date, this, am, balance, c);
	recordMap.insert(make_pair(date, record));
}
void Account::show()const
{
	cout << Id << "\tBalance: " << balance;
}
SavingsAccount::SavingsAccount(const Date& date, const string& id, double rate)
	: Account(date, id), acc(date, 0), rate(rate){}
void SavingsAccount::deposit(const Date& date, double am, const string& c)
{
	record(date, am, c);
	acc.change(date, getBalance());
}
void SavingsAccount::withdraw(const Date& date, double am, const string& c) {
    if (am <= getBalance()) {
        record(date, -am, c);
        acc.change(date, getBalance());
    } else {
        throw AccountException("Insufficient funds in account.", this);
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
	: Account(date, id), credit(credit), rate(rate), acc(date, 0), fee(fee) {}
void CreditAccount::deposit(const Date& date, double am, const string& c)
{
	record(date, am, c);
	acc.change(date, getDebt());
}
void CreditAccount::withdraw(const Date& date, double am, const string& c) {
    if (am - getBalance() <= credit) {
        record(date, -am, c);
        acc.change(date, getDebt());
    } else {
        throw AccountException("Credit limit exceeded.", this);
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
AccountRecord::AccountRecord(const Date& date,Account* account,double amount,double balance,const string& c)
	:date(date),account(account),amount(amount),balance(balance),c(c){}