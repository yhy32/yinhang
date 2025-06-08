#include "account.h"
#include <iostream>
#include <cmath>
using namespace std;

SavingsAccount::SavingsAccount(int date, int ID, double Rate)
    : id(ID), balance(0), rate(Rate), lastDate(date), accumulation(0)
{
    cout << date << "\t#" << id << " is created" << endl;
}

void SavingsAccount::record(int date, double amount)
{
    accumulation = accumulate(date);
    lastDate = date;
    amount = floor(amount * 100.0 + 0.5) / 100;
    balance += amount;
    cout << date << "\t#" << id << "\t" << amount << "\t" << balance << endl;
}

void SavingsAccount::deposit(int date, double amount)
{
    record(date, amount);
}

void SavingsAccount::withdraw(int date, double amount)
{
    if (getBalance() < amount)
    {
        cout << "Error: not enough money" << endl;
        return;
    }
    record(date, -amount);
}

void SavingsAccount::settle(int date)
{
    double interest = accumulate(date) * rate / 365;
    if (interest != 0)
    {
        record(date, interest);
    }
    accumulation = 0;
}

void SavingsAccount::show() const
{
    cout << "#" << id << "\tBalance: " << balance;
}