#include<iostream>
#include<string>
#include<cmath>
#include "account.h"
using namespace std;
double SavingsAccount::total = 0;
double SavingsAccount::accumulate(const Date& date)
{
    return accumulation + balance * date.distance(lastDate);
}
SavingsAccount::SavingsAccount(const Date& date, const std::string& id, double rate)
    : id(id), balance(0), rate(rate), lastDate(date), accumulation(0)
{
    cout << lastDate.getYear() << "-" << lastDate.getMonth() << "-" << lastDate.getDay() << "\t";
    cout << "#" << this->id << " created" << endl;
}


void  SavingsAccount::deposit(const Date& date, double amount, const std::string& c)
{
    record(date, amount, c);
}
void  SavingsAccount::withdraw(const Date& date, double amount, const std::string& c)
{
    if (amount > getBalance())
    {
        cout << "Error: not enough money" << endl;
    }
    else
    {
        record(date, -amount, c);
    }
}
void  SavingsAccount::settle(const Date& date) 
{
    double interest = accumulate(date) * rate / date.distance(Date(date.getYear() - 1, 1, 1));
    if (interest != 0)
    {
        record(date, interest, "interest");

    }
    accumulation = 0;
}
void  SavingsAccount::show() 
{
    cout << id << " \t" << "Balance: " << balance;
}
double SavingsAccount::getTotal()
{
    return total;
}
void SavingsAccount::record(const Date& date, double amount, const std::string& desc)
{
    accumulation = accumulate(date);      
    lastDate = date;                      
    amount = floor(amount * 100 + 0.5) / 100;
    balance += amount;                    
    total += amount;
    date.show();
    cout << "\t#" << id << "\t" << amount << "\t" << balance << "\t" << desc << endl;
}